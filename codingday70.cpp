/*Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int>arr={-1,1,0,-3,3};
    vector<int>prefix(arr.size()),ans(arr.size());
    int i=1;
    prefix[0]=arr[0];
    while(i<arr.size()){
    prefix[i]=prefix[i-1]*arr[i];
    i++;
}
for(i=arr.size()-2;i>=0;i--){
arr[i]=arr[i]*arr[i+1];
}
i=0;
while(i<arr.size()){
    if(i==0 ){
        ans[i]=arr[i+1];
    }
    else if(i==arr.size()-1){
       ans[i]=prefix[i-1];
    }
    else{
        ans[i]=prefix[i-1]*arr[i+1];
    }
    i++;
}
for(auto it:ans){
    cout<<it<<" ";
}

}
