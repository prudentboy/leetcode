/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */

// @lc code=start
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        if (A.size() < 2) { return ans; }

        vector<int> sorted(A);
        sort(sorted.begin(), sorted.end());
        int n(A.size()), i(n - 1), j(0);

        while (i >= 0) {
            if (A[i] != sorted[i]) {
                for (j = 0; j < i; ++j) {
                    if (A[j] == sorted[i]) { break; }
                }
                if (j > 0) {
                    flip(A, j);
                    ans.push_back(j + 1);
                }
                flip(A, i);
                ans.push_back(i + 1);
            }
            --i;
        }

        //for (i = 0; i < n; ++i) { cout << A[i] << ' '; }
        //cout << endl;
        return ans;
    }
private:
    void flip(vector<int>& v, int idx) {
        if (idx > v.size()) { return; }
        int i(0);
        while (i < idx) {
            swap(v[i++], v[idx--]);
        }
    }
};
// @lc code=end

