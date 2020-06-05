/*
 * @lc app=leetcode id=1184 lang=cpp
 *
 * [1184] Distance Between Bus Stops
 */

// @lc code=start
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int left(start), right(start), n(distance.size());
        int disLeft(0), disRight(0);
        while (left != destination || right != destination) {
            if (left == destination) {
                if (disLeft < disRight) { return disLeft; }
            } else {
                left = (left + n - 1) % n;
                disLeft += distance[left]; 
            }
            if (right == destination) {
                if (disRight < disLeft) { return disRight; }
            } else {
                disRight += distance[right];
                right = (right + 1) % n;
            }
        }
        return min(disLeft, disRight);
    }
};
// @lc code=end

