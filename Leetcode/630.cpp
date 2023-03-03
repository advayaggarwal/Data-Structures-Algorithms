/*
Idea-
During iteration, say I want to add the current course, currentTotalTime being total time of all courses
taken till now, but adding the current course might exceed my deadline or it doesn’t.

1. If it doesn’t, then I have added one new course. Increment the currentTotalTime with duration of current course.

2. If it exceeds deadline, I can swap current course with current courses that has biggest duration.
* No harm done and I might have just reduced the currentTotalTime, right?
* What preprocessing do I need to do on my course processing order so that this swap is always legal?
*/

//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses)
    {
        sort(courses.begin(), courses.end(), [&](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<int>pq;
        int timeElapsed = 0;

        for (auto v : courses)
        {
            if (v[0] + timeElapsed <= v[1])
            {
                pq.push(v[0]);
                timeElapsed += v[0];
            }

            else if (!pq.empty() && pq.top() > v[0])
            {
                timeElapsed -= pq.top();
                pq.pop();
                pq.push(v[0]);
                timeElapsed += v[0];
            }
        }

        return pq.size();
    }
};