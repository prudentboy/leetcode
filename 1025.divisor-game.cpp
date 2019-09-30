/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 */
class Solution {
public:
    bool divisorGame(int N) {
        return (N & 1) == 0;
    }
};

