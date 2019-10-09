/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        
        queue<string> q;
        q.push(s);
        unordered_set<string> us;
        us.insert(s);
        
        string tmp, stmp;
        bool found(false);
        
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            //found = false;
            
            if (isValid(tmp))
            {
                //cout << tmp << endl;
                found = true;
                ans.push_back(tmp);
            }
            if (found) continue;
            
            for (int i(0); i < tmp.size(); ++i)
            {
                if (tmp[i] != '(' && tmp[i] != ')') continue;
                stmp.assign(tmp.substr(0, i).append(tmp.substr(i + 1)));
                if (us.count(stmp)) continue;
                q.push(stmp);
                us.insert(stmp);
            }
        }
        
        return ans;
    }
private:
    bool isValid(const string& s)
    {
        if (s.empty()) return true;
        
        int cnt(0);
        for (int i(0); i < s.size(); ++i)
        {
            if (s[i] == '(') ++cnt;
            else if (s[i] == ')')
            {
                --cnt;
                if (cnt < 0) return false;
            }
        }
        
        return cnt == 0;
    }
};
// @lc code=end

