/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        //cout << s << endl;
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));
        if (s.size() < 3) return NestedInteger();

        int cnt(0), start(1);
        NestedInteger ans;
        for (int i = 1; i < s.size(); ++i)
        {
            if (cnt == 0 && (s[i] == ',' || s[i] == ']'))
            {
                ans.add(deserialize(s.substr(start, i - start)));
                start = i + 1;
            }
            else if (s[i] == '[') ++cnt;
            else if (s[i] == ']') --cnt;
        }
        return ans;
    }
};
// @lc code=end

