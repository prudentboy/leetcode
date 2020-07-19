/*
 * @lc app=leetcode id=1418 lang=cpp
 *
 * [1418] Display Table of Food Orders in a Restaurant
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<string> foodList;
        vector<int> tableList;
        unordered_map<string, int> order_ump;
        unordered_set<int> table_ust;
        unordered_set<string> food_ust;
        
        int table;
        string food, key;
        for (const auto& order : orders) {
            table = stoi(order[1]);
            food.assign(order[2]);
            if (table_ust.count(table) == 0) {
                tableList.push_back(table);
                table_ust.insert(table);
            }
            if (food_ust.count(food) == 0) {
                foodList.push_back(food);
                food_ust.insert(food);
            }
            key.assign(food);
            key += order[1];
            ++order_ump[key];
        }

        sort(foodList.begin(), foodList.end());
        sort(tableList.begin(), tableList.end());

        int m(tableList.size()), n(foodList.size());
        vector<vector<string>> ans(m + 1, vector<string>(n + 1));

        ans[0][0] = "Table";
        int i(0), j(0);
        for (i = 1; i <= m; ++i) { ans[i][0] = to_string(tableList[i - 1]); }
        for (j = 1; j <= n; ++j) { ans[0][j] = foodList[j - 1]; }

        for (i = 1; i <= m; ++i) {
            for (j = 1; j <= n; ++j) {
                key.assign(foodList[j - 1]);
                key += to_string(tableList[i - 1]);
                ans[i][j] = to_string(order_ump[key]);
            }
        }

        return ans;
    }
};
// @lc code=end

