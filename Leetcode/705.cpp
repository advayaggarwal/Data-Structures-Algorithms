//Simply using vector
//Time complexity - O(1)
//Space complexity - O(n)
class MyHashSet {
public:
    bool a[1000001] = {false};
    MyHashSet() {

    }

    void add(int key) {
        a[key] = true;
    }

    void remove(int key) {
        a[key] = false;
    }

    bool contains(int key) {
        return a[key];
    }
};

//Using vector of linked list - Chaining, actual hash set concept
//Time complexity - O(n), average O(1)
//Space complexity - O(n)
class MyHashSet {
public:
    int sz;
    vector<list<int>>m;
    MyHashSet()
    {
        sz = 1001;
        m.resize(sz);
    }

    int hash(int key)
    {
        return key % sz;
    }

    auto search(int key)
    {
        int i = hash(key);

        for (auto it = m[i].begin(); it != m[i].end(); it++)
        {
            if (*it == key)  return it;
        }
        return m[i].end();
    }

    void add(int key)
    {
        int i = hash(key);
        if (contains(key))   return;
        m[i].push_back(key);
    }

    void remove(int key)
    {
        int i = hash(key);
        auto it = search(key);
        if (it == m[i].end())    return;
        m[i].erase(it);
    }

    bool contains(int key)
    {
        int i = hash(key);
        auto it = search(key);
        if (it == m[i].end())    return false;
        return true;
    }
};