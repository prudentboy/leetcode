/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> words;
        string tmp, ans;
        int max(0), begin(0), end(0);

        for (char& c : paragraph) c = isalpha(c) ? tolower(c) : ' ';
        istringstream iss(paragraph);
        while (iss >> tmp)
        {
            if (ban.count(tmp) > 0) continue;
            if (words.count(tmp) == 0) words[tmp] = 1;
            else ++words[tmp];
            if (words[tmp] > max)
            {
                max = words[tmp];
                ans = tmp;
            }
            //cout << tmp << endl;
        }
        /*
        while (end < paragraph.size())
        {
            if (isalpha(paragraph[end++]) && end != paragraph.size()) continue;
            tmp = end == paragraph.size() ? paragraph.substr(begin) : paragraph.substr(begin, end - begin - 1);
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            while (end < paragraph.size() && !isalpha(paragraph[end])) ++end;
            begin = end; 
            if (ban.count(tmp) > 0) continue;
            if (words.count(tmp) == 0) words[tmp] = 1;
            else ++words[tmp];
            if (words[tmp] > max)
            {
                max = words[tmp];
                ans = tmp;
            }
            //cout << tmp << ' ' << ans << ' ' << max << endl;
        }
        //tmp = paragraph.substr(begin, end - begin - 1);
        //transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        //if (ban.count(tmp) == 0 && words.find(tmp) != words.end() && words[tmp] >= max) return tmp;
        */
        return ans;
    }
};

