/*
 * @lc app=leetcode id=972 lang=cpp
 *
 * [972] Equal Rational Numbers
 */

// @lc code=start
class Solution {
struct RationalNum {
    RationalNum() : interger_(0), numerator_(0), denominator_(1) {}
    RationalNum(const string& str) : interger_(-1), numerator_(0), denominator_(1) {
        int num(0), len(0), nonrep(0), rep(0), m(0), n(0);
        for (char c : str) {
            switch (c) {
                case '.' :
                    interger_ = num;
                    num = len = 0;
                    break;
                case '(' :
                    nonrep = num;
                    m = len;
                    num = len = 0;
                    break;
                case ')' :
                    rep = num;
                    n = len;
                    num = 0;
                    break;
                default :
                    num = num * 10 + c - '0';
                    ++len;
            }
        }
        if (interger_ == -1) {
            interger_ = num;
        } else if (num > 0) {
            nonrep = num;
            m = len;
        }
        //cout << nonrep << ' ' << m << ';' << rep << ' ' << n << endl;

        if (nonrep == 0 && rep == 0) {
            numerator_ = 0;
            denominator_ = 1;
            return;
        }

        numerator_ = n > 0 ? nonrep * pow(10, n) + rep - nonrep : nonrep;
        denominator_ = n > 0 ? pow(10, m + n) - pow(10, m) : pow(10, m);
        //cout << interger_ << ' ' << numerator_ << ' ' << denominator_ << endl;

        function<int(int, int)> gcd = [&](int a, int b) -> int {
            if (a < b) { swap(a, b); }
            if (a % b == 0) { return b; }
            return gcd(b, a % b);
        };

        int gcdNum(gcd(numerator_, denominator_));
        numerator_ /= gcdNum;
        denominator_ /= gcdNum;
        if (numerator_ == denominator_) {
            ++interger_;
            numerator_ = 0;
        }
    }
    bool isSame(const RationalNum& rrn) {
        return interger_ == rrn.interger_ && numerator_ == rrn.numerator_ && denominator_ == rrn.denominator_;
    }
    void print() {
        cout << interger_ << ' ' << numerator_ << '/' << denominator_ << endl;
    }
    int interger_;
    int numerator_;
    int denominator_;
};
public:
    bool isRationalEqual(string S, string T) {
        RationalNum rns(S);
        RationalNum rnt(T);
        //rns.print();
        //rnt.print();
        return rns.isSame(rnt);
    }
};
// @lc code=end

