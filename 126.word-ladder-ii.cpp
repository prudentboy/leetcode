/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.count(endWord) == 0) return ans;

        vector<string> path;
        path.push_back(beginWord);
        if (beginWord == endWord)
        {
            ans.push_back(path);
            return ans;
        }
        
        unordered_map<string, vector<vector<string>>> table;
        unordered_map<string, int> level_map;
        queue<string> q;
        vector<vector<string>> paths(1,path), tmp;
        table[beginWord] = paths;
        level_map[beginWord] = 1;
        q.push(beginWord);

        string now;
        char c;
        int level(0);
        
        while (!q.empty())
        {
            now = q.front();
            q.pop();
            tmp = table[now];
            level = level_map[now];
            //cout << now << ' ' << q.size() << ' ' << table[now].size() << ' ' << level << ' ';
            //printVecVec(tmp);
            paths.clear();
            for (int i(0); i < now.size(); ++i)
            {
                c = now[i];
                for (char j('a'); j <= 'z'; ++j)
                {
                    if (j == c) continue;
                    now[i] = j;
                    if (dict.count(now) == 0) continue;
                    if (table.find(now) == table.end())
                    {
                        paths.clear();
                        for (const auto& t : tmp)
                        {
                            vector<string> p(t);
                            p.push_back(now);
                            paths.push_back(p);
                        }
                        table[now] = paths;
                        level_map[now] = level + 1;
                        //cout << "add " << now << endl;
                    }
                    else
                    {
                        paths.clear();
                        //cout << "**" << level << now << level_map[now] << "**" << endl;
                        if (level_map[now] <= level) continue;
                        const vector<vector<string>>& tx = table[now];
                        for (const auto& t : tx)
                        {
                            vector<string> p(t);
                            if (find(t.begin(), t.end(), now) == t.end()) p.push_back(now);
                            paths.push_back(p);
                        }
                        for (const auto& t : tmp)
                        {
                            vector<string> p(t);
                            if (find(t.begin(), t.end(), now) == t.end()) p.push_back(now);
                            paths.push_back(p);
                        }
                        table[now] = paths;
                        level_map[now] = level + 1;
                        //cout << "addb " << now << endl;
                    }
                    q.push(now);
                }
                now[i] = c;
            }
        }
        if (table.find(endWord) != table.end()) return table[endWord];
        return ans;
    }
private:
    void printVec(const vector<string>& v)
    {
        for (const string& s : v) cout << s << '-';
        cout << endl;
    }
    void printVecVec(const vector<vector<string>> vv)
    {
        for (int i(0); i < vv.size(); ++i)
        {
            cout << i << ':';
            printVec(vv[i]);
        }
    }
};

