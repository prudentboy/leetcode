/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        // 处理符号
        if (isNegtive(numerator, denominator)) ans.assign("-");
        long long int n(abs((long long int)numerator)), d(abs((long long int)denominator));
        // 整数部分
        ans.append(to_string(n / d));
        n %= d;
        if (n == 0) return ans;
        ans.append(".");
        // 小数部分
        unordered_map<int, size_t> record;
        string tmp;
        while (n != 0)
        {
            n *= 10;
            if (record.count(n) > 0)
            {
                tmp.insert(record[n], "(");
                tmp.push_back(')');
                break;
            }
            tmp.append(to_string(n / d));
            record[n] = record.size();
            n %= d;
        }

        ans.append(tmp);
        return ans;
    }
private:
    bool isNegtive(int n1, int n2)
    {
        return (n1 < 0 && n2 > 0) || (n1 > 0 && n2 < 0);
    }
};

