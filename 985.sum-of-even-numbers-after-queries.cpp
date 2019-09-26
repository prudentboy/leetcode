/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
 */
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        if (queries.empty()) return {};
        
        int sum(0);
        for (int n : A) sum += (n % 2 == 0 ? n : 0);

        vector<int> ans(queries.size(), 0);
        for (int i(0); i < queries.size(); ++i)
        {
            if(A[queries[i][1]] % 2 == 0) sum -= A[queries[i][1]];
            A[queries[i][1]] += queries[i][0];
            if(A[queries[i][1]] % 2 == 0) sum += A[queries[i][1]];
            ans[i] = sum;
        }

        return ans;
    }
};

