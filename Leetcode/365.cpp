//Bézout's identity
//Time complexity - O(log(jugCapacity))
//Space complexity - O(1)
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
    {
        //we don't have enough capacity
        if (jug1Capacity + jug2Capacity < targetCapacity)    return false;

        //case jug1Capacity or jug2Capacity is zero
        if (jug1Capacity == targetCapacity or jug2Capacity == targetCapacity or jug1Capacity + jug2Capacity == targetCapacity)   return true;

        //get GCD, then we can use the property of Bézout's identity
        return targetCapacity % __gcd(jug1Capacity, jug2Capacity) == 0;
    }
};

/*
The idea is to traverse over the possible capacity states of the two jugs (Jug1, Jug2).
Any jug can be full, semi - full or empty (in any state)
At any state (a, b) of the jugs we can do 6 things.
    Pour contents of jug1 to jug2. (note that jug1 may still have some water left after pouring water to jug2)
    Pour contents of jug2 to jug1. (note that jug2 may still have some water left after pouring water to jug1)
    Empty jug1 completely.
    Empty jug2 completely.
    Fill jug1 completely (to its maximum limit)
    Fill jug2 completely (to its maximum limit)

We are going to keep a note of the already visited states (a, b) of the jugs in a HashSet of string
with key being: "a,b" (the capacities of the jugs separated by a comma.
This helps us to avoid redundant calculations).

We are going to start with a queue containing only the state (0, 0) (both jugs empty) initially.
Apply the above 6 operations on that and add those states to the queue if they weren't already visited.
Then simply keep checking whether in any of the states we get the summation of the capacities == z.

If we don't find any such state. return false.
*/

//BFS
class Solution {
public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y < z) return false;

        unordered_set<string>visited; //can't use 2d vector due to space constraints
        queue<pair<int, int>>q;
        q.push({0, 0});
        string key = to_string(0) + "#" + to_string(0);
        visited.insert(key);

        while (!q.empty())
        {
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();

            if (curr_x + curr_y == z)    return true;

            int newX, newY;

            //option 1, pour x to y
            newX = curr_x - min(curr_x, y - curr_y);
            newY = curr_y + min(curr_x, y - curr_y);
            if (!visited.count(to_string(newX) + "#" + to_string(newY)))
            {
                visited.insert(to_string(newX) + "#" + to_string(newY));
                q.push({newX, newY});
            }

            //option 2, pour y to x
            newX = curr_x + min(curr_y, x - curr_x);
            newY = curr_y - min(curr_y, x - curr_x);
            if (!visited.count(to_string(newX) + "#" + to_string(newY)))
            {
                visited.insert(to_string(newX) + "#" + to_string(newY));
                q.push({newX, newY});
            }

            //option 3, empty x
            newX = 0;
            newY = curr_y;
            if (!visited.count(to_string(newX) + "#" + to_string(newY)))
            {
                visited.insert(to_string(newX) + "#" + to_string(newY));
                q.push({newX, newY});
            }

            //option 4, empty y
            newX = curr_x;
            newY = 0;
            if (!visited.count(to_string(newX) + "#" + to_string(newY)))
            {
                visited.insert(to_string(newX) + "#" + to_string(newY));
                q.push({newX, newY});
            }

            //option 5, fill x
            newX = x;
            newY = curr_y;
            if (!visited.count(to_string(newX) + "#" + to_string(newY)))
            {
                visited.insert(to_string(newX) + "#" + to_string(newY));
                q.push({newX, newY});
            }

            //option 6, fill y
            newX = curr_x;
            newY = y;
            if (!visited.count(to_string(newX) + "#" + to_string(newY)))
            {
                visited.insert(to_string(newX) + "#" + to_string(newY));
                q.push({newX, newY});
            }
        }

        return false;
    }
};