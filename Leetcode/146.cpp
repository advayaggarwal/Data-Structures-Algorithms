class Node {
public:
    int key;
    int value;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
public:
    int capacity;
    list<Node>l;
    unordered_map<int, list<Node>::iterator>m;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) //O(1)
    {
        if (m.count(key))
        {
            auto it = m[key];
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
            return l.begin()->value;
        }

        return -1;
    }

    void put(int key, int value) //O(1)
    {
        if (m.count(key)) //key exists, so delete it first
        {
            auto it = m[key];
            l.erase(it);
        }

        else
        {
            if (l.size() == capacity) //already full, delete least recently used
            {
                m.erase(l.back().key);
                l.pop_back();
            }
        }

        Node n(key, value);
        l.push_front(n);
        m[key] = l.begin();
    }
};

//Without using Node class, by making list of pair<int,int>
class LRUCache {
public:
    int capacity;
    list<pair<int, int>>l; //{key, value}
    unordered_map<int, list<pair<int, int>>::iterator>m;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) //O(1)
    {
        if (m.count(key))
        {
            auto it = m[key];
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
            return l.begin()->second;
        }

        return -1;
    }

    void put(int key, int value) //O(1)
    {
        if (m.count(key)) //key exists, so delete it first
        {
            auto it = m[key];
            l.erase(it);
        }

        else
        {
            if (l.size() == capacity) //already full, delete least recently used
            {
                m.erase(l.back().first);
                l.pop_back();
            }
        }

        l.push_front({key, value});
        m[key] = l.begin();
    }
};