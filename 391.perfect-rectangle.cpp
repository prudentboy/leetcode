/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty() || rectangles[0].empty()) return false;

        int x1(0), x2(0), y1(0), y2(0);
        int minx1(INT_MAX), maxx2(INT_MIN), miny1(INT_MAX), maxy2(INT_MIN);
        int area(0);
        string ldown, lup, rdown, rup;
        unordered_set<string> s;

        for (const auto& rec : rectangles)
        {
            if (rec.size() != 4) return false;

            x1 = rec[0];
            y1 = rec[1];
            x2 = rec[2];
            y2 = rec[3];

            minx1 = min(minx1, x1);
            maxx2 = max(maxx2, x2);
            miny1 = min(miny1, y1);
            maxy2 = max(maxy2, y2);

            ldown.assign(to_string(x1)).append(",").append(to_string(y1));
            lup.assign(to_string(x1)).append(",").append(to_string(y2));
            rdown.assign(to_string(x2)).append(",").append(to_string(y1));
            rup.assign(to_string(x2)).append(",").append(to_string(y2));

            if (s.count(ldown) > 0) s.erase(ldown);
            else s.insert(ldown);
            if (s.count(lup) > 0) s.erase(lup);
            else s.insert(lup);
            if (s.count(rdown) > 0) s.erase(rdown);
            else s.insert(rdown);
            if (s.count(rup) > 0) s.erase(rup);
            else s.insert(rup);

            area += (x2 - x1) * (y2 - y1);
        }

        if (s.size() != 4) return false;

        ldown.assign(to_string(minx1)).append(",").append(to_string(miny1));
        lup.assign(to_string(minx1)).append(",").append(to_string(maxy2));
        rdown.assign(to_string(maxx2)).append(",").append(to_string(miny1));
        rup.assign(to_string(maxx2)).append(",").append(to_string(maxy2));        
        if (s.count(ldown) == 0) return false;
        if (s.count(lup) == 0) return false;
        if (s.count(rdown) == 0) return false;
        if (s.count(rup) == 0) return false;

        return area == (maxx2 - minx1) * (maxy2 - miny1);
    }
};
// @lc code=end

