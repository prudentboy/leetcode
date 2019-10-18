/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 */

// @lc code=start
class Solution {
public:
    string validIPAddress(string IP) {
        const string ret[3] = {"IPv4", "IPv6", "Neither"};
        //cout << ret[0] << ' ' << ret[1] << ' ' << ret[2] << endl;
        if (isValidIPv4(IP)) return ret[0];
        if (isValidIPv6(IP)) return ret[1];
        return ret[2];    
    }
private:
    bool isValidIPv4(const string& ip)
    {
        size_t start(0), index(0);
        int n(0);
        for (int i(0); i < 3; ++i)
        {
            index = ip.find_first_of(".", start);
            if (index == string::npos || index == start || index - start > 3) return false;
            for (int j(start); j < index; ++j) if (!isdigit(ip[j])) return false;
            if (index - start > 1 && ip[start] == '0') return false;
            n = stoi(ip.substr(start, index - start));
            //cout << i << ':' << n << endl;
            if (n > 255) return false;
            start = index + 1;
        }
        index = ip.size();
        if (index == start || index - start > 3) return false;
        for (int j(start); j < index; ++j) if (!isdigit(ip[j])) return false;
        if (index - start > 1 && ip[start] == '0') return false;
        n = stoi(ip.substr(start, index - start));
        if (n > 255) return false;
        return true;
    }
    bool isValidIPv6(const string& ip)
    {
        size_t start(0), index(0);
        int n(0);
        for (int i(0); i < 7; ++i)
        {
            index = ip.find_first_of(":", start);
            if (index == string::npos || index == start || index - start > 4) return false;
            //cout << ip.substr(start, index - start) << endl;
            //if (index - start == 4)
            //{
                for (int j(start); j < index; ++j) if (!isdigit(ip[j]) && (tolower(ip[j]) < 'a' || tolower(ip[j]) > 'f')) return false;
            //}
            //else if (index - start > 1 && ip[start] == '0') return false;
            start = index + 1;
        }
        index = ip.size();
        if (index == start || index - start > 4) return false;
        //if (index - start == 4)
        //{
            for (int j(start); j < index; ++j) if (!isdigit(ip[j]) && (tolower(ip[j]) < 'a' || tolower(ip[j]) > 'f')) return false;
        //}
        //else if (index - start > 1 && ip[start] == '0') return false;
        return true;
    }
};
// @lc code=end

