/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans("0");
        
        unordered_map<char, int> m;
        unordered_map<char, int> visited;
        for (char c : s)
        {
            if (m.count(c) > 0) ++m[c];
            else m[c] = 1;
        }
        
        for (char c : s)
        {
            //cout << ans << endl;
            --m[c];
            if (visited.count(c) > 0) continue;
            while (c < ans.back() && m[ans.back()] > 0)
            {
                visited.erase(ans.back());
                ans.pop_back();
            }
            ans.push_back(c);
            visited[c] = 1;
        }
        return ans.substr(1);
    }
};
// @lc code=end

