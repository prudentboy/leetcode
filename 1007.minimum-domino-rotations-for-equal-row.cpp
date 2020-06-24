/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */

// @lc code=start
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n(A.size());

        int i(0);
        int frontA(1), frontB(0), backA(0), backB(1);
        bool front(true), back(true);
        vector<int> possible({A[0], B[0]});

        for (i = 1; i < n; ++i) {
            if (front) {
                if (A[i] != possible.front() && B[i] != possible.front()) {
                    possible.erase(possible.begin());
                    front = false;
                    frontA = -1;
                    frontB = -1;
                } else {
                    if (A[i] == possible.front()) { ++frontA; }
                    if (B[i] == possible.front()) { ++frontB; }
                }
            }
            if (back) {
                if (A[i] != possible.back() && B[i] != possible.back()) {
                    possible.pop_back();
                    back = false;
                    backA = -1;
                    backB = -1;
                } else {
                    if (A[i] == possible.back()) { ++backA; }
                    if (B[i] == possible.back()) { ++backB; }
                }
            }

            if (possible.empty()) { return -1; }
        }

        return n - max(frontA, max(frontB, max(backA, backB)));
    }
};
// @lc code=end

