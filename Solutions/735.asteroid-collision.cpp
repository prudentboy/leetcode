/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        bool explode(false);
        vector<int> ans;
        for (int n : asteroids)
        {
            if (ans.empty() || n > 0 || n * ans.back() > 0)
            {
                ans.push_back(n);
                continue;
            }
            explode = false;
            while (!ans.empty() && n * ans.back() < 0)
            {
                if (n + ans.back() > 0)
                {
                    explode = true;
                    break;
                }
                if (n + ans.back() == 0)
                {
                    explode = true;
                    ans.pop_back();
                    break;
                }
                ans.pop_back();
            }
            if (!explode) ans.push_back(n);
        }
        return ans;
    }
};
// @lc code=end

