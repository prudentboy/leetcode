/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start
class UndergroundSystem {
public:
    UndergroundSystem() : station_cnt_(0) {}
    
    void checkIn(int id, string stationName, int t) {
        if (stations_.count(stationName) == 0) { stations_[stationName] = station_cnt_++; }
        people_[id] = {stations_[stationName], t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if (stations_.count(stationName) == 0) { stations_[stationName] = station_cnt_++; }
        auto& in_record(people_[id]);
        int key(getTravelKey(in_record.first, stations_[stationName]));
        ++cnts_[key];
        t_[key] += t - in_record.second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        int key(getTravelKey(stations_[startStation], stations_[endStation]));
        return (double)t_[key] / cnts_[key];
    }
private:
    inline int getTravelKey(int start, int end) {
        return start << 16 | end;
    }
private:
    int station_cnt_;
    unordered_map<string, int> stations_;
    unordered_map<int, int> cnts_;
    unordered_map<int, int> t_;
    unordered_map<int, pair<int, int>> people_;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end

