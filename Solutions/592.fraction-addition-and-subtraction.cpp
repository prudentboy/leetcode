/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 */

// @lc code=start
class Solution {
public:
    string fractionAddition(string expression) {
        frac ans, tmp;
        size_t pre(0);
        size_t pos(expression.find_first_of("+-"));
        char op('+');
        while (pos != string::npos)
        {
            if (pos != pre)
            { 
                //ans.print();
                tmp = strToFrac(expression.substr(pre, pos - pre));
                //tmp.print();
                //cout << op << endl;
                if (op == '+') ans = addFrac(ans, tmp);
                else ans = minusFrac(ans, tmp);
                op = expression[pos];
                //ans.print();
                pre = pos + 1;
            }
            pos = expression.find_first_of("+-", pos + 1);
        }
        tmp = strToFrac(expression.substr(pre));
        if (op == '+') ans = addFrac(ans, tmp);
        else ans = minusFrac(ans, tmp);
        //ans.print();

        return ans.toStr();
    }
private:
    struct frac
    {
        int nume;
        int deno;

        frac() : nume(0), deno(1) {}
        frac(int n, int d) : nume(n), deno(d) {}
        frac(const string& s) : deno(1) { 
            size_t pos(s.find_first_of('/'));
            if (pos == string::npos)
            {
                nume = stoi(s);
                return;
            }
            nume = stoi(s.substr(0, pos));
            deno = stoi(s.substr(pos + 1));
            adjust();
        }
        ~frac() {}
        void print()
        {
            cout << nume << '/' << deno << endl;
        }
        void adjust()
        {
            if (deno == 0) deno = 1;
            if (deno < 0)
            {
                nume = -nume;
                deno = -deno;
            }
            int com = gcd(abs(nume), abs(deno));
            if (com > 1)
            {
                nume /= com;
                deno /= com;
            }
        }
        string toStr()
        {
            return to_string(nume).append("/").append(to_string(deno));
        }
        int gcd(int a, int b)
        {
            if (a % b == 0) return b;
            return gcd(b, a % b);
        }
    };
    frac strToFrac(const string& str)
    {
        frac ans(str);
        return ans;
    }
    frac addFrac(const frac& a, const frac& b)
    {
        frac ans;
        ans.deno = a.deno * b.deno;
        ans.nume = a.nume * b.deno + b.nume * a.deno;
        ans.adjust();
        return ans; 
    }
    frac minusFrac(const frac& a, const frac& b)
    {
        frac ans;
        ans.deno = a.deno * b.deno;
        ans.nume = a.nume * b.deno - b.nume * a.deno;
        ans.adjust();
        return ans; 
    }
};
// @lc code=end

