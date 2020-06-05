/*
 * @lc app=leetcode id=1170 lang=cpp
 *
 * [1170] Compare Strings by Frequency of the Smallest Character
 */

// @lc code=start
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans(queries.size(), 0);
        vector<int> qFreq(queries.size(), 0), wFreq(words.size(), 0);

        int i(0);
        for (i = 0; i < qFreq.size(); ++i) { qFreq[i] = freqOfSmallestChar(queries[i]); }
        for (i = 0; i < wFreq.size(); ++i) { wFreq[i] = freqOfSmallestChar(words[i]); }

        int j(0);
        for (i = 0; i < qFreq.size(); ++i) {
            //cout << qFreq[i] << endl;
            for (j = 0; j < wFreq.size(); ++j) {
                //cout << wFreq[j] << endl;
                if (wFreq[j] > qFreq[i]) { ++ans[i]; }
            }
        }

        return ans;
    }
private:
    int freqOfSmallestChar(const string& s) {
        if (s.empty()) { return 0; }
        int cnt(1);
        char small(s.front());
        for (int i(1); i < s.size(); ++i) {
            if (s[i] == small) {
                ++cnt;
            } else if (s[i] < small) {
                small = s[i];
                cnt = 1; 
            }
        }
        return cnt;
    }
};
// @lc code=end

