/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */
class Solution {
public:
    int calculate(string s) {
        long long int ans(0), num(0), loc(0);
        char c(0), op('+');
        for (int i(0); i < s.size(); ++i)
        {
            c = s[i];
            //cout << num << ' ' << loc << ' ' << ans << ' ' << op << endl;
            if (isdigit(c)) num = num * 10 + c - '0';
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.size() - 1)
            {
                switch(op)
                {
                    case '+': loc += num; break;
                    case '-': loc -= num; break;
                    case '*': loc *= num; break;
                    case '/': loc /= num; break;
                }
                num = 0;
                op = c;
                if (c == '+' || c == '-' || i == s.size() - 1)
                {
                    ans += loc;
                    loc = 0;
                }
            }
            //cout << num << ' ' << loc << ' ' << ans << ' ' << op << endl;
        }
        return ans;
    }
};

