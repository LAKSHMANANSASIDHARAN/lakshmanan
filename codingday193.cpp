/*1189. Maximum Number of Balloons
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
You can use each character in text at most once. Return the maximum number of instances that can be formed.
Example 1:
Input: text = "nlaebolko"
Output: 1
Example 2:
Input: text = "loonbalxballpoon"
Output: 2
Example 3:
Input: text = "leetcode"
Output: 0
 */
class Solution {
public:
    int maxNumberOfBalloons(string text) {
     vector<int>hash(26,0);
      for(auto i:text){
        if(i=='b' or i=='a' or i=='l' or i=='n' or i=='o'){
            hash[i-'a']++;
        }
      }
      int maxi=INT_MAX;
      maxi=min(hash['b'-'a'],maxi);
      maxi=min(hash['n'-'a'],maxi);
      maxi=min(hash['l'-'a']/2,maxi);
      maxi=min(hash['o'-'a']/2,maxi);
       maxi=min(hash['a'-'a'],maxi);
      return maxi;

    }
};
