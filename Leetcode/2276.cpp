//Using Map
//Time complexity - O(logn)
//Space complexity - O(n)
class CountIntervals {
public:
    map<int, int>m;
    int cnt;
    CountIntervals() {
        cnt =  0;
    }

    void add(int left, int right)
    {
        auto it = m.upper_bound(left);

        if (it != m.begin())
        {
            auto p = it;
            p--;
            if (p->second >= left)
            {
                left = p->first;
                right = max(right, p->second);

                cnt -= p->second - p->first + 1;
                m.erase(p);
            }
        }

        for (; it != m.end() && it->first <= right; m.erase(it++))
        {
            right = max(right, it->second);
            cnt -= it->second - it->first + 1;
        }

        cnt += right - left + 1;
        m[left] = right;
    }

    int count()
    {
        return cnt;
    }
};

//Using Set
//Time complexity - O(logn)
//Space complexity - O(n)
class CountIntervals {
public:
    set<pair<int, int>>s;
    int cnt;
    CountIntervals() {
        cnt =  0;
    }

    void add(int left, int right)
    {
        auto it = s.upper_bound({left, INT_MIN});

        if (it != s.begin() && (--it)->second < left)    it++; //to check if prev interval is overlapping or not

        while (it != s.end() && it->first <= right) //while overlapping delete the interval and subtract the count
        {
            left = min(left, it->first);
            right = max(right, it->second);
            cnt -= it->second - it->first + 1;
            s.erase(it++);
        }

        s.insert({left, right});
        cnt += right - left + 1;
    }

    int count()
    {
        return cnt;
    }
};