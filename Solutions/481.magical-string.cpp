/*
 * @lc app=leetcode id=481 lang=cpp
 *
 * [481] Magical String
 */

// @lc code=start
class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n <= 3) return 1;
        queue<int> q;
        q.push(2);
        int cnt(1), len(3), tmp(0);
        int num(1);
        while (!q.empty() && len < n)
        {
            tmp = q.front();
            q.pop();
            len += tmp;
            if (tmp == 1)
            {
                q.push(num);
                if (num == 1) ++cnt;
            }
            else
            {
                q.push(num);
                q.push(num);
                if (num == 1) cnt += (len > n ? 1 : 2);
            }
            num = (num == 1 ? 2 : 1);
        }
        return cnt;
    }
};
// @lc code=end

