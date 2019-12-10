/*
 * @lc app=leetcode id=842 lang=cpp
 *
 * [842] Split Array into Fibonacci Sequence
 */

// @lc code=start
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        if (S.size() < 3) return {};
        int i(0), j(0), n(S.size());
        long long int first(0), second(0);
        vector<int> tmp;
        for (i = 0; i < n - 2; ++i) {
            first = first * 10 + S[i] - '0';
            if (first > INT_MAX) break;
            second = 0;
            for (j = i + 1; j < n - 1; ++j) {
                second = second * 10 + S[j] - '0';
                if (second > INT_MAX) break;
                if (checkFibo(S, j + 1, first, second, tmp)) return tmp;
                if (second == 0) break;
            }
            if (first == 0) break;
        }
        if (S[0] == '0') first = 0;
        return {};
    }
private:
    bool checkFibo(const string& S, long long int idx, long long int first, long long int second, vector<int>& v) {
        //cout << first << ' ' << second << endl;
        v.clear();
        v.push_back(first);
        v.push_back(second);
        string str;
        long long int pre(second), now(first + second), tmp(0);
        while (idx < S.size()) {
            if (now > INT_MAX) return false;
            str.assign(to_string(now));
            if (idx + str.size() > S.size()) return false;
            if (str != S.substr(idx, str.size())) return false;
            idx += str.size();
            v.push_back(now);
            tmp = now;
            now = pre + now;
            pre = tmp;
        }
        return idx == S.size();
    }
};
// @lc code=end

