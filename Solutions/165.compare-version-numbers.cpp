/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        double v1(getVersionDouble(version1)), v2(getVersionDouble(version2));
        if (abs(v1 - v2) < 1e-60) return 0;
        return v1 > v2 ? 1 : -1;
    }
private:
    double getVersionDouble(const string& s)
    {
        const double cFactor = 1.0 / 100;
        double ans(0.0), factor(1.0);

        string tmp(s), now;
        int num(0);
        size_t index(0);
        while (index != string::npos)
        {
            index = tmp.find_first_of('.');
            now = tmp.substr(0, index);
            num = atoi(now.c_str());
            tmp = tmp.substr(index + 1);
            ans += num * factor;
            factor *= cFactor;
        }

        return ans;
    }
};

