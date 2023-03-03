class NumberContainers {
public:
    unordered_map<int, int>m1;
    unordered_map<int, set<int>>m2;
    NumberContainers() {
    }

    void change(int index, int number) //O(logn)
    {
        if (m1.count(index))
        {
            int oldNumber = m1[index];
            m2[oldNumber].erase(index);
            if (m2[oldNumber].size() == 0)  m2.erase(oldNumber);
        }

        m1[index] = number;
        m2[number].insert(index);
    }

    int find(int number) //O(1)
    {
        if (m2.count(number))    return *(m2[number].begin());
        return -1;
    }
};