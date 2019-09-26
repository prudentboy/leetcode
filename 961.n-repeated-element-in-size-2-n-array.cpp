/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> m;

        for (int n : A)
        {
            if (m.count(n) > 0) return n;
            m[n] = 1;
        }
        return 0;
    }
};

