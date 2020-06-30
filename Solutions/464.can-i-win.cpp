/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */

// @lc code=start
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) < desiredTotal * 2) return false;
        
        unordered_map<int, bool> m;
        return canIWin(m, 0, maxChoosableInteger, desiredTotal);
    }
private:
    bool canIWin(unordered_map<int, bool>& m, int visited, int maxn, int target)
    {
        //cout << m.size() << ' ' << visited << endl;
        if (m.count(visited) > 0) return m[visited];

        for (int i(1); i <= maxn; ++i)
        {
            int mask(1 << i);
            if ((visited & mask) != 0) continue;
            if (i >= target || !canIWin(m, visited | mask, maxn, target - i))
            {
                m[visited] = true;
                return true;
            } 
        }
        m[visited] = false;
        return false;
    }
};
// @lc code=end

