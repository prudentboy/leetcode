/*
 * @lc app=leetcode id=866 lang=cpp
 *
 * [866] Prime Palindrome
 */

// @lc code=start
class Solution {
public:
    int primePalindrome(int N) {
        if (N <= 2) return 2;
        if (N <= 3) return 3;
        if (N <= 5) return 5;
        if (N <= 7) return 7;
        if (N <= 11) return 11;

        string tmp, rev;
        int n(0);
        for (int i = 10; i < 2e5; ++i)
        {
            tmp = to_string(i);
            rev.assign(tmp);
            rev.pop_back();
            reverse(rev.begin(), rev.end());
            tmp.append(rev);
            n = stoi(tmp);
            if (n > N && isPrime(n)) return n;
        }
        return -1;
    }
private:
    bool isPrime(int n)
    {
        if (n <= 1) return false;
        for (int i(2); i <= sqrt(n); ++i)
            if (n % i == 0) return false;
        
        return true;
    }
};
// @lc code=end

