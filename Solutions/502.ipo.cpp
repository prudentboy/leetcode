/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        /*
        if (k == 0) { return 0; }

        int ans(W);
        int i(0), j(0), n(Profits.size());
        vector<pair<int, int>> take(n, {k, W}), jump(n, {k, W});

        if (W >= Capital[0]) { take[0] = {k - 1, W + Profits[0]}; }
        ans = max(ans, take[0].second);
        //cout << i << ':' << take[i].first << '-' << take[i].second << '|';
        //cout << jump[i].first << '-' << jump[i].second << ' ' << ans << endl;
        for (i = 1; i < n; ++i) {
            for (j = 0; j < i; ++j) {
                // find max take i from j
                if (take[j].first > 0 && take[j].second >= Capital[i] && \
                    (take[j].second + Profits[i] > take[i].second || \
                     (take[j].second + Profits[i] == take[i].second && take[j].first - 1 > take[i].first))) {
                    //cout << j << "take1 : " << take[j].first << ' ' << take[j].second << endl; 
                    take[i].first = take[j].first - 1;
                    take[i].second = take[j].second + Profits[i];
                }
                if (jump[j].first > 0 && jump[j].second >= Capital[i] && \
                    (jump[j].second + Profits[i] > take[i].second || \
                     (jump[j].second + Profits[i] == take[i].second && jump[j].first - 1 > take[i].first))) {
                    //cout << j << "take2 : " << take[j].first << ' ' << take[j].second << endl; 
                    take[i].first = jump[j].first - 1;
                    take[i].second = jump[j].second + Profits[i];
                }
                // find max jump i from j
                if (take[j].second > jump[i].second || \
                    (take[j].second == jump[i].second && take[j].first > jump[i].first)) {
                    //cout << j << "jump1 : " << take[j].first << ' ' << take[j].second << endl; 
                    jump[i].first = take[j].first;
                    jump[i].second = take[j].second;
                }
                if (jump[j].second > jump[i].second || \
                    (jump[j].second == jump[i].second && jump[j].first > jump[i].first)) {
                    //cout << j << "jump2 : " << take[j].first << ' ' << take[j].second << endl; 
                    jump[i].first = jump[j].first;
                    jump[i].second = jump[j].second;
                }
            }
            ans = max(ans, take[i].second);
            ans = max(ans, jump[i].second);
            //cout << i << ':' << take[i].first << '-' << take[i].second << '|';
            //cout << jump[i].first << '-' << jump[i].second << ' ' << ans << endl;
        }

        return ans;

        int ans(W);
        int n(Profits.size());
        int i(0), j(0), mx(0);
        vector<pair<int, int>> v(n);
        for (i = 0; i < n; ++i) {
            v[i].first = Capital[i];
            v[i].second = Profits[i];
        }
        sort(v.begin(), v.end());

        int left(0), mid(0), right(n);
        int idx(0);
        for (i = 0; i < k; ++i) {
            left = 0;
            right = n - i;
            while (left < right) {
                mid = left + (right - left) / 2;
                if (v[mid].first <= ans) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            mx = 0;
            for (j = left - 1; j >= 0; --j) {
                if (v[j].second > mx) {
                    mx = v[j].second;
                    idx = j;
                }
            }
            ans += mx;
            v.erase(v.begin() + idx);
        }

        return ans;
        */

        int ans(W);
        priority_queue<int> available;
        multiset<pair<int, int>> rest;

        int n(Profits.size());
        int i(0), j(0);
        for (i = 0; i < n; ++i) {
            if (Capital[i] <= ans) {
                available.push(Profits[i]);
            } else {
                rest.insert({Capital[i], Profits[i]});
            }
        }

        auto iter(rest.cbegin());
        for (i = 0; i < k; ++i) {
            if (available.empty()) { break; }
            
            ans += available.top();
            available.pop();
            
            while (iter != rest.cend()) {
                if (iter->first > ans) { break; }
                available.push(iter->second);
                ++iter;
            }
        }

        return ans;
    }
};
// @lc code=end

