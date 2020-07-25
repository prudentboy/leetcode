/*
 * @lc app=leetcode id=1483 lang=cpp
 *
 * [1483] Kth Ancestor of a Tree Node
 */

// @lc code=start
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) : mxLevel_(getMaxBitCnt(n)), dp_(mxLevel_, vector<int>(n, -1)) {
        for (int i(0); i < n; ++i) { dp_[0][i] = parent[i]; }
        for (int i(1); i < mxLevel_; ++i) {
            for (int j(1); j < n; ++j) {
                if (dp_[i - 1][j] == -1) { continue; }
                dp_[i][j] = dp_[i - 1][dp_[i - 1][j]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int ret(node);
        for (int i(0); i < mxLevel_; ++i) {
            if (ret == -1) { return ret; }
            if ((k & (1 << i)) > 0) { ret = dp_[i][ret]; }
        }
        return ret;
    }
private:
    inline const int getMaxBitCnt(int n) {
        int cnt(0);
        while (n > 0) {
            n >>= 1;
            ++cnt;
        }
        return cnt;
    }
    int mxLevel_;
    vector<vector<int>> dp_;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end

