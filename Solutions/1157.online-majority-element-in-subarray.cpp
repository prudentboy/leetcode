/*
 * @lc app=leetcode id=1157 lang=cpp
 *
 * [1157] Online Majority Element In Subarray
 */

// @lc code=start
class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        for (int i(0); i < arr.size(); ++i) { idxs_[arr[i]].push_back(i); }
        for (auto& p : idxs_) { freq_.push_back({p.second.size(), p.first}); }
        sort(freq_.rbegin(), freq_.rend());
    }
    
    int query(int left, int right, int threshold) {
        for (auto& p : freq_) {
            if (p.first < threshold) { return -1; }
            int cnt(upper_bound(idxs_[p.second].begin(), idxs_[p.second].end(), right) - \
                    lower_bound(idxs_[p.second].begin(), idxs_[p.second].end(), left));
            if (cnt >= threshold) { return p.second; }
        }
        return -1;
    }

private:
    unordered_map<int, vector<int>> idxs_;
    vector<pair<int, int>> freq_;
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
// @lc code=end

