/*
 * @lc app=leetcode id=564 lang=cpp
 *
 * [564] Find the Closest Palindrome
 */

// @lc code=start
class Solution {
public:
    string nearestPalindromic(string n) {
        int len(n.size());
        long long int ori(stoll(n));
        long long int left(pow(10, len - 1) - 1);
        long long int right(pow(10, len) + 1);
        long long int mn = abs(left - ori);
        string ans(to_string(left));
        updateAns(ori, right, mn, ans);

        string half(n.substr(0, len >> 1));
        reverse(half.begin(), half.end());
        string palind(n.substr(0, (len >> 1) + (len & 1)));
        palind.append(half);
        long long int p(stoll(palind));
        if (palind != n) { updateAns(ori, p, mn, ans); }

        if ((len & 1) == 1) {
            --palind[len >> 1];
            if (isValid(palind)) { p = stoll(palind); updateAns(ori, p, mn, ans); }
            palind[len >> 1] += 2;
            if (isValid(palind)) { p = stoll(palind); updateAns(ori, p, mn, ans); }
        } else {
            --palind[len >> 1];
            --palind[(len >> 1) - 1];
            if (isValid(palind)) { p = stoll(palind); updateAns(ori, p, mn, ans); }
            palind[len >> 1] += 2;
            palind[(len >> 1) - 1] += 2;
            if (isValid(palind)) { p = stoll(palind); updateAns(ori, p, mn, ans); }
        }

        return ans;
    }
private:
    bool isValid(const std::string& s) {
        if (s.empty()) { return false; }
        if (s.size() == 1) { return isdigit(s[0]); }
        if (s[0] == '0') { return false; }
        for (char c : s) {
            if (!isdigit(c)) { return false; }
        }
        return true;
    }
    void updateAns(long long int ori, long long int maybe, long long int& mn, string& ans) {
        if (abs(ori - maybe) < mn || (abs(ori - maybe) == mn && maybe < stoll(ans))) {
            mn = abs(ori - maybe);
            ans.assign(to_string(maybe));
        }
        //cout << ori << ' ' << maybe << ' ' << ans << endl;
    }
};
// @lc code=end

