/*
 * @lc app=leetcode id=996 lang=cpp
 *
 * [996] Number of Squareful Arrays
 */

// @lc code=start
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        int n(A.size());
        sort(A.begin(), A.end());
        vector<bool> used(n, false);
        vector<int> cur;
        int ans(0);
        dfs(cur, A, used, ans);
        return ans;
    }
private:
    bool isSquare(int n) {
        int x = sqrt(n);
        return x * x == n;
    }

    void dfs(vector<int>& cur, const vector<int>& A, vector<bool>& used, int& ans) {
        //for (int x : cur) { cout << x << ' '; }
        //cout << endl;

        if (cur.size() == A.size()) {
            ++ans;
            return;
        }

        for (int i(0); i < A.size(); ++i) {
            if (used[i]) { continue; }
            if (i > 0 && !used[i - 1] && A[i] == A[i - 1]) { continue; }
            if (!cur.empty() && !isSquare(cur.back() + A[i])) { continue; }

            cur.push_back(A[i]);
            used[i] = true;
            dfs(cur, A, used, ans);
            used[i] = false;
            cur.pop_back();
        }
    }
};
// @lc code=end

