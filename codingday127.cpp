/*Add Strings
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"*/
class Solution {
    void rev(string& ans){
        int i=0,j=ans.size()-1;
        while(i<=j){
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
    }
    void process(string num,int i,string & ans, int bal){
        while(i>=0){
           int sum=bal+num[i]-'0';
           if(sum>=10){
            bal=1;
            sum  = sum % 10;
            ans+=to_string(sum);
         }
         else{
            bal=0;
            ans+=to_string(sum);
         }
         i--;
        }
         if(bal==1){
         ans+='1';
     }
    }
public:
    string addStrings(string num1, string num2) {
     int i=num1.size()-1;
     int j=num2.size()-1;
     int bal=0;
     int temp1,temp2,sum;
     string ans;
     while(i>=0 && j>=0){
         temp1=num1[i]-'0';
         temp2=num2[j]-'0';
         sum=bal+temp1+temp2;
         if(sum>=10){
            bal=1;
            sum  = sum % 10;
            ans+=to_string(sum);
         }
         else{
            bal=0;
            ans+=to_string(sum);
         }
         i--;
         j--;
     }
     if(i>=0){
        process(num1,i,ans,bal);
     }
     else{
        process(num2,j,ans,bal);
     }
    
      rev(ans);
      return ans;

    }
};
