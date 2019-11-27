/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n <= 0) return tasks.size();
        
        int mx(0), mxCnt(0);
        array<int, 26> cnts = {0};
        for (char t : tasks)
        {
            ++cnts[t - 'A'];
            if (mx == cnts[t - 'A']) ++mxCnt;
            else if (mx < cnts[t - 'A'])
            {
                mx = cnts[t - 'A'];
                mxCnt = 1;
            }
        }
        int tofillCnt = (mx - 1) * (n + 1 - mxCnt);
        int idleCnt = max(0, tofillCnt - ((int)tasks.size() - mx * mxCnt));
        return tasks.size() + idleCnt; 
    }
};
// @lc code=end

