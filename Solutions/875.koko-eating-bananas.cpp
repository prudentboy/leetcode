/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int ans(0);
        int mx(0), n(piles.size());
        for (int num : piles) mx = max(mx, num);
        int times(H / n);
        int l(max(1, mx / H)), r(mx / times), mid(0);
        if (mx % times != 0) ++r;
        int cnt(0);
        //cout << l << ' ' << r << endl;
        while (l < r)
        {
            mid = l + ((r - l) >> 1);
            if (r == mid) return r;
            cnt = 0;
            for (int p : piles)
            {
                cnt += p / mid;
                if (p % mid != 0) ++cnt;
            }
            if (cnt <= H) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};
// @lc code=end

