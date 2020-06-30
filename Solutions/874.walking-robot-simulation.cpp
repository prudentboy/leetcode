/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans(0);

        string tmp;
        unordered_set<string> ob_set;
        for (const auto& ob : obstacles)
        {
            tmp.assign(to_string(ob[0]));
            tmp += '-';
            tmp.append(to_string(ob[1]));
            ob_set.insert(tmp);
        }

        static const int Len = 4; 
        vector<int> xDirect({0, 1, 0, -1}), yDirect({1, 0, -1, 0});
        int direct(0), x(0), y(0);

        for (int c : commands)
        {
            if (c > 0)
            {
                while (c-- > 0)
                {
                    x += xDirect[direct];
                    y += yDirect[direct];
                    tmp.assign(to_string(x));
                    tmp += '-';
                    tmp.append(to_string(y));
                    if (ob_set.count(tmp) > 0)
                    {
                        x -= xDirect[direct];
                        y -= yDirect[direct];
                        break;
                    }
                }
            }
            else if (c == -1) direct = (direct + 1) % Len;
            else if (c == -2) direct = (direct + 3) % Len;
            if (x * x + y * y > ans) ans = x * x + y * y;
            //cout << x << ' ' << y << ' ' << ans << endl;
        }

        return ans;
    }
};
// @lc code=end

