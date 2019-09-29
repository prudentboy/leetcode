/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3) return false;
        long long int prePre(0), pre(0), now(0);
        for (int i(0); i < num.size() / 2; ++i)
        {
            prePre = stoll(num.substr(0, i + 1));
            if (i > 0 && num[0] == '0') break;
            for (int j(i + 1); j < num.size(); ++j)
            {
                if (num.size() - j - 1 < max(i, j - i)) break;
                if (j - i > 1 && num[i + 1] == '0') continue;
                pre = stoll(num.substr(i + 1, j - i));
                //cout << prePre << ' ' << pre << endl;
                if (isAdditiveNumber(num, j + 1, prePre, pre)) return true;
            }
        }
        return false;
    }
private:
    bool isAdditiveNumber(const string& num, size_t index, long long int a, long long int b)
    {
        if (index == num.size()) return true;
        string tmp(to_string(a + b));
        //cout << a << '-' << b << '-' << tmp << endl;
        if (num.size() - index < tmp.size()) return false;
        if (num.substr(index, tmp.size()) != tmp) return false;
        return isAdditiveNumber(num, index + tmp.size(), b, a + b);
    }
};

