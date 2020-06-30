/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n(citations.size());

        int i(n - 1);
        for (; i >= 0; --i)
        {
            if (citations[i] >= n - i) continue;
            return n - i - 1;
        }
        return n - i - 1;
    }
};

