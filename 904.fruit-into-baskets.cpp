/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if (tree.size() < 3) { return tree.size(); }
        int bucketA(-1), bucketB(-1);
        int cntA(0), cntB(0), begin(0);
        int ans(0);
        for (int i(0); i < tree.size(); ++i) {
            if (tree[i] == bucketA) {
                ++cntA;
            } else if (tree[i] == bucketB) {
                ++cntB;
            } else if (cntA == 0) {
                bucketA = tree[i];
                cntA = 1;
            } else if (cntB == 0) {
                bucketB = tree[i];
                cntB = 1;
            } else {
                while (cntA > 0 && cntB > 0) {
                    if (tree[begin] == bucketA) {
                        --cntA;
                    } else if (tree[begin] == bucketB) {
                        --cntB;
                    }
                    ++begin;
                }
                --i;
            }
            ans = max(ans, cntA + cntB);
        }
        return ans;
    }
};
// @lc code=end

