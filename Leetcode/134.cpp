//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();
        for (int i = 0; i < n; i++)
        {
            if (gas[i] >= cost[i])
            {
                int curr_gas = gas[i] - cost[i];
                int j = (i + 1) % n;
                for (; j != i; j = (j + 1) % n)
                {
                    curr_gas += gas[j] - cost[j];
                    if (curr_gas < 0)    break;
                }

                if (j == i)    return i;
            }
        }

        return -1;
    }
};


/*
If we look at the problem, our point of concern should be the total amount of gas should be
greater than the total cost. The only factor we need to consider is setting the starting point.

* Time complexity - O(n)
* Space complexity - O(1)

*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();
        int total = 0, surplus = 0, start = 0;

        for (int i = 0; i < n; i++)
        {
            total += gas[i] - cost[i];
            surplus += gas[i] - cost[i];

            if (surplus < 0)
            {
                surplus = 0;
                start = i + 1;
            }
        }

        return total < 0 ? -1 : start;
    }
};