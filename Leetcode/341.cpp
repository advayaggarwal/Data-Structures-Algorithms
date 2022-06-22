/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
//#1 - Copying the data structure
//Space complexity - O(n)
class NestedIterator {
public:
    vector<int>output;
    int i;

    void helper(vector<NestedInteger> &nestedList)
    {
        int n = nestedList.size();
        for (int i = 0; i < n; i++)
        {
            if (nestedList[i].isInteger())   output.push_back(nestedList[i].getInteger());
            else
            {
                helper(nestedList[i].getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        i = 0;
        helper(nestedList);
    }

    int next() {
        return output[i++];
    }

    bool hasNext() {
        return i < output.size();
    }
};

/*
#2
//O(n) space, Flatten the list as you go.
#1 is not an iterator because an iterator should never copy the data structure.
Besides, it is a waste of time to flatten and store the whole list if we may only visit a few elements.
So we can store the first level in the stack and flatten it as we go.
If the list is flat, then there is no saving over #1.
*/
class NestedIterator {
public:
    stack<NestedInteger>st;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        int n = nestedList.size();
        for (int i = n - 1; i >= 0; i--)   st.push(nestedList[i]);
    }

    int next()
    {
        int ans = st.top().getInteger();
        st.pop();
        return ans;
    }

    bool hasNext()
    {
        while (!st.empty())
        {
            auto nI = st.top();
            if (nI.isInteger())  return true;
            else
            {
                vector<NestedInteger>v = nI.getList();
                st.pop();

                for (int i = v.size() - 1; i >= 0; i--)
                {
                    st.push(v[i]);
                }
            }
        }

        return false;
    }
};

/*
#3
Real iterator, O(h) space, h is the depth of the list. #2 stores each element in the current list.
This still can be large. A list iterator is sufficient to dfs the list.
This solution only stores 2 iterators of the current list.
*/

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (begins.size()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else {
                auto x = begins.top();
                if (x->isInteger())
                    return true;
                begins.top()++;
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }

private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};