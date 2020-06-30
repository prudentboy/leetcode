/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 */

// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() <= 1) return false;

        unordered_map<int, unsigned int> nums;
        for (int i = 0; i < deck.size(); ++i)
        {
            if (nums.find(deck[i]) == nums.end())
            {
                nums[deck[i]] = 1;
            }
            else
            {
                ++nums[deck[i]];
            }
        }

        int min = 20000;
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (it->second < min) min = it->second;
        }

        if (min <= 1) return false;

        for (int i = 2; i <= min; ++i)
        {
            auto it = nums.begin();
            for (; it != nums.end(); ++it)
            {
                if (it->second % i != 0)
                {
                    break;
                }
            }
            if (it == nums.end()) return true;
        }
        return false;
    }
};
// @lc code=end

