/*
 * @lc app=leetcode id=636 lang=cpp
 *
 * [636] Exclusive Time of Functions
 */

// @lc code=start
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        int pre(0);
        int idx(0), t(0);
        char cmd[10];
        stack<int> st;
        for (const string& log : logs)
        {
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, cmd, &t);
            //cout << idx << ' ' << cmd[0] << ' ' << t << endl;
            if (cmd[0] == 's')
            {
                if (!st.empty()) ans[st.top()] += t - pre;
                st.push(idx);
            }
            else
            {
                ans[st.top()] += ++t - pre;
                st.pop();
            }
            pre = t;
        }
        return ans;
    }
};
// @lc code=end

