/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left(0), right(0);
        int cnt(0), ans(0);
        while (right < A.size()) {
            while (right < A.size() && cnt <= K) {
                if (A[right] == 0) {
                    if (++cnt > K) { break; }
                }
                ans = max(ans, right - left + 1);
                ++right;
            }
            //cout << "right: " << left << ' ' << right << ' ' << ans << endl;
            while (right < A.size() && left <= right && cnt > K) {
                if (A[left] == 0) {
                    --cnt;
                }
                ++left;
            }
            ++right;
            //cout << "left: " << left << ' ' << right << ' ' << ans << endl;
        }

        return ans;
    }
};
// @lc code=end

