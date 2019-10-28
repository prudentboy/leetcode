/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> m;
        return canCross(stones, m, 0, 0);
    }
private:
    bool canCross(const vector<int>& stones, unordered_map<int, bool>& m, int index, int k)
    {
        int key = index | (k << 11);
        if (m.count(key) > 0) return m[key];

        for (int i(index + 1); i < stones.size(); ++i)
        {
            int knew = stones[i] - stones[index];
            if (knew < k - 1) continue;
            if (knew > k + 1)
            {
                m[key] = false;
                return false;
            }
            if (canCross(stones, m, i, knew))
            {
                m[key] = true;
                return true;
            }
        }
        m[key] = (index + 1 == stones.size());
        return m[key];
    }
};
// @lc code=end

