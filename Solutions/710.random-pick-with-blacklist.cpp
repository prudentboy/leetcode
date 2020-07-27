/*
 * @lc app=leetcode id=710 lang=cpp
 *
 * [710] Random Pick with Blacklist
 */

// @lc code=start
class Solution {
public:
    Solution(int N, vector<int>& blacklist) : high_(N - blacklist.size()) {
        srand(time(nullptr));

        int idx(high_);
        unordered_set<int> ust(blacklist.begin(), blacklist.end());
        for (int black : blacklist) {
            if (black < high_) {
                while (ust.count(idx) > 0) { ++idx; }
                black_maps_[black] = idx++;
            }
        }
    }
    
    int pick() {
        int candidate(rand() % high_);
        if (black_maps_.count(candidate) > 0) {
            candidate = black_maps_[candidate];
        }
        return candidate;
    }

private:
    int high_;
    unordered_map<int, int> black_maps_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

