/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> cnt(N), ans(N);

        vector<vector<int>> graph(N);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        function<void(int, int)> postOrder = [&](int cur, int par) {
            for (int child : graph[cur]) {
                if (child == par) { continue; }
                postOrder(child, cur);
                cnt[cur] += cnt[child];
                ans[cur] += ans[child] + cnt[child];
            }
            ++cnt[cur];
        };

        function<void(int, int)> preOrder = [&](int cur, int par) {
            for (int child : graph[cur]) {
                if (child == par) { continue; }
                ans[child] = ans[cur] + N - (cnt[child] << 1);
                preOrder(child, cur);
            }
        };

        postOrder(0, -1);
        /*
        cout << "count: " << endl;
        for (int i(0); i < N; ++i) { cout << cnt[i] << ' '; }
        cout << endl << "ans: " << endl;
        for (int i(0); i < N; ++i) { cout << ans[i] << ' '; }
        cout << endl;
        */
        preOrder(0, -1);
        /*
        cout << "count: " << endl;
        for (int i(0); i < N; ++i) { cout << cnt[i] << ' '; }
        cout << endl << "ans: " << endl;
        for (int i(0); i < N; ++i) { cout << ans[i] << ' '; }
        cout << endl;
        */
        return ans;
    }
};
// @lc code=end

