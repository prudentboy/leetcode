/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n(graph.size());
        vector<bool> flags(n, false);
        queue<int> q;
        set<int> s;
        unordered_map<int, unordered_set<int>> forward, backward;
        for (int i(0); i < n; ++i) {
            if (graph[i].empty()) {
                flags[i] = true;
                s.insert(i);
                q.push(i);
            } else {
                for (int num : graph[i]) {
                    forward[i].insert(num);
                    backward[num].insert(i);
                }
            }
        }
        int tmp(0), len(0);
        while (!q.empty()) {
            //cout << "ans: ";
            //for (int i(0); i < ans.size(); ++i) cout << ans[i] << ' ';
            //cout << endl;
            len = q.size();
            while (len-- > 0) {
                tmp = q.front();
                //cout << len << ' ' << tmp << endl;
                q.pop();
                for (int pb : backward[tmp]) {
                    //cout << "pb: " << pb << endl;
                    for (auto it(forward[pb].begin()); it != forward[pb].end();) {
                        //cout << "pf: " << *it << endl;
                        if (flags[*it]) forward[pb].erase(it++);
                        else ++it;
                    }
                }
                q.push(tmp);
            }
            len = q.size();
            while (len-- > 0) {
                tmp = q.front();
                //cout << len << ' ' << tmp << endl;
                q.pop();
                for (int pb : backward[tmp]) {
                    if (forward[pb].empty()) {
                        q.push(pb);
                        s.insert(pb);
                        flags[pb] = true;
                    }
                }
            }
        }
        return vector<int>(s.begin(), s.end());
    }
};
// @lc code=end

