/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() : cnt_(0) {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        vector<int> tweet({tweetId, userId, 0});
        tweets_[++cnt_] = tweet;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for (auto iter = tweets_.rbegin(); iter != tweets_.rend(); ++iter)
        {
            if (follow_[userId].count((iter->second)[1])) ans.push_back((iter->second)[0]);
            if (ans.size() == 10) break;
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follow_[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        follow_[followerId].erase(followeeId);
    }
private:
    unsigned long long int cnt_;
    unordered_map<int, unordered_set<int>> follow_;
    // tweet : t[0]-id, t[1]-user, t[2]-status
    map<unsigned long long int, vector<int>> tweets_;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

