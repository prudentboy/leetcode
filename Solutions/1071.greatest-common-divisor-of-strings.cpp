/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.empty() || str2.empty()) return "";
        int len(gcd(str1.size(), str2.size()));
        string tmp;
        for (int i(1); i <= len; ++i)
        {
            if (len % i != 0) continue;
            tmp.assign(str2.substr(0, len / i));
            if (isFacOfString(str1, tmp) && isFacOfString(str2, tmp)) return tmp;
        }

        return "";
    }
private:
    int gcd(int a, int b)
    {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
    bool isFacOfString(const string& ori, const string& sub)
    {
        //if (ori.size() % sub.size() != 0) return false;
        int cnt(ori.size() / sub.size());
        int j(0), k(0);
        for (int i(0); i < cnt; ++i)
        {
            j = 0;
            while(j < sub.size())
            {
                if (ori[k++] != sub[j++]) return false;
            }
        }
        return true;
    }
};
// @lc code=end

