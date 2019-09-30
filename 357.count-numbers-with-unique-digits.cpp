/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> ans{1,10,91,739,5275,32491,168571,712891,2345851,5611771,887769};
        if (n < 0) return 0;
        if (n >= ans.size()) return ans.back();
        return ans[n];
    }
private:
    inline vector<int> getAnsVec()
    {
        vector<int> ans(11, 0);
        ans[0] = 1;
        ans[1] = 9;
        for (int i(2); i < 11; ++i)
        {
            ans[i] = ans[i - 1] * (11 - i);
        }
        //for (const auto n : ans) cout << n << ' ';
        //cout << endl;
        for (int i(1); i < 11; ++i) ans[i] += ans[i - 1];
        //for (const auto n : ans) cout << n << ',';
        //cout << endl;
        return ans;
    }
};

