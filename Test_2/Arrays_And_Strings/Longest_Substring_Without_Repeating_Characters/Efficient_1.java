// Problem Link -> https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer> mp = new HashMap<>();
        int res = 0;
        int low = 0;
        int high = 0;
        while(high < s.length()) {
            char currChar = s.charAt(high);
            if(mp.containsKey(currChar)) {
                 while(mp.containsKey(currChar)) {
                    char toRemove = s.charAt(low);
                    int currOccurences = mp.get(toRemove);
                    currOccurences--;
                    if(currOccurences == 0) {
                        mp.remove(toRemove);
                    } else {
                        mp.put(toRemove, currOccurences);
                    }
                    low++;
                }
                mp.put(currChar, 1);
                res = Math.max(res, high - low + 1);
                
            } else {
                mp.put(currChar,1);
                res = Math.max(res, high - low + 1);
            }
            high++;
        }
        return res;
    }
}