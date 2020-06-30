/*
 * @lc app=leetcode id=1311 lang=cpp
 *
 * [1311] Get Watched Videos by Your Friends
 */

// @lc code=start
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, \
    vector<vector<int>>& friends, int id, int level) {
        int n(friends.size());
        vector<bool> visited(n, false);

        int depth(0);
        queue<int> q;
        q.push(id);
        int len(0), person(0);
        visited[id] = true;

        while (!q.empty()) {
            if (depth == level) { break; }
            len = q.size();
            while (len-- > 0) {
                person = q.front();
                q.pop();
                for (int fri : friends[person]) {
                    if (visited[fri]) { continue; }
                    q.push(fri);
                    visited[fri] = true;
                }
            }
            ++depth;
        }

        unordered_map<string, int> ump;
        vector<set<string>> v(q.size() + 1);
        while (!q.empty()) {
            person = q.front();
            q.pop();
            for (string& video : watchedVideos[person]) { ++ump[video]; }
        }

        for (auto& p : ump) { v[p.second].insert(p.first); }

        vector<string> ans;
        for (auto& st : v) {
            if (!st.empty()) { for (auto& str : st) { ans.push_back(str); } }
        }
        return ans;
    }
};
// @lc code=end

