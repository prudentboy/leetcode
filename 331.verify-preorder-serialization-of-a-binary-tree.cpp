/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return true;

        int cap(1);
        preorder.append(",");
        for (int i(0); i < preorder.size(); ++i)
        {
            if (preorder[i] != ',') continue;
            if (--cap < 0) return false;
            if (preorder[i - 1] != '#') cap += 2;
        }

        return cap == 0;
    }
};

