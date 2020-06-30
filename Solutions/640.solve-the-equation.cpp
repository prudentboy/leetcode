/*
 * @lc app=leetcode id=640 lang=cpp
 *
 * [640] Solve the Equation
 */

// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
        static const string INF_RET = "Infinite solutions";
        static const string NORES_RET = "No solution";
        string res("x=");

        bool eqRight(false), flag(true), xconf(false), now(false);
        int a(0), b(0), tmp(0);
        int i(0), j(0);
        int n(equation.size());

        for (i = 0; i < n; ++i)
        {
            now = (flag != eqRight);
            switch (equation[i])
            {
                case 'x':
                    if (!xconf && tmp == 0) tmp = 1;
                    if (now) a += tmp;
                    else a -= tmp;
                    tmp = 0;
                    xconf = false;
                    break;
                case '+':
                    if (now) b += tmp;
                    else b -= tmp;
                    flag = true;
                    tmp = 0;
                    xconf = false;
                    break;
                case '-':
                    if (now) b += tmp;
                    else b -= tmp;
                    flag = false;
                    tmp = 0;
                    xconf = false;
                    break;
                case '=':
                    if (now) b += tmp;
                    else b-= tmp;
                    flag = true;
                    eqRight = true;
                    tmp = 0;
                    xconf = false;
                    break;
                default:
                    tmp = tmp * 10 + equation[i] - '0';
                    xconf = true;
            }
            //cout << a << ' ' << b << ' ' << tmp << ' ' << now << endl;
        }
        if (now) b += tmp;
        else b -= tmp;
        //cout << a << ' ' << b << endl;
        if (a == 0) return b == 0 ? INF_RET : NORES_RET;
        res.append(to_string((-b) / a));
        return res;
    }
};
// @lc code=end

