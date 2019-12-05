/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution {
public:
    string reorganizeString(string S) {
        int n(S.size()), mx(0);
        array<int, 26> arr = {0};
        for (char c : S){
            ++arr[c - 'a'];
            mx = max(mx, arr[c - 'a']);
        }
        if (mx > n / 2 + n % 2) return "";
        if (mx == 1) return S;
        
        int i(0);
        multimap<int, char> m;
        for (i = 0; i < 26; ++i) {
            if (arr[i] > 0) {
                m.insert(make_pair(arr[i], i + 'a'));
            }
        }

        i = 0;
        int cnt(0);
        string ans(n, 0);
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            cnt = it->first;
            while (cnt-- > 0) {
                if (ans[i] != 0) i = (i + 1) % n;
                ans[i] = it->second;
                i = (i + 2) % n;
            }
        }
        return ans;
    }
};
// @lc code=end

