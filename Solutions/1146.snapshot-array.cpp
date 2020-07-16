/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 */

// @lc code=start
class SnapshotArray {
public:
    SnapshotArray(int length) : sid_(0), v_(length, 0) {}
    
    void set(int index, int val) {
        v_[index] = val;
        ump_[index][sid_] = val;
    }
    
    int snap() {
        for (auto& p : ump_) {
            ump_[p.first][sid_] = v_[p.first];
        }
        return sid_++;
    }
    
    int get(int index, int snap_id) {
        if (ump_.count(index) == 0) { return 0; }
        if (ump_[index].count(snap_id) == 0) { return 0; }
        return ump_[index][snap_id];
    }
private:
    unordered_map<int, unordered_map<int, int>> ump_;
    vector<int> v_;
    int sid_;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

