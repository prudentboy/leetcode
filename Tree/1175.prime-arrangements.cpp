/*
 * @lc app=leetcode id=1175 lang=cpp
 *
 * [1175] Prime Arrangements
 */

// @lc code=start
class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<int> primeList({2, 3});
        int pCnt(0), cCnt(0);
        long long int ans(1);
        for (int i = 1; i <= n; ++i) {
            ans *= isPrime(i, primeList) ? ++pCnt : ++cCnt;
            ans %= 1000000007;
        }
        //cout << pCnt << ' ' << cCnt << endl;
        return ans;
    }
private:
    bool isPrime(int n, vector<int>& primeList) {
        if (n <= 1) { return false; }
        if (n == 2 || n == 3) { return true; }
        for (int i = 0; i < primeList.size() && primeList[i] <= sqrt(n); ++i) {
            if (n % primeList[i] == 0) { return false; }
        }
        //cout << n << endl;
        primeList.push_back(n);
        return true;
    }
};
// @lc code=end

