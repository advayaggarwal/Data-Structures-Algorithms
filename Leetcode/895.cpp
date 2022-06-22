//Time complexity - O(1)
//Space complexity - O(n)
class FreqStack {
public:
    unordered_map<int, int>freq; //{val, freq}
    unordered_map<int, stack<int>>group; //{freq, values}
    int maxFreq;
    FreqStack()
    {
        maxFreq = 0;
    }

    void push(int val)
    {
        freq[val]++;
        group[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }

    int pop()
    {
        int ans = group[maxFreq].top();
        group[maxFreq].pop();
        freq[ans]--;
        if (group[maxFreq].empty())  maxFreq--;
        return ans;
    }
};