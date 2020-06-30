/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 */

// @lc code=start
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<int> ans;
        if (k == 0) return ans;
        
        int m(nums1.size()), n(nums2.size());
        
        vector<int> n1, n2, tmp;
        for (int i = max(0, k - n); i <= min(m, k); ++i)
        {
            n1 = std::move(getSingleMax(nums1, i));
            n2 = std::move(getSingleMax(nums2, k - i));
            tmp = std::move(mergeVec(n1, n2));
            //cout << i << ' ' << n1.size() << ' ' << n2.size() << ' ' << tmp.size() << endl;
            if (isLarger(tmp, ans)) ans = tmp;
        }
        
        return ans;
    }
private:
    vector<int> getSingleMax(const vector<int>& v, int m)
    {
        vector<int> ans;
        if (m == 0) return ans;
        if (m == v.size()) return v;
        
        int i(0), d(v.size() - m);
        for (i = 0; i < v.size(); ++i)
        {
            while (!ans.empty() && d > 0 && ans.back() < v[i])
            {
                --d;
                ans.pop_back();
            }
            ans.push_back(v[i]);
        }
        ans.resize(m);
        
        //for (int i(0); i < ans.size(); ++i) cout << ans[i] << ' ';
        //cout << endl;
        
        return ans;
    }
    vector<int> mergeVec(vector<int>& v1, vector<int>& v2)
    {
        if (v1.empty()) return v2;
        if (v2.empty()) return v1;
        
        //for (int i(0); i < v1.size(); ++i) cout << v1[i] << ' ';
        //cout << endl;
        //for (int i(0); i < v2.size(); ++i) cout << v2[i] << ' ';
        //cout << endl;
        
        vector<int> ans;
        while (!v1.empty() || !v2.empty())
        {
            vector<int> &tmp = (v1 > v2) ? v1 : v2;
            ans.push_back(tmp[0]);
            tmp.erase(tmp.begin());
            //cout << 'a' << i << ' ' << j << ' ' << k << endl;
            //cout << v1[i] << ' ' << v2[j] << ' ' << ans[k] << endl;
        }
        
        return ans;
    }
    bool isLarger(const vector<int>& v1, const vector<int>& v2)
    {
        int i(0), j(0), m(v1.size()), n(v2.size());
        
        while (i < m && j < n)
        {
            if (v1[i] > v2[j]) return true;
            else if (v1[i] < v2[j]) return false;
            ++i;
            ++j;
        }
        
        if (i < m) return true;
        return false;
    }
};
// @lc code=end

