/* Find the Longest Substring Containing Vowels in Even Counts
Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
Example 1:
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:
Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:
Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.*/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int res=0,l=0,r=0;
        while(l<s.size()){
            int a=0,e=0,i=0,o=0,u=0;
            r=l;
            while(r<s.size()){
                if(s[r]=='a'){
                    a++;
                }
              else  if(s[r]=='e'){
                    e++;
                }
             else   if(s[r]=='i'){
                    i++;
                }
             else   if(s[r]=='o'){
                    o++;
                }
               else if(s[r]=='u'){
                    u++;
                }
                if((a%2==0 )and (i%2==0 )and (o%2==0) and (e%2==0) and (u%2==0)){
                   res=max(res,r-l+1);
                }
                r++;
            }
            l++;
        }
        return res;
    }
};
