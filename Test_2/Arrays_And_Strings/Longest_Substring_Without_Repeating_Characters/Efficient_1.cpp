class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i = 0;
        int j = 0;
        int res = 0;
        while(j < s.size()) {
            char currChar = s[j];
            if(mp.find(currChar) == mp.end()) {
                mp[currChar]++;
                res = max(res, j - i + 1);
            } else if(mp.find(currChar) != mp.end()) {
                while(mp.find(currChar) != mp.end()) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                mp[s[j]]++;
                res = max(res, j - i + 1);
            }
            j++;
        }
        return res;
    }
};