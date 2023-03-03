//Using in-built data structure
class MyCircularQueue {
public:
    deque<int>dq;
    int maxSize;
    MyCircularQueue(int k) {
        maxSize = k;
    }

    bool enQueue(int value) { //O(1)
        if (isFull())    return false;
        dq.push_back(value);
        return true;
    }

    bool deQueue() { //O(1)
        if (isEmpty())   return false;
        dq.pop_front();
        return true;
    }

    int Front() { //O(1)
        if (isEmpty())   return -1;
        return dq.front();
    }

    int Rear() { //O(1)
        if (isEmpty())   return -1;
        return dq.back();
    }

    bool isEmpty() { //O(1)
        return dq.empty();
    }

    bool isFull() { //O(1)
        return dq.size() == maxSize;
    }
};

//Using vector
class MyCircularQueue {
public:
    vector<int>dq;
    int maxSize, head = 0, tail = -1;
    MyCircularQueue(int k) {
        maxSize = k;
    }

    bool enQueue(int value) {
        if (isFull())    return false;
        tail++;
        dq.push_back(value);
        return true;
    }

    bool deQueue() {
        if (isEmpty())    return false;
        head++;
        return true;
    }

    int Front() {
        if (isEmpty())   return -1;
        return dq[head];
    }

    int Rear() {
        if (isEmpty())   return -1;
        return dq[tail];
    }

    bool isEmpty() {
        return tail < head;
    }

    bool isFull() {
        return (tail - head + 1) == maxSize;
    }
};

//Using vector - Space optimised
class MyCircularQueue {
public:
    vector<int>dq;
    int maxSize, head = 0, tail = -1;
    MyCircularQueue(int k) {
        maxSize = k;
        dq.resize(k);
    }

    bool enQueue(int value) {
        if (isFull())    return false;
        tail = (tail + 1) % maxSize;
        dq[tail] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty())    return false;
        if (head == tail) head = 0, tail = -1;
        else head = (head + 1) % maxSize;
        return true;
    }

    int Front() {
        if (isEmpty())   return -1;
        return dq[head];
    }

    int Rear() {
        if (isEmpty())   return -1;
        return dq[tail];
    }

    bool isEmpty() {
        return tail == -1;
    }

    bool isFull() {
        return !isEmpty() && (tail + 1) % maxSize == head;
    }
};