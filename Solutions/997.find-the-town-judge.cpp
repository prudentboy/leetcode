/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int ans(-1);
        vector<int> ind(N, 0), outd(N, 0);
        for (int i(0); i < trust.size(); ++i)
        {
            ++outd[trust[i][0] - 1];
            ++ind[trust[i][1] - 1];
        }

        for (int i(0); i < N; ++i)
        {
            if (outd[i] > 0) continue;
            if (ind[i] == N - 1)
            {
                if (ans != -1) return -1;
                ans = i + 1;
            }
        }
        return ans;
    }
};

