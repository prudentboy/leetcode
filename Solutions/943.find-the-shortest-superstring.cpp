/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 */

// @lc code=start
class Solution {
    public:
  string shortestSuperstring(vector<string>& A) {    
    const int n = A.size();
    g_ = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        g_[i][j] = A[j].length();
        for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k)
          if (A[i].substr(A[i].size() - k) == A[j].substr(0, k))            
            g_[i][j] = A[j].length() - k;
      }
    vector<int> path(n);
    best_len_ = INT_MAX;
    dfs(A, 0, 0, 0, path);    
    string ans = A[best_path_[0]];
    for (int k = 1; k < best_path_.size(); ++k) {
      int i = best_path_[k - 1];
      int j = best_path_[k];
      ans += A[j].substr(A[j].length() - g_[i][j]);
    }
    return ans;
  }
private:
  vector<vector<int>> g_;
  vector<int> best_path_;
  int best_len_;
  void dfs(const vector<string>& A, int d, int used, int cur_len, vector<int>& path) {
    if (cur_len >= best_len_) return;
    if (d == A.size()) {
      best_len_ = cur_len;
      best_path_ = path;
      return;
    }
    
    for (int i = 0; i < A.size(); ++i) {
      if (used & (1 << i)) continue;      
      path[d] = i;
      dfs(A,
          d + 1, 
          used | (1 << i),
          d == 0 ? A[i].length() : cur_len + g_[path[d - 1]][i],
          path);
    }
  }
    /*
public:
    string shortestSuperstring(vector<string>& A) {
        int n(A.size());
        
        vector<vector<int>> costGraph(n, vector<int>(n, 0));
        int i(0), j(0);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i == j) { continue; }
                costGraph[i][j] = calConLength(A[i], A[j]);
            }
        }
        
        vector<bool> visited(n, false);
        vector<int> path;
        vector<int> now;
        path.reserve(n);
        now.reserve(n);
        int mn(INT_MAX);
        
        function<void(int, int)> dfs;
        dfs = [&](int front, int len) {
            if (len >= mn) { return; }
            if (now.size() == n) {
                mn = len;
                path = now;
                return;
            }
            for (int i(0); i < n; ++i) {
                if (visited[i]) { continue; }
                int cnt = front == -1 ? A[i].size() : costGraph[front][i];
                len += cnt;
                now.push_back(i);
                visited[i] = true;
                dfs(i, len);
                visited[i] = false;
                now.pop_back();
                len -= cnt;
            }
        };
        
        dfs(-1, 0);
        //for (int p : path) { cout << p << ' '; }
        //cout << endl;
        
        string ans(A[path[0]]);
        for (int i(1); i < n; ++i) {
            ans.append(A[path[i]].substr(A[path[i]].size() - costGraph[path[i - 1]][path[i]]));
        }
        
        return ans;
    }
private:
    int calConLength(const string& front, const string& behind) {
        char c(behind[0]);
        for (int i(0); i < front.size(); ++i) {
            if (front[i] != c) { continue; }
            if (behind.find(front.substr(i)) != string::npos) { return behind.size() - front.size() + i; }
        }
        return behind.size();
    }*/
};
// @lc code=end

