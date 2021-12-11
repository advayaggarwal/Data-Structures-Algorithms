//Time complexity - O(a+b+c)
//Space complexity - O(1)
class Solution {
public:
    int maximumScore(int a, int b, int c)
    {
        int ans = 0;
        priority_queue<int>q;
        q.push(a);
        q.push(b);
        q.push(c);
        while (q.size() > 1)
        {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            x--;
            y--;
            if (x)  q.push(x);

            if (y)  q.push(y);

            ans++;
        }
        return ans;
    }
};

/*

1.
If one number if bigger that the sum of the remaning two. The sum of the remaining two is the answer.
Reason: you have to take 1 from one of the two smaller numbers in each move, they eventually run out first.

2.
Otherwise, no more than 1 will be left at the end. You can first take 1 from the biggest one and 1 from
the smallest one in each move until two bigger ones are the same. From there on you perform two moves
together: 2 from the smallest one and 1 from each of the bigger ones until the smallest is 0 or 1.

*/

//Time complexity - O(1)
//Space complexity - O(1)
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int m = max(max(a, b), c);
        if (2 * m > a + b + c) return a + b + c - m;
        return (a + b + c) / 2;
    }
};