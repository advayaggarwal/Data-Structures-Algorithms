class MyCalendar {
public:
    map<int, int>m;
    MyCalendar() {
    }

    bool book(int start, int end) //O(n)
    {
        m[start]++;
        m[end]--;

        int sum = 0;
        for (auto p : m)
        {
            sum += p.second;
            if (sum > 1)
            {
                m[start]--;
                m[end]++;
                return false;
            }
        }

        return true;
    }
};

class MyCalendar {
public:
    vector<pair<int, int>>bookings;
    MyCalendar() {
    }

    bool book(int start, int end) //O(n)
    {
        for (auto p : bookings)
        {
            if (end > p.first && start < p.second) return false; //double booking
        }

        bookings.push_back({start, end});
        return true;
    }
};

class MyCalendar {
public:
    set<pair<int, int>>s;
    MyCalendar() {
    }

    bool book(int start, int end) //O(logn)
    {
        auto it = s.lower_bound({start, end});
        if (it != s.end() && it->first < end)    return false;
        if (it != s.begin() && start < (--it)->second)   return false;
        s.insert({start, end});
        return true;
    }
};