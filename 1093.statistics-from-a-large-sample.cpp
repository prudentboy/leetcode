/*
 * @lc app=leetcode id=1093 lang=cpp
 *
 * [1093] Statistics from a Large Sample
 */

// @lc code=start
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans(5, -1.0);

        int i(0);
        long sum(0), cnt(0), mxCnt(0);
        for (i = 0; i < count.size(); ++i) {
            if (count[i] == 0) { continue; }
            if (ans[0] < 0) { ans[0] = i; }
            ans[1] = i;
            sum += count[i] * i;
            cnt += count[i];
            if (count[i] > mxCnt) {
                mxCnt = count[i];
                ans[4] = i;
            }
        }
        ans[2] = (double)sum / cnt;
        int tmp(0), med(0);
        if ((cnt & 1) == 1) {
            for (i = 0; i < count.size(); ++i) {
                tmp += count[i];
                if (tmp >= ((cnt + 1) >> 1)) {
                    ans[3] = i;
                    break;
                }
            }
        } else {
            for (i = 0; i < count.size(); ++i) {
                tmp += count[i];
                if (tmp < ((cnt >> 1) - 1)) { continue; }
                if (tmp == ((cnt >> 1) - 1)) {
                    med += i;
                } else if (tmp == (cnt >> 1)) {
                    med += i;
                    if (med > i) { break; }
                } else {
                    med += i;
                    if (med == i) { med <<= 1; }
                    break;
                }
            }
            ans[3] = med / 2.0;
        }

        return ans;
    }
};
// @lc code=end

