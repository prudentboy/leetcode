/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead_dict(deadends.begin(), deadends.end());
        string now, tmp;
        if (dead_dict.count("0000") > 0) return -1;

        queue<string> q;
        unordered_map<string, int> m;
        q.push("0000");
        m["0000"] = 0;
        while (!q.empty()) {
            now.assign(q.front());
            q.pop();
            //cout << now << ':' << m[now] << endl; 
            if (now == target) return m[now];

            tmp.assign(now);

            tmp[0] = (tmp[0] - '0' + 1) % 10 + '0';
            if (dead_dict.count(tmp) == 0 && m.count(tmp) == 0) {
                m[tmp] = m[now] + 1;
                q.push(tmp);
            }
            tmp[0] = now[0];
            tmp[0] = (tmp[0] - '0' + 9) % 10 + '0';
            if (dead_dict.count(tmp) == 0 && m.count(tmp) == 0) {
                m[tmp] = m[now] + 1;
                q.push(tmp);
            }
            tmp[0] = now[0];
            tmp[1] = (tmp[1] - '0' + 1) % 10 + '0';
            if (dead_dict.count(tmp) == 0 && m.count(tmp) == 0) {
                m[tmp] = m[now] + 1;
                q.push(tmp);
            }
            tmp[1] = now[1];
            tmp[1] = (tmp[1] - '0' + 9) % 10 + '0';
            if (dead_dict.count(tmp) == 0 && m.count(tmp) == 0) {
                m[tmp] = m[now] + 1;
                q.push(tmp);
            }
            tmp[1] = now[1];
            tmp[2] = (tmp[2] - '0' + 1) % 10 + '0';
            if (dead_dict.count(tmp) == 0 && m.count(tmp) == 0) {
                m[tmp] = m[now] + 1;
                q.push(tmp);
            }
            tmp[2] = now[2];
            tmp[2] = (tmp[2] - '0' + 9) % 10 + '0';
            if (dead_dict.count(tmp) == 0 && m.count(tmp) == 0) {
                m[tmp] = m[now] + 1;
                q.push(tmp);
            }
            tmp[2] = now[2];
            tmp[3] = (tmp[3] - '0' + 1) % 10 + '0';
            if (dead_dict.count(tmp) == 0 && m.count(tmp) == 0) {
                m[tmp] = m[now] + 1;
                q.push(tmp);
            }
            tmp[3] = now[3];
            tmp[3] = (tmp[3] - '0' + 9) % 10 + '0';
            if (dead_dict.count(tmp) == 0 && m.count(tmp) == 0) {
                m[tmp] = m[now] + 1;
                q.push(tmp);
            }
            tmp[3] = now[3];
        }

        return -1;
    }
};
// @lc code=end

