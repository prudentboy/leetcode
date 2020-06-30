/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        unordered_map<string, double> m;
        return helper(N, K, r, c, m);
    }
private:
    double helper(int N, int k, int i, int j, unordered_map<string, double>& m)
    {
        if (k == 0) return 1.0;
        string key(to_string(i));
        key += ';';
        key.append(to_string(j));
        key += ';';
        key.append(to_string(k));
        //cout << key << endl;
        if (m.count(key) > 0) return m[key];

        static const vector<int> posX = {-2,-2,-1,-1,1,1,2,2};
        static const vector<int> posY = {-1,1,-2,2,-2,2,-1,1};
        double ans(0.0);
        for (int l = 0; l < 8; ++l)
        {
            if (i + posX[l] < 0 || i + posX[l] >= N) continue;
            if (j + posY[l] < 0 || j + posY[l] >= N) continue;
            ans += helper(N, k - 1, i + posX[l], j + posY[l], m) / 8.0;
        }
        m[key] = ans;
        return ans;
    }
};
// @lc code=end

