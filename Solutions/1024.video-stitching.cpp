/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */

// @lc code=start
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        //printVV(clips);
        if (clips[0][0] != 0) { return -1; }
        int ans(0);
        int end(0), i(0), idx(0), mx(0);
        while (end < T) {
            mx = end;
            for (;i < clips.size(); ++i) {
                if (clips[i][0] > end) { break; }
                if (clips[i][1] > mx) {
                    mx = clips[i][1];
                    idx = i;
                }
            }
            if (mx == end) { break;}
            end = mx;
            ++ans;
        }
        return end < T ? -1 : ans;
    }
private:
    void printVV(const vector<vector<int>>& vv) {
        for (auto& v : vv) {
            for (int n : v) { cout << n << ' '; }
            cout << endl;
        }
    }
};
// @lc code=end

