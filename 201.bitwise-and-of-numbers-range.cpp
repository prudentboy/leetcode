/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int tmp(0);
        while (m != n)
        {
            ++tmp;
            m >>= 1; 
            n >>= 1;
        }
        return (m << tmp);
    }
};

