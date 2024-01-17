// Problem Link -> https://leetcode.com/problems/multiply-strings/description/

class Solution {
    public String multiply(String num1, String num2) {
        StringBuilder ref_num1 = new StringBuilder(num1);
        StringBuilder ref_num2 = new StringBuilder(num2);
        if(num1.equals("0") || num2.equals("0")) return "0";     
        
        ref_num1 = ref_num1.reverse();
        ref_num2 = ref_num2.reverse();

        ArrayList<Integer> v = new ArrayList<>(Collections.nCopies(ref_num1.length() + ref_num2.length(), 0));

        for (int i = 0; i < ref_num1.length(); i++) {
            int digit1 = Character.getNumericValue(ref_num1.charAt(i));
            for (int j = 0; j < ref_num2.length(); j++) {
                int digit2 = Character.getNumericValue(ref_num2.charAt(j));
                int currIndex = i + j;
                int currProduct = digit1 * digit2 + v.get(currIndex);
                int currVal = currProduct % 10;
                int currCarry = currProduct / 10;
                v.set(currIndex, currVal);
                v.set(currIndex + 1, v.get(currIndex + 1) + currCarry);
            }
        }

        Collections.reverse(v);
        StringBuilder res = new StringBuilder();
        boolean notLeadingZeros = false;
        for (int i = 0; i < v.size(); i++) {
            if(!notLeadingZeros && v.get(i) == 0) continue;
            if(v.get(i) != 0 && notLeadingZeros == false) {
                notLeadingZeros = true;
            }
            res.append(v.get(i));
        }
        return res.toString();
    }
}