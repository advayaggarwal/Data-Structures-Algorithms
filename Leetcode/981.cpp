class TimeMap {
public:
    unordered_map<string, map<int, string, greater<int>>>m;
    TimeMap() {
    }

    void set(string key, string value, int timestamp) //O(logn)
    {
        m[key][timestamp] = value;
    }

    string get(string key, int timestamp) //O(n)
    {
        for (auto p : m[key])
        {
            if (p.first <= timestamp)    return p.second;
        }

        return "";
    }
};