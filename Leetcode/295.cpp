class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int>leftHeap;
    priority_queue<int, vector<int>, greater<int>>rightHeap;

    void addNum(int num) {

        if (leftHeap.size() == 0 and rightHeap.size() == 0)
        {
            leftHeap.push(num);
        }

        else if (leftHeap.size() == rightHeap.size())
        {
            if ((num * 1.0) < findMedian())
            {
                leftHeap.push(num);
            }

            else rightHeap.push(num);
        }

        else if (leftHeap.size() > rightHeap.size())
        {
            if ((num * 1.0) < findMedian())
            {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(num);
            }

            else    rightHeap.push(num);
        }

        else
        {
            if ((num * 1.0) > findMedian())
            {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(num);
            }

            else    leftHeap.push(num);
        }

    }

    double findMedian() {
        if (leftHeap.size() == rightHeap.size())
        {
            return (leftHeap.top() + rightHeap.top()) / 2.0;
        }

        else if (leftHeap.size() > rightHeap.size()) return leftHeap.top() * 1.0;

        else return rightHeap.top() * 1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */