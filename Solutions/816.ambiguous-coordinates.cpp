/*
 * @lc app=leetcode id=816 lang=cpp
 *
 * [816] Ambiguous Coordinates
 */

// @lc code=start
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        unordered_set<string> ans;
        string firstStr, secondStr;
        vector<string> first, second;
        for (int i(2); i < S.size() - 1; ++i) {
            firstStr.assign(S.substr(1, i - 1));
            first = getRealStr(firstStr);
            if (first.empty()) continue;
            secondStr.assign(S.substr(i));
            secondStr.pop_back();
            second = getRealStr(secondStr);
            if (second.empty()) continue;
            for (auto& f : first) {
                for (auto& se : second) {
                    ans.insert("(" + f + ", " + se + ")");
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
private:
    vector<string> getRealStr(const string& str) {
        //cout << str << endl;
        if (str.empty()) return {};
        if (str.size() == 1) return {str};
        if (str[0] == '0' && str.back() == '0') return {};
        if (str.back() == '0') return {str};
        
        string numStr(str);
        if (str[0] == '0') {
            numStr.insert(1, 1, '.');
            return {numStr};
        }

        vector<string> ans;
        ans.push_back(str);
        for (int i(1); i < str.size(); ++i) {
            numStr.assign(str);
            numStr.insert(i, 1, '.');
            ans.push_back(numStr);
        }
        return ans;
    }
};
// @lc code=end

