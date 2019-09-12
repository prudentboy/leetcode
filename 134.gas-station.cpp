/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> delta(gas);
        for (int i(0); i < cost.size(); ++i) delta[i] -= cost[i];
        int sum(0);
        for (int i(0); i < delta.size(); ++i) sum += delta[i];
        if (sum < 0) return -1;
        for (int i(0); i < delta.size(); ++i) 
            if (canCompleteCircuit(delta, i)) return i;
        return -1;
    }
private:
    inline bool canCompleteCircuit(const vector<int>& delta, int index)
    {
        if (delta[index] < 0) return false;
        int i(index);
        int now(0);
        do {
            now += delta[i];
            //cout << i << ' ' << delta[i] << ' ' << now << endl;
            if (now < 0) return false;
            i = (i + 1) % delta.size();
        } while (i != index);
        return true;
    }
};

