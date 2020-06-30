/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.count(endWord) == 0) return 0;
        if (beginWord == endWord) return 1;
        unordered_map<string, int> table;
        table[beginWord] = 1;
        queue<string> q;
        q.push(beginWord);

        string now;
        char c;
        int cnt;
        while (!q.empty())
        {
            now = q.front();
            cnt = table[now];
            q.pop();
            for (int i(0); i < now.size(); ++i)
            {
                c = now[i];
                for (int j(0); j < 26; ++j)
                {
                    now[i] = 'a' + j;
                    if (now[i] == c) continue;
                    if (dict.count(now) > 0)
                    {
                        if (now == endWord) return cnt + 1;
                        if (table.find(now) == table.end())
                        {
                            table[now] = cnt + 1;
                            q.push(now);
                        }
                    }
                    now[i] = c;
                }
            }
        }
        return 0;
    }
};

