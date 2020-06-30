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

        vector<string> path, tmp;
        path.push_back(beginWord);
        if (beginWord == endWord)
        {
            ans.push_back(path);
            return ans;
        }
        
        queue<vector<string>> q;
        unordered_set<string> toDel;
        q.push(path);

        string now;
        char c;
        int level(1), levelMin(INT_MAX);
        
        while (!q.empty())
        {
            path = q.front();
            q.pop();
            if (path.size() > level)
            {
                for (const auto& s : toDel) dict.erase(s);
                toDel.clear();
                level = path.size();
                if (level > levelMin) break;
            }
            //printVec(path);
            now = path.back();
            for (int i(0); i < now.size(); ++i)
            {
                c = now[i];
                for (char j('a'); j <= 'z'; ++j)
                {
                    if (j == c) continue;
                    now[i] = j;
                    if (dict.count(now) == 0) continue;
                    toDel.insert(now);
                    tmp = path;
                    tmp.push_back(now);
                    if (now == endWord)
                    {
                        ans.push_back(tmp);
                        levelMin = level;
                    }
                    else
                    {
                        q.push(tmp);
                    }
                }
                now[i] = c;
            }
        }
        //printVecVec(ans);
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

