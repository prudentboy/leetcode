/*
 * @lc app=leetcode id=1333 lang=cpp
 *
 * [1333] Filter Restaurants by Vegan-Friendly, Price and Distance
 */

// @lc code=start
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        restaurants.erase(remove_if(restaurants.begin(), restaurants.end(), [&](const vector<int>& restaurant) {
            return (veganFriendly == 1 && restaurant[2] == 0) || restaurant[3] > maxPrice || restaurant[4] > maxDistance;
        }), restaurants.end());
        sort(restaurants.begin(), restaurants.end(), [](const vector<int>& l, const vector<int>& r) {
            if (l[1] == r[1]) { return l[0] > r[0]; }
            return l[1] > r[1];
        });

        vector<int> ans(restaurants.size());
        for (int i(0); i < ans.size(); ++i) { ans[i] = restaurants[i][0]; }
        return ans;
    }
};
// @lc code=end

