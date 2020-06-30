/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return subarrayWithMostKDistinct(A, K) - subarrayWithMostKDistinct(A, K - 1);
    }
private:
    int subarrayWithMostKDistinct(const vector<int>& A, int K) {
        int ans(0);
        int n(A.size());
        int left(0), right(0);
        unordered_map<int, int> ump;
        for (right = 0; right < n; ++right) {
            ++ump[A[right]];
            while (ump.size() > K) {
                if (--ump[A[left]] <= 0) { ump.erase(A[left]); }
                ++left;
            }
            ans += right - left + 1;
        }
        //cout << K << ':' << ans << endl;
        return ans;
    }
};
// @lc code=end

