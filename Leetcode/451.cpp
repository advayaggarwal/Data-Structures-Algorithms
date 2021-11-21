//Time complexity - O(nlogn), where n is size of string s
//Space complexity - O(256)
class Solution {
public:
    string frequencySort(string s) {

        vector<int>freq(256, 0);

        for (char ch : s)  freq[ch]++;

        sort(s.begin(), s.end(), [&](char a, char b) { //& is to capture local variable freq to use in lambda function
            return freq[a] > freq[b] or (freq[a] == freq[b] and a < b);
        });

        return s;
    }
};

//Using Max Heap
//Time complexity - O(n + klogk), where k is #unique characters, n is the size of string s
class Solution {
public:
    string frequencySort(string s)
    {
        string res;

        vector<int>freq(256);

        for (char ch : s)    freq[ch]++; //O(n)

        priority_queue<pair<int, char>, vector<pair<int, char>>>maxHeap;

        for (int i = 0; i < 256; i++)
        {
            if (freq[i] > 0) maxHeap.push({freq[i], char(i)});
        }

        while (!maxHeap.empty())
        {
            res += string(maxHeap.top().first, maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }
};

//Bucket sort technique
//Time complexity - O(n), where n is size of string s
//Space complexity - O(n)
class Solution {
public:
    string frequencySort(string s)
    {
        string res;

        vector<int>freq(256);

        for (char ch : s)    freq[ch]++;

        vector<string>bucket(s.size() + 1);

        for (int i = 0; i < 256; i++)
        {
            char c = i;
            bucket[freq[i]] += string(freq[i], c);
        }

        for (int i = s.size(); i >= 0; i--)
        {
            res += bucket[i];
        }

        return res;
    }
};