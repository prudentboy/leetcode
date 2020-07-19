/*
 * @lc app=leetcode id=1452 lang=cpp
 *
 * [1452] People Whose List of Favorite Companies Is Not a Subset of Another List
 */

// @lc code=start
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int cnt(0);
        unordered_map<string, int> com_ump;
        for (auto& fav : favoriteCompanies) {
            for (auto& com : fav) {
                if (com_ump.count(com) == 0) { com_ump[com] = cnt++; }
            }
        }

        int n(favoriteCompanies.size());
        int i(0), j(0);
        vector<vector<int>> favDict(n, vector<int>(cnt));
        for (i = 0; i < n; ++i) {
            for (auto& com : favoriteCompanies[i]) { favDict[i][com_ump[com]] = 1; }
        }

        vector<int> ans;
        bool isSubSet(false), miss(false);
        for (i = 0; i < n; ++i) {
            isSubSet = false;
            for (j = 0; j < n; ++j) {
                if (i == j) { continue; }
                if (isSubSet) { break; }
                miss = false;
                for (auto& com : favoriteCompanies[i]) {
                    if (miss) { break; }
                    if (favDict[j][com_ump[com]] == 0) { miss = true; }
                }
                if (!miss) {
                    isSubSet = true;
                    break;
                }
            }
            if (!isSubSet) { ans.push_back(i); }
        }

        return ans;
    }
};
// @lc code=end

