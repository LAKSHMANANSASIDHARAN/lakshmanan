/*Relative Sort Array
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
Example 1:
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:
Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]*/
class Solution {
    void process(int i,int& count,  vector<int>&ans, unordered_map<int,int>&mp){
        while(count--){
            ans.push_back(i);
        }
        mp[i]=0;
    }
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
      unordered_map<int,int>mp;
      for(auto i:arr1){
          mp[i]++;
      }  
      vector<int>ans;
      for(auto i:arr2){
        int temp=mp[i];
        process(i,temp,ans,mp);
      }
      vector<int>temp;
      for(auto i:mp){
        if(i.second!=0){
           process(i.first,i.second,temp,mp);   
        }
      }
      sort(temp.begin(),temp.end());
      for(auto i:temp){
        ans.push_back(i);
      }
      return ans;
    }
};
