/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;

        vector<vector<int>> arr(buildings.size() * 2, vector<int>(2, 0));
        for (int i(0); i < buildings.size(); ++i)
        {
            arr[2 * i][0] = buildings[i][0];
            arr[2 * i][1] = -buildings[i][2];
            arr[2 * i + 1][0] = buildings[i][1];
            arr[2 * i + 1][1] = buildings[i][2];
        }
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {if(a[0] == b[0]) return a[1] < b[1]; return a[0] < b[0];});

        multiset<int> ms;
        ms.insert(0);
        int h(0), ph(0);
        for (const vector<int>& a : arr)
        {
            if (a[1] < 0) ms.insert(-a[1]);
            else ms.erase(ms.find(a[1]));
            h = *(ms.rbegin());
            if (h == ph) continue;
            ans.push_back(vector<int>({a[0], h}));
            ph = h;
        }

        return ans;
    }
};

