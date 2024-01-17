// Problem Link -> https://leetcode.com/problems/next-permutation/description/

class Solution {
    private static void reverseArray(int[] nums) {
        int i = 0;
        int j = nums.length - 1;
        while(i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
        return;
    }
    public void nextPermutation(int[] nums) {
        int lastInd = -1;
        for(int i = nums.length - 1; i >= 1; i--) {
            if(nums[i] > nums[i-1]) {
                lastInd = i - 1;
                break;
            }
        }
        if(lastInd == -1) {
            reverseArray(nums);
            return;
        }

        for(int i = nums.length - 1; i >= lastInd+1; i--) {
            if(nums[lastInd] < nums[i]) {
                int temp = nums[lastInd];
                nums[lastInd] = nums[i];
                nums[i] = temp;
                break;
            }
        }

        int low = lastInd+1;
        int high = nums.length - 1;
        while(low < high) {
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }
        return;
    }
}