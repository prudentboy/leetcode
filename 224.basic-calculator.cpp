/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */
class Solution {
public:
    int calculate(string s) {
        stack<int> st;

        long long int flag(1), num(0), ans(0);
        char c(0);

        for (int i(0); i < s.size(); ++i)
        {
            c = s[i];
            if (isdigit(c))
            {
                num = 0;
                while (i < s.size() && isdigit(s[i])) num = 10 * num + s[i++] - '0';
                ans += flag * num;
                --i;
            }
            else if (c == '+') flag = 1;
            else if (c == '-') flag = -1;
            else if (c == '(')
            {
                st.push(ans);
                st.push(flag);
                ans = 0;
                flag = 1;
            }
            else if (c == ')')
            {
                ans *= st.top();
                st.pop();
                ans += st.top();
                st.pop();
            }
            //cout << ans << endl;
        }

        return ans;
    }
};

