/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 */

// @lc code=start
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int i(0), factor(1);
        long long int len(0);
        
        for (i = 0; i < S.size(); ++i) {
            if (S[i] > '1' && S[i] <= '9') {
                factor = S[i] - '0';
                len *= factor;
            } else {
                ++len;
                if (len == K) return string(1, S[i]);
            }
            //cout << i << ' ' << S[i] << ' ' << len << ' ' << factor << endl;
            if (len >= K) return decodeAtIndex(S, (K - 1) % (len / factor) + 1);
        }

        return "";
    }
private:
};
// @lc code=end

