//Brute force solution
//Time complexity - O(n)
//Space complexity - O(2*n)
class MyQueue {
public:
    stack<int>s1, s2;

    MyQueue() {
    }

    void push(int x) { //O(n)

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() { //O(1)
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek() { //O(1)
        return s1.top();
    }

    bool empty() { //O(1)
        return s1.empty();
    }
};

//Efficient solution
//Time complexity - Amortized O(1)
//Space complexity - O(2*n)
class MyQueue {
public:

    stack<int> input, output;

    MyQueue() {
    }

    void push(int x) { //O(1)
        input.push(x);
    }

    int pop() { //Amortized O(1)
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        int ans = output.top();
        output.pop();
        return ans;

    }

    int peek() { //Amortized O(1)
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty() { //O(1)
        return input.empty() && output.empty();
    }
};