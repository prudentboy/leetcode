/*
 * @lc app=leetcode id=1409 lang=cpp
 *
 * [1409] Queries on a Permutation With Key
 */

// @lc code=start
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n(queries.size());
        
        vector<int> ans(n);
        vector<int> arr(m);

        int i(0), j(0);
        for (i = 0; i < m; ++i) { arr[i] = i + 1; }

        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) { if (arr[j] == queries[i]) { break; } }
            ans[i] = j;
            rotate(arr.begin(), arr.begin() + j, arr.begin() + j + 1);
            //for (j = 0; j < m; ++j) { cout << arr[j] << ' '; }
            //cout << endl;
        }

        return ans;
    }
};
// @lc code=end

