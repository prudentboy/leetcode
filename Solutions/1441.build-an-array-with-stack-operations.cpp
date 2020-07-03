/*
 * @lc app=leetcode id=1441 lang=cpp
 *
 * [1441] Build an Array With Stack Operations
 */

// @lc code=start
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        const vector<string> operation({"Push", "Pop"});
        vector<string> ans;
        stack<int> stk;
        int i(0), num(1);
        while (i < target.size()) {
            while ((i == 0 && !stk.empty()) || (i > 0 && target[i - 1] != stk.top())) {
                ans.push_back(operation[1]);
                stk.pop();
            }
            if (num == target[i]) { ++i; }
            ans.push_back(operation[0]);
            stk.push(num);
            if (++num > n) {break; }
        }
        return ans;
    }
};
// @lc code=end

