/*
 * @lc app=leetcode id=831 lang=cpp
 *
 * [831] Masking Personal Information
 */

// @lc code=start
class Solution {
public:
    string maskPII(string S) {
        if (isEmail(S)) return maskEmail(S);
        else return maskPhone(S);
    }
private:
    inline bool isEmail(const string& S) {
        return S.find("@") != string::npos;
    }
    string maskEmail(const string& S) {
        string ans;
        int pos = S.find_first_of("@");
        ans += S[0];
        ans.append(5, '*');
        ans += S[pos - 1];
        ans.append(S.substr(pos));
        transform(ans.begin(), ans.end(), ans.begin(), [](char c){return tolower(c);});
        return ans;
    }
    string maskPhone(const string& S) {
        string ans("***-***-****");
        int n(S.size()), i(n - 1), j(11), cnt(0);
        for (; i >= 0; --i) {
            //cout << i << ' ' << j << ' ' << cnt << endl;
            if (S[i] >= '0' && S[i] <= '9') {
                ++cnt;
                if (cnt < 5) ans[j--] = S[i];
            }
        }
        if (cnt == 10) return ans;
        string pre("+" + string(cnt - 10, '*') + '-');
        return pre + ans;
    }
};
// @lc code=end

