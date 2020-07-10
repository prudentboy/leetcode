/*
 * @lc app=leetcode id=1296 lang=cpp
 *
 * [1296] Divide Array in Sets of K Consecutive Numbers
 */

// @lc code=start
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (k == 1) { return true; }
        if (nums.size() % k != 0) { return false; }

        unordered_map<int, int> ump;
        for (int n : nums) { ++ump[n]; }
        
        queue<int> q;
        for (int n : nums) {
            if (ump.count(n - 1) == 0) { q.push(n); }
        }

        int first(0);
        while (!q.empty()) {
            first = q.front();
            q.pop();
            for (int i = k; i > 0; --i) {
                //cout << first << ' ' << i << ' ' << first + i - 1 << endl;
                if (ump[first + i - 1] < ump[first]) { return false; }
                ump[first + i - 1] -= ump[first];
                if (ump[first + i - 1] == 0) {
                    ump.erase(first + i - 1);
                    if (ump.count(first + i) > 0) { q.push(first + i);}
                }
            }
        }
        return true;
    }
};
// @lc code=end

