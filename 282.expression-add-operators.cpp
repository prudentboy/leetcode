/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        addOperators(num, target, 0, 0, "", ans);
        return ans;
    }
private:
    void addOperators(string num, int target, long long int pre, long long int cur, string now, vector<string>& ans)
    {
        //cout << num << ' ' << target << ' ' << pre << ' ' << cur << ' ' << now << endl;
        if (num.empty() && cur == target)
        {
            ans.push_back(now);
            //cout << "bingo! " << now << endl;
            return;
        }
        long long int p(0);
        string l, r;
        for (int i(1); i <= num.size(); ++i)
        {
            l = num.substr(0,i);
            if (l.size() > 1 && l[0] == '0') return;
            r = num.substr(i);
            p = stoll(l);
            if (now.empty())
            {
                addOperators(r, target, p, p, l, ans);
            }
            else
            {
                addOperators(r, target, p, cur + p, now + "+" + l, ans);
                addOperators(r, target, -p, cur - p, now + "-" + l, ans);
                addOperators(r, target, pre * p, cur - pre + pre * p, now + "*" + l, ans);
            }
        }
    }
};

