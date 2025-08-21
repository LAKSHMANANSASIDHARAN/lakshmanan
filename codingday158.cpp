/*605. Can Place Flowers
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int i=0;
       if(flowerbed.size()==1) {
        if(flowerbed[i]==0) {n--;}
       i+=2;
       }
       while(i<flowerbed.size() && n>0){
         if(i==0 && flowerbed[i]+flowerbed[i+1]==0) {
            n--;
            flowerbed[i]=1;
            i+=2;
         } 
         else if (i==flowerbed.size()-1 && flowerbed[i]+flowerbed[i-1]==0){
            n--;
            flowerbed[i]=1;
            i+=2;
         }
         else if  ( i>0 && i<flowerbed.size()-1 && flowerbed[i-1]+flowerbed[i]+flowerbed[i+1]==0){
            n--;
            flowerbed[i]=1;
            i+=2;
         }
         else{
         i++;
         }
         
       } 
       if(n>0) return false;
       return true;
    }
};
