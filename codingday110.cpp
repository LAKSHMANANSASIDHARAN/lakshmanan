/*Permutation in String
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.
Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>hash(26,0) ,hash2(26,0);
        string temp="",temp2="";
        if(s1.size()>s2.size()) return false;
        temp=s1;
        temp2=s2;
        for(auto i:temp){
            hash[i-'a']++;
        }
        int i=0;
        for(i=0;i<temp.size();i++){
            hash2[temp2[i]-'a']++;
        }
        if(hash==hash2)return true;
        int l=0;
        while (i<temp2.size()){   
            hash2[temp2[l]-'a']--;
            hash2[temp2[i]-'a']++;
            if(hash==hash2){
                return true;
            }
            l++;
            i++;
        }
        return false;
    }
};
/*Fruit Into Baskets
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.
Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int len=0;
        int l=0,r=0;
        while(r<fruits.size()){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
              
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                  l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};
