/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */
class Solution {
public:
    using line = array<long long int, 3>;
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 2) return points.size();

        int ans(0);
        set<line> line_set;
        line tmp;
        for (int i(0); i < points.size() - 1; ++i)
        {
            for (int j(i + 1); j < points.size(); ++j)
            {
                if (points[i][0] == points[j][0] and points[i][1] == points[j][1]) continue;
                getLine(points[i], points[j], tmp);
                line_set.insert(tmp);
            }
        }

        if (line_set.empty()) return points.size();

        int cnt(0);
        for (const auto& l : line_set)
        {
            cnt = 0;
            for (int i = 0; i < points.size(); ++i)
            {
                if (onLineCheck(l, points[i])) ++cnt;
            }
            if (cnt > ans) ans = cnt;
        }
        
        return ans;
    }
private:
    void getLine(const vector<int>& p1, const vector<int>& p2, line& l)
    {
        l[0] = p2[1] - p1[1];
        l[1] = p1[0] - p2[0];
        l[2] = (long long int)p2[0] * p1[1] - (long long int)p1[0] * p2[1];
        refineLine(l);
    }
    bool onLineCheck(const line& l, const vector<int>& p)
    {
        return p[0] * l[0] + p[1] * l[1] + l[2] == 0;
    }
    void refineLine(line& l)
    {
        refineSign(l);
        int common_gcd = gcd(l);
        l[0] /= common_gcd;
        l[1] /= common_gcd;
        l[2] /= common_gcd; 
    }
    void refineSign(line& l)
    {
        if (l[0] < 0)
        {
            l[0] = -l[0];
            l[1] = -l[1];
            l[2] = -l[2];
        }
        else if (l[0] == 0)
        {
            if (l[1] < 0)
            {
                l[1] = -l[1];
                l[2] = -l[2];
            }
        }
    }
    int gcd(int a, int b)
    {
        if (a == 0 or b == 0) return 1;
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        if (a < b) swap(a, b);
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
    int gcd(const line& l)
    {
        return gcd(gcd(l[0], l[1]), l[2]);
    }
};

