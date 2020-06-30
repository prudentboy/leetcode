/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */

// @lc code=start
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int n(nums.size());
        vector<bool> visited(n, false);

        int index(0), next(0);
        for (int i(0); i < n; ++i)
        {
            if (visited[i]) continue;
            visited[i] = true;

            vector<bool> inner(n, false);
            index = i;
            inner[i] = true;
            while (true)
            {
                next = ((index + nums[index]) % n + n) % n;
                if (index == next) break;
                if (nums[index] * nums[next] < 0) break;
                if (inner[next]) return true;
                visited[next] = true;
                inner[next] = true;
                //cout << index << ':' << nums[index] << ' ' << next << ':' << nums[next] << endl;
                index = next;
            }
        }
        return false;
    }
};
// @lc code=end

