/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : q_(k, 0), front_(0), rear_(0), size_(k), len_(0) {}
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        q_[front_] = value;
        front_ = (front_ + 1) % size_;
        ++len_;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        rear_ = (rear_ + 1) % size_;
        --len_;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return q_[rear_];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        return q_[(front_ + size_ - 1) % size_];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return len_ == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return len_ == size_;
    }
private:
    vector<int> q_;
    int front_;
    int rear_;
    int size_;
    int len_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

