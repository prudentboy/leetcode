/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 */

// @lc code=start
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        const int n(wage.size());
        vector<pair<double, int>> workers(n);
        for (int i(0); i < n; ++i) { workers[i] = {(double)wage[i] / quality[i], quality[i]}; }
        sort(workers.begin(), workers.end());

        priority_queue<int> pq;
        int qSum(0);
        double ans(1e9);
        for (auto& worker : workers) {
            pq.push(worker.second);
            qSum += worker.second;
            if (pq.size() > K) {
                qSum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) { ans = min(ans, worker.first * qSum); }
        }
        return ans;
    }
};
// @lc code=end

