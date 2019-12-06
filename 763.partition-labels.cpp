/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.empty()) return {};
        
        vector<int> ans;
        int start(0), end(0), i(0);
        char c(S[0]);
        end = S.find_last_of(c);
        while (start < S.size()) {
            //cout << c << ' ' << i << ' ' << start << ' ' << end << endl;
            if (end <= i) {
                ans.push_back(end - start + 1);
                start = end + 1;
                if (start >= S.size()) break;
                c = S[start];
                end = S.find_last_of(c);
                continue;
            }
            for (i = start + 1; i < end; ++i) {
                //cout << i << ' ' << c << endl;
                if (S[i] == c) continue;
                c = S[i];
                if (S.find_last_of(c) <= end) continue;
                end = S.find_last_of(c);
            }
        }
        return ans;
    }
};
// @lc code=end

