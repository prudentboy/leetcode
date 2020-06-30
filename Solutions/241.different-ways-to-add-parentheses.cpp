/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;

        char op(0);
        string lstr, rstr;
        lstr.reserve(input.size());
        rstr.reserve(input.size());
        for (int i(0); i < input.size(); ++i)
        {
            op = input[i];
            if (op == '+' || op == '-' || op == '*')
            {
                lstr = input.substr(0, i);
                rstr = input.substr(i + 1);
                vector<int> left(diffWaysToCompute(lstr));
                vector<int> right(diffWaysToCompute(rstr));
                for (int l(0); l < left.size(); ++l)
                {
                    for (int r(0); r < right.size(); ++r)
                    {
                        //cout << left[l] << ' ' << right[r] << endl;
                        ans.push_back(cal(left[l], right[r], op));
                    }
                }
            }
        }
        if (ans.empty()) ans.push_back(stoi(input));
        return ans;
    }
private:
    int cal(int a, int b, char op)
    {
        switch (op)
        {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            default: return 0;
        }
        return 0;
    }
};

