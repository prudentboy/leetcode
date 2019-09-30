/*
 * @lc app=leetcode id=878 lang=cpp
 *
 * [878] Nth Magical Number
 */

// @lc code=start
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long long int g(gcd(A, B)), l((long long int)(A * B) / g);
        long long int low(N), high((long long int)(N) * min(A, B)), mid(0);
        long long int M(1e9 + 7);

        while (low < high)
        {
            mid = low + ((high - low) >> 1);
            //cout << low << ' ' << mid << ' ' << high << endl;
            if (mid / A + mid / B - mid / l < N) low = mid + 1;
            else high = mid;
        }

        return high % M;
    }
private:
    int gcd(int a, int b)
    {
        if (a < b) return gcd(b, a);
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
};
// @lc code=end

