/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        if (time.size() < 2) return 0;
        
        int ans(0), i(0);
        vector<long long int> reminder(60, 0);
        for (; i < time.size(); ++i) ++reminder[time[i] % 60];
        for (i = 1; i < 30; ++i) ans += (reminder[i] * reminder[60 - i]);
        ans += (reminder[0] * (reminder[0] - 1) >> 1);
        ans += (reminder[30] * (reminder[30] - 1) >> 1);

        return ans;
    }
};

