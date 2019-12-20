/*
 * @lc app=leetcode id=855 lang=cpp
 *
 * [855] Exam Room
 */

// @lc code=start
class ExamRoom {
public:
    ExamRoom(int N) : cap_(N) {}
    
    int seat() {
        int start(0), ans(0), mx(0);
        for (int n : s_) {
            if (start == 0) {
                if (mx < n - start) { mx = n - start; }
            } else {
                if (mx < ((n - start + 1) >> 1)) {
                    mx = ((n - start + 1) >> 1);
                    ans = start + mx - 1;
                }
            }
            start = n + 1;
        }
        if (start > 0 && mx < cap_ - start) { ans = cap_ - 1;}
        s_.insert(ans);
        return ans;
    }
    
    void leave(int p) {
        s_.erase(p);
    }
private:
    int cap_;
    set<int> s_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

