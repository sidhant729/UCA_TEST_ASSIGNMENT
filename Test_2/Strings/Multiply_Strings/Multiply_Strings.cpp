// Problem Link -> https://leetcode.com/problems/multiply-strings/description/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        vector<int>v(num1.size()+num2.size(), 0);
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        for(int i = 0; i < num1.size(); i++) {
            int digit1 = num1[i]-'0';
            for(int j = 0; j < num2.size(); j++) {
                int digit2 = num2[j]-'0';
                int currIndex = i + j;
                int currProduct = digit1 * digit2 + v[currIndex];
                int currVal = currProduct%10;
                int currCarry = currProduct/10;
                v[currIndex+1] += currCarry;
                v[currIndex] = currVal;
            }
        }
        string res = "";
        reverse(v.begin(),v.end());
        bool flag = false;
        for(auto it : v) {
            if(!flag && it == 0) continue;
            if(it != 0) flag = true;
            res += to_string(it);
            
        }
        return res;
    }
};