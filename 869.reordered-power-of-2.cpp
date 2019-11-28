/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        if (N < 3) return true;

        string inStr(to_string(N));
        sort(inStr.begin(), inStr.end());

        string tmp;
        for (int i(0); i < 31; ++i)
        {
            tmp.assign(to_string(1 << i));
            sort(tmp.begin(), tmp.end());
            if (tmp == inStr) return true;
        }
        return false;
    }
};
// @lc code=end

