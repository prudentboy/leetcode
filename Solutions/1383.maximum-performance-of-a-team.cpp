/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 */

// @lc code=start
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int M(1e9 + 7);

        vector<pair<int, int>> people;
        for (int i(0); i < n; ++i) { people.push_back({efficiency[i], speed[i]}); }
        sort(people.rbegin(), people.rend());

        long ans(0), sum(0);
        priority_queue<int> pq;
        for (int i(0); i < n; ++i) {
            sum += people[i].second;
            pq.push(-people[i].second);
            if (i >= k) {
                sum += pq.top();
                pq.pop();
            }
            ans = max(ans, sum * people[i].first);
        }

        return ans % M;
    }
};
// @lc code=end

