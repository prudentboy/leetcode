/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size() < 2) return 0;

        vector<int> mask(words.size(), 0);
        int i(0), j(0);
        for (i = 0; i < words.size(); ++i)
        {
            for (char c : words[i]) mask[i] |= (1 << (c - 'a'));
        }

        int ans(0);
        for (i = 0; i < words.size() - 1; ++i)
        {
            for (j = i + 1; j < words.size(); ++j)
            {
                if ((mask[i] & mask[j]) != 0) continue;
                ans = max(ans, int(words[i].size() * words[j].size()));
            }
        }
        return ans;
    }
};

