/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) : _index(0) {
        transNestedIntegerToVec(nestedList, _flattened);
    }

    int next() {
        return _flattened[_index++];
    }

    bool hasNext() {
        return _index < _flattened.size();
    }
private:
    void transNestedIntegerToVec(const vector<NestedInteger>& nestedList, vector<int>& v)
    {
        for (const auto& nest : nestedList)
        {
            if (nest.isInteger()) v.push_back(nest.getInteger());
            else transNestedIntegerToVec(nest.getList(), v);
        }
    }
private:
    vector<int> _flattened;
    size_t _index;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

