/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */
class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() < 2) return chars.size();
        int now(1), cnt(1);
        char c(chars[0]);
        string num_s;

        for (int i(1); i < chars.size(); ++i)
        {
            if (chars[i] != c)
            {
                c = chars[i];
                addNumber(chars, now, cnt);
                chars[now++] = c;
                cnt = 1;
            }
            else
            {
                ++cnt;
            }
        }
        addNumber(chars, now, cnt);

        return now;
    }
private:
    void addNumber(vector<char>& chars, int& now, int cnt)
    {
        if (cnt <= 1) return;
        string tmp(to_string(cnt));
        for (char c : tmp) chars[now++] = c;
    }
};

