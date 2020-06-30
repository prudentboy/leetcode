/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        vector<double> ans(queries.size(), 0.0);
        
        unordered_map<string, unordered_map<string, double>> edges;
        for (int i(0); i < equations.size(); ++i)
        {
            vector<string>& equ = equations[i];
            edges[equ[0]][equ[1]] = values[i];
            edges[equ[1]][equ[0]] = 1.0 / values[i];
            //cout << equ[0] << '-' << equ[1] << endl;
            //cout << edges[equ[0]][equ[1]] << ' ' << edges[equ[1]][equ[0]] << endl;
        }

        unordered_set<string> visited;
        for (int i(0); i < queries.size(); ++i)
        {
            vector<string>& q = queries[i];
            ans[i] = calcEquation(q[0], q[1], edges);
        }

        return ans;
    }
private:
    double calcEquation(const string& before, const string& after, unordered_map<string, unordered_map<string, double>>& edges)
    {
        if (edges.count(before) == 0 || edges.count(after) == 0) return -1.0;
        if (before == after) return 1.0;
        
        double ans(1.0);
        unordered_set<string> visited;
        queue<pair<string, double>> q;
        pair<string, double> tmp;
        q.push({before, 1.0});

        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            //cout << tmp.first << ' ' << tmp.second << endl;
            if (visited.count(tmp.first) > 0) continue;
            visited.insert(tmp.first);

            //cout << edges[tmp.first].size() << endl;
            for (const auto& adj : edges[tmp.first])
            {
                //cout << "adj: " << adj.first << ' ' << adj.second << endl;
                if (visited.count(adj.first) > 0) continue;
                if (adj.first == after) return tmp.second * adj.second;
                q.push({adj.first, tmp.second * adj.second});
            }
        }

        return -1.0;
    }
};
// @lc code=end
