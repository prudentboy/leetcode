/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n(arr.size());
        vector<int> xors(n + 1);
        for (int i(1); i < n + 1; ++i) { xors[i] = xors[i - 1] ^ arr[i - 1]; }

        vector<int> ans(queries.size());

        for (int i(0); i < ans.size(); ++i) {
            ans[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];
        }

        return ans;
    }
};
// @lc code=end

