/*
 * @lc app=leetcode id=833 lang=cpp
 *
 * [833] Find And Replace in String
 */

// @lc code=start
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int i(0), j(0), n(indexes.size());
        vector<pair<int, int>> vp(n, {0,0});
        for (i = 0; i < n; ++i) {
            vp[i] = {indexes[i], i};
        }
        sort(vp.begin(), vp.end());

        string ans;
        for (i = 0; i < n; ++i) {
            if (vp[i].first > j) {
                ans.append(S.substr(j, vp[i].first - j));
                j = vp[i].first;
            }
            if (match(S, vp[i].first, sources[vp[i].second])) {
                ans.append(targets[vp[i].second]);
                j += sources[vp[i].second].size();
            }
        }
        if (j < S.size()) ans.append(S.substr(j));
        
        return ans;
    }
private:
    bool match(const string& S, int idx, const string& tar) {
        for (int i(0); i < tar.size(); ++i) {
            if (idx >= S.size()) return false;
            if (tar[i] != S[idx++]) return false;
        }
        return true;
    }
};
// @lc code=end

