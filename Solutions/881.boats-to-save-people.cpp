/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if (people.size() < 2) return people.size();

        int ans(0);
        sort(people.begin(), people.end());
        int l(0), r(people.size() - 1);
        while (l <= r)
        {
            if (people[l] + people[r--] <= limit) ++l;
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

