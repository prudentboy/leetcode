/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
 */

// @lc code=start
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<long long int> s;
        s.insert(disCount(p1, p2));
        s.insert(disCount(p1, p3));
        s.insert(disCount(p1, p4));
        s.insert(disCount(p3, p2));
        s.insert(disCount(p4, p2));
        s.insert(disCount(p3, p4));
        return s.count(0) == 0 && s.size() == 2;
    }
private:
    long long int disCount(const vector<int>& a, const vector<int>& b)
    {
        return (long long int)(a[0] - b[0]) * (a[0] - b[0]) + (long long int)(a[1] - b[1]) * (a[1] - b[1]);
    }
};
// @lc code=end

