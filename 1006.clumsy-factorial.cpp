/*
 * @lc app=leetcode id=1006 lang=cpp
 *
 * [1006] Clumsy Factorial
 */

// @lc code=start
class Solution {
public:
    int clumsy(int N) {
        if (N == 1) { return 1; }

        long long int ans(N);
        int opt(0);
        while (--N > 0) {
            switch (opt) {
                case 0:
                    ans *= N;
                    break;
                case 1:
                    ans /= N;
                    break;
                case 2:
                    ans += N;
                    break;
                case 3: default:
                    if (N <= 2) {
                        ans -= N;
                    } else {
                        ans -= (long)N * (N - 1) / (N - 2);
                        N -= 2;
                        opt = 1;
                    }
            }
            //cout << ans << endl;
            updateOpt(opt);
        }

        return ans;
    }
private:
    void updateOpt(int& opt) {
        opt = (opt + 1) % 4;
    }
};
// @lc code=end

