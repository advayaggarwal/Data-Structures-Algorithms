//Using 2 queues
//Time complexity - Push - O(1), Pop - O(n), top - O(1), empty - O(1)
class MyStack {
public:
    queue<int>q1, q2;
    int topp;
    MyStack() {
    }

    void push(int x)
    {
        q1.push(x);
        topp = x;
    }

    int pop()
    {
        while (q1.size() > 1)
        {
            topp = q1.front();
            q2.push(topp);
            q1.pop();
        }

        int ans = q1.front();
        q1.pop();
        swap(q1, q2);
        return ans;
    }

    int top()
    {
        return topp;
    }

    bool empty() {
        return q1.empty();
    }
};

//Using 1 queue
//Time complexity - push - O(n), pop - O(1), top - O(1), empty - O(1)
class MyStack {
public:
    queue<int>q;
    MyStack() {
    }

    void push(int x)
    {
        q.push(x);
        int sz = q.size();
        while (sz > 1)
        {
            q.push(q.front());
            q.pop();
            sz--;
        }
    }

    int pop()
    {
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top()
    {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};