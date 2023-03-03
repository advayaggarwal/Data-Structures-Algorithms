class MyCalendarThree {
public:
    map<int, int>m;
    MyCalendarThree() {
    }

    int book(int start, int end) //O(n)
    {
        m[start]++;
        m[end]--;
        int sum = 0, maxi = 0;
        for (auto p : m)
        {
            sum += p.second;
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};
