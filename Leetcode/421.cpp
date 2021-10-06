//Time complexity - O(n)
class Node {
public:
    Node *z;
    Node *o;
};

class Trie {
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(int value)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (value >> i) & 1;

            if (bit == 0)
            {
                if (temp->z == NULL)
                {
                    temp->z = new Node();
                }

                temp = temp->z;
            }

            else
            {
                if (temp->o == NULL)
                {
                    temp->o = new Node();
                }
                temp = temp->o;
            }
        }
    }

    int xor_helper(int value)
    {
        int ans = 0;

        Node *temp = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (value >> i) & 1;

            if (bit == 0)
            {
                //search for 1

                if (temp->o)
                {
                    ans += (1 << i);
                    temp = temp->o;
                }

                else temp = temp->z;
            }

            else
            {
                //search for 0

                if (temp->z)
                {
                    ans += (1 << i);
                    temp = temp->z;
                }

                else temp = temp->o;
            }
        }

        return ans;

    }

    int max_xor(vector<int>&nums, int n)
    {
        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            insert(nums[i]);

            int curr_ans = xor_helper(nums[i]);

            ans = max(ans, curr_ans);

        }

        return ans;
    }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;

        return t.max_xor(nums, nums.size());

    }
};