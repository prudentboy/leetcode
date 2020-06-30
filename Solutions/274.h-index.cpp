/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int i;
        for (i = 0; i < citations.size(); ++i)
        {
            if (citations[i] > i) continue;
            return i;
        }
        return i;
    }
};

