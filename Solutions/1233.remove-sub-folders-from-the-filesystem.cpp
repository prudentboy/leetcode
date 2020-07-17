/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        unordered_set<string> ust;

        sort(folder.begin(), folder.end());
        
        bool flag(false);
        string prefix;
        for (auto& f : folder) {
            prefix.clear();
            flag = false;
            for (char c : f) {
                if (prefix.size() > 1 && c == '/' && ust.count(prefix)) {
                    flag = true;
                    break;
                }
                prefix += c;
            }
            if (flag) { continue; }
            ust.insert(f);
            ans.push_back(f);
        }

        return ans;
    }
};
// @lc code=end

