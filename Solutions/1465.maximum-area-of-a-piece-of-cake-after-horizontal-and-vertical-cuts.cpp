/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */

// @lc code=start
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int pre(0);
        int mh(0), mw(0);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        for (int cut : horizontalCuts) {
            mh = max(mh, cut - pre);
            pre = cut;
        }
        mh = max(mh, h - pre);

        pre = 0;
        sort(verticalCuts.begin(), verticalCuts.end());
        for (int cut : verticalCuts) {
            mw = max(mw, cut - pre);
            pre = cut;
        }
        mw = max(mw, w - pre);

        return (long long int)mh * mw % 1000000007;
    }
};
// @lc code=end

