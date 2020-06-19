/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int t(0), ans(0);
        sort(courses.begin(), courses.end(), [](const vector<int>& l, const vector<int>& r) {
            return l[1] < r[1];
        });
        priority_queue<int> pq;
        for (auto& course : courses) {
            t += course[0];
            ++ans;
            pq.push(course[0]);
            if (t > course[1]) {
                --ans;
                t -= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};
// @lc code=end

