/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 */

// @lc code=start
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        if (A.empty()) return true;

        map<int, int> m;
        for (int n : A) ++m[n];

        for (auto& p : m)
        {
            //cout << p.first << ' ' << p.second << endl;
            if (p.second == 0) continue;
            if (p.first == 0)
            {
                if ((p.second & 1) == 1) return false;
                p.second = 0;
            }
            else if (p.first < 0)
            {
                if ((p.first & 1) == 1) return false;
                if (m.count(p.first / 2) == 0) return false;
                if (m[p.first / 2] < p.second) return false;
                m[p.first / 2] -= p.second;
                p.second = 0;
            }
            else
            {
                if (m.count(p.first << 1) == 0) return false;
                if (m[p.first << 1] < p.second) return false;
                m[p.first << 1] -= p.second;
                p.second = 0;
            }
        }

        int sum(0);
        for (auto& p : m) sum += p.second;
        
        return sum == 0;
    }
};
// @lc code=end

