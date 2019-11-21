/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        if (num < 10) return num;
        string str(to_string(num));
        int i(0), j(0), k(0);
        for (i = 1; i < str.size(); ++i)
            if (str[i] > str[i - 1]) break;
        if (i == str.size()) return num;
        
        k = i;
        for (j = i + 1; j < str.size(); ++j)
            if (str[j] >= str[k]) k = j;
        for (j = 0; j < i; ++j)
            if (str[j] < str[k]) break;
        swap(str[j], str[k]);

        return stoi(str);
    }
};
// @lc code=end

