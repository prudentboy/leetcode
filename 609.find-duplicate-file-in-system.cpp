/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> dict;
        string dir, file, content;
        size_t pre(0), pos(0), pos_in(0);
        int cnt(0);
        for (const string& p : paths)
        {
            //cout << ++cnt << " : " << endl;
            pos = p.find_first_of(" ", 0);
            dir.assign(p.substr(0, pos));
            //cout << dir << endl;
            while (pos != string::npos)
            {
                pre = pos;
                pos = p.find_first_of(" ", pos + 1);
                if (pos != string::npos)
                {
                    file.assign(p.substr(pre + 1, pos - pre - 1));
                    pos_in = file.find_first_of("(");
                    content.assign(file.substr(pos_in + 1));
                    content.pop_back();
                    file.resize(pos_in);
                    //cout << file << '&' << content << endl;
                    dict[content].push_back(dir + '/' + file);
                }
            }
            file.assign(p.substr(pre + 1));
            pos_in = file.find_first_of("(");
            content.assign(file.substr(pos_in + 1));
            content.pop_back();
            file.resize(pos_in);
            //cout << file << '&' << content << endl;
            dict[content].push_back(dir + '/' + file);
        }

        vector<vector<string>> ans;
        for (const auto& p : dict)
            if (p.second.size() > 1) ans.push_back(p.second);
        
        return ans;
    }
};
// @lc code=end

