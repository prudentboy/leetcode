/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        const int n(points.size());
        if (n <= 3) { return points; }

        sort(points.begin(), points.end());

        set<vector<int>> st;
        st.insert(points.front());
        vector<int> cur(points.front());
        int curIdx(0), firstIdx(0);

        while (true) {
            vector<int> nxt(points.front());
            int nxtIdx(0);
            for (int i(1); i < n; ++i) {
                if (i == curIdx) { continue; }
                int cp(crossProduct(cur, points[i], nxt));
                if (nxtIdx == curIdx || cp > 0 || (cp == 0 && disSquare(points[i], cur) > disSquare(nxt, cur))) {
                    nxt = points[i];
                    nxtIdx = i;
                }
            }
            for (int i(0); i < n; ++i) {
                if (i == curIdx) { continue; }
                if (crossProduct(cur, points[i], nxt) == 0) { st.insert(points[i]); }
            }
            swap(cur, nxt);
            curIdx = nxtIdx;
            if (curIdx == firstIdx) { break; }
        }

        vector<vector<int>> ans;
        for (auto& point : st) { ans.push_back(point); }
        return ans;
    }
private:
    int disSquare(const vector<int>& p1, const vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
    int crossProduct(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) {
        int BAx(p1[0] - p2[0]), BAy(p1[1] - p2[1]);
        int BCx(p3[0] - p2[0]), BCy(p3[1] - p2[1]);
        return BAx * BCy - BAy * BCx;
    }
};
// @lc code=end

