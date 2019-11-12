/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (52.71%)
 * Likes:    876
 * Dislikes: 52
 * Total Accepted:    63.8K
 * Total Submissions: 121K
 * Testcase Example:  '[1,2,1]'
 *
 * 
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element. The
 * Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this
 * number.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; The number 2 can't find
 * next greater number; The second 1's next greater number needs to search
 * circularly, which is also 2.
 * 
 * 
 * 
 * Note:
 * The length of given array won't exceed 10000.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return {};
        if (nums.size() == 1) return {-1};

        size_t i(0), n(nums.size());
        vector<int> ans(n, -1);
        stack<size_t> st;
        int num(0);
        for (i = 0; i < (n << 1); ++i)
        {
            num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num)
            {
                ans[st.top()] = num;
                st.pop();
            }
            if (i < n) st.push(i);
        }

        return ans;
    }
};
// @lc code=end

