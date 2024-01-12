// Problem Link -> https://leetcode.com/problems/container-with-most-water/descripti

class Solution {
    public int maxArea(int[] height) {
        int low = 0;
        int high = height.length - 1;
        int res = 0;
        while(low < high) {
            int currWater = Math.min(height[low], height[high]) * (high - low);
            res = Math.max(currWater, res);
            if(height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }
        return res;
    }
}