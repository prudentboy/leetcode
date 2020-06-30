/*
 * @lc app=leetcode id=467 lang=cpp
 *
 * [467] Unique Substrings in Wraparound String
 */

// @lc code=start
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        array<int, 26> arr = {0};
        
        int i(0), len(0);
        for (i = 0; i < p.size(); ++i)
        {
            if (i > 0 && (p[i] - 1 == p[i - 1] || p[i - 1] - p[i] == 25)) ++len;
            else len = 1;
            if (len > arr[p[i] - 'a']) arr[p[i] - 'a'] = len;
        }

        return accumulate(arr.begin(), arr.end(), 0);
    }
};
// @lc code=end

