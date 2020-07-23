/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 */

// @lc code=start
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> ancestors(n);
        iota(ancestors.begin(), ancestors.end(), 0);
        function<int(int)> find = [&](int idx) {
            if (ancestors[idx] != idx) {
                ancestors[idx] = find(ancestors[idx]);
            }
            return ancestors[idx];
        };

        vector<int> parents(n, -1);

        int i(0), left(0), right(0), ancP(0), ancC(0);
        for (i = 0; i < n; ++i) {
            left = leftChild[i];
            right = rightChild[i];
            ancP = find(i);
            if (left >= 0) {
                if (parents[left] >= 0) { return false; }
                parents[left] = i;
                ancC = find(left);
                if (ancC == ancP) { return false; }
                ancestors[ancC] = ancP;
            }
            if (right >= 0) {
                if (parents[right] >= 0) { return false; }
                parents[right] = i;
                ancC = find(right);
                if (ancC == ancP) { return false; }
                ancestors[ancC] = ancP;
            }
        }

        int cnt(0);
        for (i = 0; i < n; ++i) { if (ancestors[i] == i) {++cnt;} }
        return cnt == 1;
    }
};
// @lc code=end

