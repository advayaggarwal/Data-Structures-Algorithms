class MyCalendarTwo {
public:
    map<int, int>m;
    MyCalendarTwo() {
    }

    bool book(int start, int end) //O(n)
    {
        m[start]++;
        m[end]--;
        int sum = 0;
        for (auto p : m)
        {
            sum += p.second;
            if (sum > 2)
            {
                m[start]--;
                m[end]++;
                return false;
            }
        }

        return true;
    }
};

class MyCalendarTwo {
public:
    vector<pair<int, int>>booking, doubleBooking;
    MyCalendarTwo() {
    }

    bool isOverlap(int s1, int e1, int s2, int e2)
    {
        return max(s1, s2) < min(e1, e2);
    }

    bool book(int start, int end) //O(n)
    {
        for (auto p : doubleBooking)
        {
            if (isOverlap(p.first, p.second, start, end)) return false;
        }

        for (auto p : booking)
        {
            if (isOverlap(p.first, p.second, start, end))
                doubleBooking.push_back({max(start, p.first), min(end, p.second)});
        }

        booking.push_back({start, end});
        return true;
    }
};