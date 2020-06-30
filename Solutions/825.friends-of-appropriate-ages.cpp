/*
 * @lc app=leetcode id=825 lang=cpp
 *
 * [825] Friends Of Appropriate Ages
 */

// @lc code=start
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans(0);
        map<int, int> m;
        for (int age : ages) {
            ++m[age];
        }
        //cout << m.size() << endl;
        int lim(0);
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            //cout << '|' << it->first << ' ' << it->second << endl;
            lim = it->first / 2 + 7;
            if (it->first > lim) ans += it->second * (it->second - 1);
            auto iter = it;
            ++iter;
            for (; iter != m.rend(); ++iter) {
                //cout << iter->first << ' ' << iter->second << endl;
                if (iter->first > lim) ans += it->second * iter->second;
            }
        }
        return ans;
    }
};
// @lc code=end

