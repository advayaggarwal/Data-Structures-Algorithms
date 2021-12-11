//Simply using vector
class MyHashMap {
public:
    vector<int>v;
    MyHashMap() {
        v = vector<int>(1000001, -1);
    }

    void put(int key, int value) {
        v[key] = value;
    }

    int get(int key) {
        return v[key];
    }

    void remove(int key) {
        v[key] = -1;
    }
};

//Using vector of linked list - Chaining
class MyHashMap {
public:
    vector<list<pair<int, int>>>m;
    int sz;
    MyHashMap()
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
            if (it->first == key)    return it;
        }

        return m[i].end();
    }

    void put(int key, int value)
    {
        int i = hash(key);
        remove(key); //to update if it already exists
        m[i].push_back({key, value});
    }

    int get(int key)
    {
        int i = hash(key);
        auto it = search(key);
        if (it != m[i].end())    return it->second;
        return -1;
    }

    void remove(int key)
    {
        int i = hash(key);
        auto it = search(key);
        if (it != m[i].end())    m[i].erase(it);

    }
};