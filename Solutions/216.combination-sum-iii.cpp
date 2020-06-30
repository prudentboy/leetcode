/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        combinationSum3(k, n, 1, tmp, ans);
        return ans;
    }
private:
    void combinationSum3(int k, int n, int beg, vector<int>& tmp, vector<vector<int>>& ans)
    {
        if (n < 0) return;
        if (n == 0 && tmp.size() == k)
        {
            ans.push_back(tmp);
            return;
        }
        for (int i(beg); i < 10; ++i)
        {
            tmp.push_back(i);
            combinationSum3(k, n - i, i + 1, tmp, ans);
            tmp.pop_back();
        }
    }
};

