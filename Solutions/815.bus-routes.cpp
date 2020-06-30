/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) { return 0; }

        unordered_map<int, vector<int>> ump;

        for (int i(0); i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                ump[stop].push_back(i);
            }
        }

        int ans(1);

        unordered_set<int> busTaken;
        queue<int> q;
        q.push(S);
        int len(0), tmp(0);
        while (!q.empty()) {
            len = q.size();
            while (len-- > 0) {
                tmp = q.front();
                //cout << tmp << endl;
                q.pop();
                for (int bus : ump[tmp]) {
                    if (busTaken.count(bus) > 0) { continue; }
                    for (int stop : routes[bus]) {
                        if (stop == T) { return ans; }
                        q.push(stop);
                    }
                    busTaken.insert(bus);
                }
            }
            ++ans;
        }

        return -1;
    }
};
// @lc code=end
