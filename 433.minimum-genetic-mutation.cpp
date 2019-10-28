/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        
        if (dict.count(end) == 0) return -1;
        if (start == end) return 0;

        const char gens[4] = {'A', 'T', 'G', 'C'};

        unordered_map<string, int> m;
        queue<pair<string, int>> q;
        q.push({start, 0});
        m[start] = 0;
        pair<string, int> tmp;
        char c('A');
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            //cout << tmp.first << ' ' << tmp.second << endl;
            for (int i(0); i < tmp.first.size(); ++i)
            {
                c = tmp.first[i];
                for (int j(0); j < 4; ++j)
                {
                    if (gens[j] == c) continue;
                    tmp.first[i] = gens[j];
                    if (tmp.first == end) return tmp.second + 1;
                    if (dict.count(tmp.first) > 0)
                    {
                        if (m.count(tmp.first) == 0 || m[tmp.first] > tmp.second + 1)
                        {
                            q.push({tmp.first, tmp.second + 1});
                            m[tmp.first] = tmp.second + 1;
                        }
                    }
                    tmp.first[i] = c;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

