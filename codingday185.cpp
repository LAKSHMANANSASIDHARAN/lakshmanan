/*405. Convert a Number to Hexadecimal

Given a 32-bit integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve this problem.

 

Example 1:

Input: num = 26
Output: "1a"
Example 2:

Input: num = -1
Output: "ffffffff*/
if(num == 0) return "0";
        unsigned int n = num;
        string hex = "0123456789abcdef", res = "";
        while(n > 0) {
            res = hex[n % 16] + res;
            n /= 16;
        }
        return res;