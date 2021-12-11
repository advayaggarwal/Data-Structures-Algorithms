//Using 2 stacks
class MinStack {
public:
    stack<int>s1, s2;
    MinStack() {
    }

    void push(int val)
    {
        s1.push(val);
        if (s2.empty() or s2.top() >= val) s2.push(val);
    }

    void pop()
    {
        if (s1.top() == s2.top())    s2.pop();
        s1.pop();
    }

    int top()
    {
        return s1.top();
    }

    int getMin()
    {
        return s2.top();
    }
};

//Using 1 stack of pair<int,int>
class MinStack {
public:
    stack<pair<int, int>>s;
    MinStack() {
    }

    void push(int val)
    {
        if (s.empty())   s.push({val, val});
        else
        {
            s.push({val, min(val, s.top().second)});
        }
    }

    void pop()
    {
        s.pop();
    }

    int top()
    {
        return s.top().first;
    }

    int getMin()
    {
        return s.top().second;
    }
};

//Using only 1 stack - Tricky
class MinStack {
public:
    stack<long long int>s;
    long long int minEle;

    MinStack()
    {
        minEle = INT_MAX;
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push(1LL * val);
            minEle = 1LL * val;
        }

        else if (val > minEle)  s.push(val);

        else
        {
            s.push(2 * 1LL * val - minEle);
            minEle = val;
        }
    }

    void pop()
    {
        if (s.top() > minEle)  s.pop();
        else
        {
            minEle = 2 * 1LL * minEle - s.top();
            s.pop();
        }
    }

    int top()
    {
        if (s.top() > minEle)    return s.top();
        else return minEle;
    }

    int getMin()
    {
        return minEle;
    }
};