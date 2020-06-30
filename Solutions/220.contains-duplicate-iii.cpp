/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty() || k < 0) return false;

        multiset<long long int> tree;
        auto iter = tree.lower_bound(0);
        for (int i(0); i < nums.size(); ++i)
        {
            if (i > k) tree.erase(nums[i - k - 1]);
            //cout << nums.size() << endl;
            iter = tree.lower_bound((long long int)nums[i] - t);
            if (iter != tree.end() && abs(*iter - nums[i]) <= t) return true;
            tree.insert(nums[i]);
        }

        return false;
    }
};

