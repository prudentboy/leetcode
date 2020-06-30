/*
 * @lc app=leetcode id=722 lang=cpp
 *
 * [722] Remove Comments
 */

// @lc code=start
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        if (source.empty()) return {};

        bool flag = false;
        size_t pos(0);
        vector<string> ans;
        string tmp;

        for (int i(0); i < source.size(); ++i)
        {
            //s = source[i];
            //cout << i << ':' << tmp << endl;
            if (flag)
            {
                pos = source[i].find("*/");
                if (pos == string::npos) continue;
                flag = false;
                //if (pos + 2 == source[i].size()) continue;
                source[i] = source[i].substr(pos + 2);
                //cout << i << '|' << source[i] << endl;
                --i;
            }
            else
            {
                //cout << source[i] << '-' << tmp << endl;
                pos = source[i].find_first_of("/");
                while (pos != string::npos)
                {
                    if (pos + 1 < source[i].size() && source[i][pos + 1] == '/')
                    {
                        tmp.append(source[i].substr(0, pos));
                        if (!tmp.empty()) ans.push_back(tmp);
                        tmp.clear();
                        break;
                    }
                    else if (pos + 1 < source[i].size() && source[i][pos + 1] == '*')
                    {
                        flag = true;
                        tmp.append(source[i].substr(0, pos));
                        source[i].assign(source[i].substr(pos + 2));
                        --i;
                        break;
                    }
                    pos = source[i].find_first_of("/", pos + 1);
                }
                if (pos == string::npos)
                {
                    tmp.append(source[i]);
                    if (!tmp.empty()) ans.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        return ans;
    }
};
// @lc code=end

