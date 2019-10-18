/*
 * @lc app=leetcode id=1154 lang=cpp
 *
 * [1154] Day of the Year
 */

// @lc code=start
class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8));
        const int past[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        //cout << year << ' ' << month << ' ' << day << endl;
        int ans = past[month - 1] + day;
        if (month > 2 && isLeapYear(year)) ++ans;
        return ans;
    }
private:
    bool isLeapYear(int y)
    {
        if (y % 4 != 0) return false;
        if (y % 400 == 0) return true;
        return y % 100 != 0;
    }
};
// @lc code=end

