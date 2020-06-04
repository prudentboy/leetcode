/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */

// @lc code=start
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        
        int i(0), now(1);
        for (i = 0; candies >= now; i = (i + 1) % num_people) {
            //cout << i << ' ' << now << ' ' << candies << endl;
            ans[i] += now;
            candies -= now++;
        }
        ans[i] += candies;
        return ans;
    }
};
// @lc code=end

