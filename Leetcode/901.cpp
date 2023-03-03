class StockSpanner {
private:
    stack<pair<int, int>> s;
public:
    StockSpanner() {

    }

    int next(int price)
    {
        int res = 1;
        while (!s.empty() && s.top().first <= price) {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};

//Nearest Greater to the left
class StockSpanner {
public:
    stack<pair<int, int>>s;
    int index = -1;
    StockSpanner() {
    }

    int next(int price)
    {
        index++;
        int res;
        while (!s.empty() && s.top().first <= price) s.pop();

        if (s.empty())   res = index + 1;
        else res = index - s.top().second;

        s.push({price, index});
        return res;
    }
};