/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data)
    {
        for (int i(0); i < data.size(); ++i)
        {
            if ((data[i] >> 7) == 0) continue;
            else if ((data[i] >> 5) == 6)
            {
                if (i + 1 >= data.size() || (data[++i] >> 6) != 2) return false;
            }
            else if ((data[i] >> 4) == 14)
            {
                if (i + 1 >= data.size() || (data[++i] >> 6) != 2) return false;
                if (i + 1 >= data.size() || (data[++i] >> 6) != 2) return false;
            }
            else if ((data[i] >> 3) == 30)
            {
                if (i + 1 >= data.size() || (data[++i] >> 6) != 2) return false;
                if (i + 1 >= data.size() || (data[++i] >> 6) != 2) return false;
                if (i + 1 >= data.size() || (data[++i] >> 6) != 2) return false;
            }
            else return false;
        }
        return true;
    }
};
// @lc code=end
