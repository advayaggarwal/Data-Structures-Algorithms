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

    int get(int key) {
        if (m.count(key) != 0)
        {
            auto it = m[key];

            l.push_front(*it);

            m[key] = l.begin();

            l.erase(it);

            return l.begin()->value;
        }

        return -1;
    }

    void put(int key, int value) {

        if (m.count(key) != 0)
        {
            auto it = m[key];
            it->value = value;
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();

        }
        else
        {
            if (l.size() == capacity)
            {
                m.erase(l.back().key);
                l.pop_back();
            }

            Node n(key, value);

            l.push_front(n);
            m[key] = l.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */