/*
 * @lc app=leetcode id=591 lang=cpp
 *
 * [591] Tag Validator
 */

// @lc code=start
class Solution {
public:
    bool isValid(string code) {
        const string FinalStr("final");
        if (code == FinalStr) { return false; }

        // dealt with cdata
        regex cdata("<!\\[CDATA\\[.*?\\]\\]>");
        code = regex_replace(code, cdata, "cdata");

        // dealt with tag
        regex tag("<([A-Z]{1,9})>[^<]*</\\1>");
        string pre(code);
        while (pre != (code = regex_replace(code, tag, "final"))) { pre = code; }

        return code == FinalStr;
    }
};
// @lc code=end

