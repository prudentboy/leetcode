/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> m;
        for (const vector<string>& ticket : tickets) m[ticket[0]].insert(ticket[1]);

        string tmp;
        vector<string> ans;
        ans.reserve(tickets.size() + 1);
        stack<string> q;
        q.push("JFK");

        while (!q.empty())
        {
            tmp = q.top();
            if (m[tmp].empty())
            {
                ans.push_back(tmp);
                q.pop();
            }
            else
            {
                q.push(*m[tmp].begin());
                m[tmp].erase(m[tmp].begin());
            }
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

