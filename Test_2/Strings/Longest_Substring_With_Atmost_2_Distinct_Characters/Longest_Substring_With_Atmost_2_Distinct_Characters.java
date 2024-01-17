// Problem Link -> https://www.codingninjas.com/studio/problems/longest-substring-with-at-most-two-distinct-characters_3125863?leftPanelTabValue=PROBLEMLon

import java.util.HashMap;

public class Solution {
	public static int lengthOfLongestSubstring(String s) {
		// Write your code here.
		HashMap<Character,Integer> mp = new HashMap<>();
		int low = 0;
		int high = 0;
		int res = 0;
		while(high < s.length()) {
			char currChar = s.charAt(high);
			mp.put(currChar, mp.getOrDefault(currChar, 0) + 1);
			if(mp.size() > 2) {
				while(mp.size() > 2) {
					int currOccurences = mp.get(s.charAt(low));
					currOccurences--;
					if(currOccurences == 0) {
						mp.remove(s.charAt(low));
					} else {
						mp.put(s.charAt(low), currOccurences);
					}
					low++;
				}
				res = Math.max(res, high - low + 1);
			} else {
				res = Math.max(res, high - low + 1);
			}
			high++;
		}
		return res;
	}
}