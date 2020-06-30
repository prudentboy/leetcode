/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if (nums.empty()) return ans;

        int ma(0), mb(0), cnta(0), cntb(0);
        for (int n : nums)
        {
            if (ma == n) ++cnta;
            else if (mb == n) ++cntb;
            else if (cnta == 0)
            {
                ma = n;
                ++cnta;
            }
            else if (cntb == 0)
            {
                mb = n;
                ++cntb;
            }
            else
            {
                --cnta;
                --cntb;
            }
        }
        cnta = 0;
        cntb = 0;
        for (int n : nums)
        {
            if (n == ma) ++cnta;
            else if (n == mb) ++cntb;
        }
        if (cnta > nums.size() / 3) ans.push_back(ma);
        if (cntb > nums.size() / 3) ans.push_back(mb);

        return ans;
    }
};

