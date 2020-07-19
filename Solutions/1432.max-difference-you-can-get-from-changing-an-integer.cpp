/*
 * @lc app=leetcode id=1432 lang=cpp
 *
 * [1432] Max Difference You Can Get From Changing an Integer
 */

// @lc code=start
class Solution {
public:
    int maxDiff(int num) {
        string ori(to_string(num));

        int i(0), n(ori.size());
        char mxChange, mnChange;
        bool mnFound(false), mxFound(false);

        if (ori.front() != '1') {
            mnChange = ori.front();
            mnFound = true;
        }

        for (i = 0; i < n; ++i) {
            if (mxFound && mnFound) { break; }
            if (!mxFound) {
                if (ori[i] != '9') {
                    mxChange = ori[i];
                    mxFound = true;
                }
            }

            if (!mnFound) {
                if (i == 0) { continue;}
                if (ori[i] != '0' && ori[i] != ori.front()) {
                    mnChange = ori[i];
                    mnFound = true;
                }
            }
        }

        string mn(ori), mx(ori);
        if (mxFound) {
            for (char& c : mx) {
                if (c == mxChange) { c = '9'; }
            }
        }
        if (mnFound) {
            char z(mnChange == ori.front() ? '1' : '0');
            for (char& c : mn) {
                if (c == mnChange) { c = z; }
            }
        }

        return stoi(mx) - stoi(mn);
    }
};
// @lc code=end

