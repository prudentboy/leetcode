/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */
class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;

        int ans(0), len(0), bit(0);
        while (N != 0)
        {
            bit = (N & 1);
            if (bit == 0) ans |= (1 << len);

            N >>= 1;
            ++len;
        }
        
        return ans;
    }
};

