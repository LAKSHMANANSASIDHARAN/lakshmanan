/*Today problem is Count the number of the substring within string 
They have given the string "10101" and k=1.
Now we need to find out how many substring are inside the main ,the condition is you can pick 1 and 0 if both are within the limit[k].
and we need to return the number of substring are here */
/*Example 1:
Input: s = "10101", k = 1
Output: 12
Example 2:
Input: s = "1010101", k = 2
Output: 25
Example 3:
Input: s = "11111", k = 1
Output: 15
*/
 int countKConstraintSubstrings(string s, int k) {
        int c1 = 0, c0 = 0, sum = 0, i = 0, j = 0;
         while (j < s.size()) {
            if (s[j] == '0') c0++;
            if (s[j] == '1') c1++;
            while (c0 > k && c1 > k) {
                if (s[i] == '0') c0--;
                if (s[i] == '1') c1--;
                i++;
            }     
           sum += (j - i + 1);
           j++;
        } return sum;
    }

/*Time Complexity is O(n) we are not using any extra loop .while loop that inside the main loop is just checking ,so it wont take time.
Space Complexity is 0(1) we are not using any extra space for storing any array or number */

 
