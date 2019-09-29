/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */
class Solution {
public:
    string numberToWords(int num) {
        const vector<string> ones({"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"});
        const vector<string> tens({"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"});
        const vector<string> units({"Hundred", "Thousand", "Million", "Billion"});

        if (num < 0) return "";
        if (num < 20) return ones[num];
        string ans, s;
        int tmp(0), small(0), unit(0);
        while (num > 0)
        {
            tmp = num % 1000;
            small = tmp % 100;
            s.clear();
            if (tmp >= 100)
            {
                s.append(ones[tmp / 100]).append(" ").append(units[0]);
                if (small != 0) s.push_back(' ');
            } 
            //cout << s << endl;
            if (small != 0 && small < 20) s.append(ones[small]);
            else
            {
                if (small != 0) s.append(tens[small / 10]);
                if (small % 10 != 0) s.append(" ").append(ones[small % 10]);
            }
            //cout << s << endl;
            if (tmp != 0 && unit > 0) s.append(" ").append(units[unit]);
            //cout << s << endl;
            ++unit;
            num /= 1000;
            if (tmp != 0 && !ans.empty()) ans = " " + ans;
            ans = s + ans;
            //cout << tmp << ' ' << unit << ' ' << num << ' ' << ans << endl;
        }
        return ans;
    }
};

