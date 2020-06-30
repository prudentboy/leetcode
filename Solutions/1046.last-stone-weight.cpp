/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> priq;

        for (int stone : stones) { priq.push(stone); }

        int one(0), another(0);
        while (priq.size() > 1) {
            one = priq.top();
            priq.pop();
            another = priq.top();
            priq.pop();
            if (one == another) { continue; }
            priq.push(abs(one - another));
        }
        if (priq.empty()) { return 0; }
        return priq.top();
    }
};
// @lc code=end

