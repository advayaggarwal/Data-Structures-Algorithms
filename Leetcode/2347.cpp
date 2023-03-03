//Time complexity - O(1)
//Space complexity - O(1)
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits)
    {
        vector<int>count(14);
        for (int i = 0; i < 5; i++)  count[ranks[i]]++;
        vector<int>ch(4);
        for (int i = 0; i < 5; i++)  ch[suits[i] - 'a']++;


        for (int i = 0; i < 4; i++)  if (ch[i] == 5)  return "Flush";

        for (int i = 1; i < 14; i++)
        {
            if (count[i] >= 3)   return "Three of a Kind";
        }

        for (int i = 1; i < 14; i++)
        {
            if (count[i] >= 2)   return "Pair";
        }

        return "High Card";
    }
};