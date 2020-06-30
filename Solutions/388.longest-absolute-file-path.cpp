/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 */

// @lc code=start
class Solution {
public:
    int lengthLongestPath(string input) {
        if (input.empty()) return 0;

        int ans(0), level(0), preLen(0);
        bool isFile(false);
        string curPath;
        stack<pair<string, int>> s;
        input += '\n';

        for (int i(0); i < input.size(); ++i)
        {
            if (input[i] != '\n')
            {
                if (input[i] == '\t') ++level;
                else
                {
                    curPath += input[i];
                    if (input[i] == '.') isFile = true;
                }
            }
            else
            {
                while (!s.empty() && s.top().second >= level)
                {
                    preLen -= s.top().first.size() + 1;
                    s.pop();
                }
                if (isFile) ans = max(ans, preLen + (int)curPath.size() + 1);
                else
                {
                    s.push({curPath, level});
                    preLen += curPath.size() + 1;
                    //if (s.size() == 1) --preLen;
                }
                level = 0;
                isFile = false;
                curPath.clear();
            }
        }

        if (ans > 0) --ans;
        return ans ;
    }
};
// @lc code=end

