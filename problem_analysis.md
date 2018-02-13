## leetcode题目分析 ##

### 数字转换 ###
- 13.Roman to Interger
-- 从右向左，变小则减，否则累加

### 回文 ###
- 回文 = 逆序 + 相等  
- vector(include string)回文判断
```
bool isPalindrome(const string& s)
{
    return equal(s.begin(), s.begin() + s.length() / 2, s.rbegin());
}
```
