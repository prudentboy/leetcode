/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        small.push(num);
        big.push(small.top());
        small.pop();
        if (small.size() < big.size())
        {
            small.push(big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        if (small.size() > big.size()) return small.top();
        return (small.top() + big.top()) / 2.0;
    }
private:
    priority_queue<int, vector<int>> small;
    priority_queue<int, vector<int>, greater<int>> big;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

