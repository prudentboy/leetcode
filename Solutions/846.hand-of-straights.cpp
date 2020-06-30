/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W != 0) return false;
        unordered_map<int, int> m;
        for (int n : hand) ++m[n];
        sort(hand.begin(), hand.end());
        int i(0);
        for (int n : hand) {
            if (m[n] == 0) continue;
            for (i = n; i < n + W; ++i) {
                if (m.count(i) == 0 || m[i] == 0) return false;
                --m[i]; 
            }
        }
        return true;
    }
};
// @lc code=end

