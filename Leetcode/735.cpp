//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        int n = asteroids.size();
        stack<int>s;
        for (int i = 0; i < n; i++)
        {
            if (asteroids[i] > 0)    s.push(asteroids[i]);
            else
            {
                while (!s.empty() && s.top() > 0 && s.top() < -asteroids[i]) s.pop();

                if (!s.empty() && s.top() == -asteroids[i])  s.pop();
                else if (!s.empty() && s.top() > -asteroids[i])  continue;
                else s.push(asteroids[i]);
            }
        }

        vector<int>result;
        while (!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

//Shorter code
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s; // use vector to simulate stack.
        for (int i : a) {
            while (!s.empty() && s.back() > 0 && s.back() < -i)
                s.pop_back();
            if (s.empty() || i > 0 || s.back() < 0)
                s.push_back(i);
            else if (i < 0 && s.back() == -i)
                s.pop_back();
        }
        return s;
    }
};