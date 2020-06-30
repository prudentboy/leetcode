/*
 * @lc app=leetcode id=982 lang=cpp
 *
 * [982] Triples with Bitwise AND Equal To Zero
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int>& A) {
        int ans(0);

        unordered_map<int, int> ump;
        for (int i : A) {
            for (int j : A) { ++ump[i & j]; }
        }

        for (int k : A) {
            for (auto& p : ump) {
                if ((k & p.first) == 0) { ans += p.second; }
            }
        }
        
        return ans;
    }
};
// @lc code=end

