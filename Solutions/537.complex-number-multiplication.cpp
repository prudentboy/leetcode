/*
 * @lc app=leetcode id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 */

// @lc code=start
class Solution {
    using complex = pair<int, int>;
public:
    string complexNumberMultiply(string a, string b) {
        complex c1(strToComplex(a)), c2(strToComplex(b));
        return complexToStr(complexMultiply(c1, c2));
    }
private:
    complex complexMultiply(const complex& c1, const complex& c2)
    {
        int real(c1.first * c2.first - c1.second * c2.second);
        int imag(c1.first * c2.second + c1.second * c2.first);
        return {real, imag};
    }
    complex strToComplex(const string& str)
    {
        size_t before(str.find('+'));
        int real = stoi(str.substr(0, before));
        int imag = stoi(str.substr(before + 1));
        return {real, imag};
    }
    string complexToStr(const complex& comp)
    {
        return to_string(comp.first).append("+").append(to_string(comp.second)).append("i");
    }
};
// @lc code=end

