//Time complexity - O(n)
//Space complexity - O(n)
/*
    Intuition
Let left[i] be the distance from seat i to the closest person sitting to the left of i.
Similarly, let right[i] be the distance to the closest person sitting to the right of i.
This is motivated by the idea that the closest person in seat i sits a distance min(left[i],right[i]) away
*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats)
    {
        int n = seats.size();

        vector<int>left(n, n), right(n, n);

        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 1)   left[i] = 0;
            else if (i > 0)    left[i] = left[i - 1] + 1;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (seats[i] == 1)   right[i] = 0;
            else if (i < n - 1)    right[i] = right[i + 1] + 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 0)   ans = max(ans, min(left[i], right[i]));
        }

        return ans;
    }
};


//Using two pointers - same as above without using extra space
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats)
    {
        int n = seats.size();
        int prev = -1, future = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 1)   prev = i;
            else
            {
                while (future < n && seats[future] == 0 || future < i)   future++;

                int left = prev == -1 ? n : i - prev;
                int right = future == n ? n : future - i;

                ans = max(ans, min(left, right));
            }
        }

        return ans;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)

/*
For each group of K empty seats between two people, we can take into account the candidate answer (K+1)/2.

For groups of empty seats between the edge of the row and one other person, the answer is K,
and we should take into account those answers too.

*/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats)
    {
        int n = seats.size();
        int k = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 1)   k = 0;
            else
            {
                k++;
                ans = max(ans, (k + 1) / 2);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 1)
            {
                ans = max(ans, i);
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (seats[i] == 1)
            {
                ans = max(ans, n - 1 - i);
                break;
            }
        }

        return ans;
    }
};