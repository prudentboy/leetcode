/*
 * @lc app=leetcode id=949 lang=cpp
 *
 * [949] Largest Time for Given Digits
 */
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        if (A.size() != 4) return {};
        sort(A.begin(), A.end());
        //printVec(A);

        bool has_answer(false);
        int hour(23), min(59);
        vector<int> tmp(4, 0);

        while (hour >= 0)
        {
            min = 59;
            while (min >= 0)
            {
                tmp[0] = hour / 10 % 10;
                tmp[1] = hour % 10;
                //cout << hour << ':' << min << endl;
                tmp[2] = min / 10 % 10;
                tmp[3] = min % 10;
                //printVec(tmp);
                sort(tmp.begin(), tmp.end());
                if (A == tmp) return {hour / 10 % 10 + '0', hour % 10 + '0', ':', min / 10 % 10 + '0', min % 10 + '0'};
                --min;
            }
            --hour;
        }

        return {};
    }
private:
    void printVec(const vector<int>& v)
    {
        cout << v[0] << v[1] << ' ' << v[2] << v[3] << endl;
    }
};

