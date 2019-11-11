/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

// @lc code=start
class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        unsigned int hash(0);
        int i(0), j(0);
        for (i = 0, j = 0; j < longUrl.size(); ++i)
        {
            if ((i & 1) == 0) hash ^= ((hash << 7) ^ (longUrl[j++]) ^ (hash >> 3));
            else hash ^= (~(hash << 11) ^ (longUrl[j++]) ^ (hash >> 5));
        }
        hash &= 0x7FFFFFFF;
        m_[hash] = longUrl;
        return to_string(hash);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        unsigned int hash = stoi(shortUrl);
        return m_[hash];
    }
private:
    unordered_map<unsigned int, string> m_;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

