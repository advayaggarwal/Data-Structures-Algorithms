//Josephus problem

//Simulation of the problem statement Using Queue
//Time complexity - O(n*k)
//Space complexity - O(n)
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        while (q.size() != 1) {
            int x = k;
            while (x > 1) {
                int r = q.front();
                q.pop();
                q.push(r);
                x--;
            }
            q.pop();
        }
        return q.front();
    }
};

//Recursive
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int findTheWinner(int n, int k)
    {
        if (n == 1)    return 1;

        return (findTheWinner(n - 1, k) + k - 1) % n + 1;
        // +1 for 1 based indexing, k-1 for the correct index from previous index and %n as it's circular
    }
};

//Iterative
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int findTheWinner(int n, int k)
    {
        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            res = (res + k) % i;
        }

        return res + 1;
    }
};