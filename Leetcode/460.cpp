class LFUCache {
public:
    unordered_map<int, int>key_value;
    unordered_map<int, pair<int, list<int>::iterator>>key_freq; //{key, {freq, list iterator}};
    unordered_map<int, list<int>>freq_keys;
    int minFreq;
    int capacity;
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) //O(1)
    {
        if (key_value.count(key))
        {
            if (key_freq.count(key) && freq_keys.count(key_freq[key].first))
            {
                auto it = key_freq[key].second;
                if (it != freq_keys[key_freq[key].first].end())
                {
                    freq_keys[key_freq[key].first].erase(it);
                    if (freq_keys[key_freq[key].first].size() == 0)
                    {
                        freq_keys.erase(freq_keys.find(key_freq[key].first));
                        if (minFreq == key_freq[key].first)  minFreq++;
                    }
                }
            }

            key_freq[key].first++;
            freq_keys[key_freq[key].first].push_back(key);
            key_freq[key].second = --freq_keys[key_freq[key].first].end();
            return key_value[key];
        }

        return -1;
    }

    void put(int key, int value) //O(1)
    {
        if (capacity == 0)   return;
        if (key_value.count(key))
        {
            key_value[key] = value;
            get(key);
            return;
        }

        if (key_value.size() == capacity)
        {
            int least_freq_key = *freq_keys[minFreq].begin();
            key_freq.erase(least_freq_key);
            key_value.erase(least_freq_key);
            freq_keys[minFreq].pop_front();
            if (freq_keys[minFreq].size() == 0)   freq_keys.erase(minFreq);
        }

        minFreq = 1;
        key_value[key] = value;
        key_freq[key].first++;
        freq_keys[key_freq[key].first].push_back(key);
        key_freq[key].second = --freq_keys[key_freq[key].first].end();
    }
};