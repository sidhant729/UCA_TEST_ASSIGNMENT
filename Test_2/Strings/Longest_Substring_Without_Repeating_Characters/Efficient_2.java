// Problem Link -> https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
        int low = 0;
        int high = 0;
        int res = 0;
        while(high < s.length()) {
            if(set.contains(s.charAt(high))) {
                set.remove(s.charAt(low));
                low++;
            } else {
                set.add(s.charAt(high));
                res = Math.max(res, high - low + 1);
                high++;
            }
        }
        return res;
    }
}