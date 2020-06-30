/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int max(-1);
        unordered_map<size_t, int> m;
        for (int n : nums)
        {
            if (m.count(n) == 0) m[n] = 1;
            else ++m[n];

            if (m[n] > max) max = m[n];
        }

        vector<vector<int>> bucket(max);
        for (const auto& pair : m) bucket[pair.second - 1].push_back(pair.first);

        vector<int> ans(k, 0);
        int j(0);
        for (int i(max - 1); i >= 0, j < k; --i)
        {
            if (!bucket[i].empty())
            {
                for (int n : bucket[i]) 
                {
                    if (j < k) ans[j++] = n;
                } 
            }
        }

        return ans;
    }
};

