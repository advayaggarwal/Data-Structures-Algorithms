//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    vector<string> letterCasePermutation(string s) {

        vector<string>permutations;
        int n = s.size();

        generatePermutations(0, n, s, permutations);

        return permutations;
    }

    void generatePermutations(int index, int n, string &s, vector<string>&permutations)
    {
        if (index == n)
        {
            permutations.push_back(s);
            return;
        }

        if (s[index] >= '0' && s[index] <= '9')  generatePermutations(index + 1, n, s, permutations);

        else
        {
            s[index] = toupper(s[index]);

            generatePermutations(index + 1, n, s, permutations);

            s[index] = tolower(s[index]);

            generatePermutations(index + 1, n, s, permutations);
        }
    }
};