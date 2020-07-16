/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt(0);
        int i(0);
        unordered_set<int> rmPos;
        stack<pair<char, int>> stk;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push({'(', i});
            } else if (s[i] == ')') {
                if (!stk.empty() && stk.top().first == '(') {
                    stk.pop();
                } else {
                    stk.push({')', i});
                }
            }
        }
        
        while (!stk.empty()) {
            rmPos.insert(stk.top().second);
            stk.pop();
        }

        string ans;
        for (i = 0; i < s.size(); ++i) {
            if (rmPos.count(i) > 0) { continue; }
            ans += s[i];
        }
        return ans;
    }
};
// @lc code=end

