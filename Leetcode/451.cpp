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


//Bucket sort technique
//Time complexity - O(n), where n is size of string s
//Space complexity - O(n)
class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int>freq;

        for (char ch : s)  freq[ch]++;

        vector<string> bucket(s.size() + 1, ""); //max chars will be s.size() if all are different
        string res;

        for (auto e : freq)
        {
            int n = e.second;
            char c = e.first;

            bucket[n] += string(n, c); //char c occurs n times
            //string(n,c) appends char c, n times
        }

        for (int i = s.size(); i >= 0; i--)
        {
            res +=  bucket[i];
        }

        return res;
    }
};