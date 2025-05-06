/*Given an array of integers, perform the following steps:
Square each element.
Convert each squared number to its 8-bit binary representation.
For each binary string, count the number of 1's (i.e., Hamming weight or bit count).
Pair each squared number with its corresponding bit count.
Sort the pairs primarily by bit count (ascending), and secondarily by number value (ascending if tie).
From the sorted list:
Let minval = number corresponding to the minimum bit count (first in sorted).
Let maxval = number corresponding to the maximum bit count (last, but if there are ties, pick the last such value from those tied).
Compute res = minval * maxval.
Find and print the smallest power of 2 that is strictly greater than res.*/
#include <iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
void mul(vector<int>&nums){
for(int i=0;i<nums.size();i++){
  nums[i]=nums[i]*nums[i];
  }
}
void convert(vector<int>&nums,vector<string>&arr){
     for(auto it:nums){
      arr.push_back(bitset<8>(it).to_string());
    }
   }
void givesize(vector<string>&arr,vector<int>&size){
  int count=0;
  for(auto it:arr){
    for(auto i:it){
      if(i=='1'){
        count++;
      }
    }
    size.push_back(count);
    count=0;
}
}
int findmax(vector<int>&nums,vector<int>&size){
int maxval=nums[nums.size()-1],maxbit=size[size.size()-1];
for(int i=nums.size()-2;i>=0;i--){
  if(maxbit<size[i]){
    maxbit=size[i];
  }
 else if(maxbit==size[i]){
    maxval=min(maxval,nums[i]);
  }
}
return maxval;
}
int findmin(vector<int>&nums,vector<int>&size){
int minval=nums[0],minbit=size[0];
for(int i=1;i<nums.size();i++){
  if(minbit>size[i]){
    minbit=size[i];
  }
 else if(minbit==size[i]){
  minval=min(minval,nums[i]);
 }

}
return  minval;
}
void insert(vector<int>&arr,vector<int>&size,vector<pair<int,int>>&mainprocess){
int i=0;
while(i<arr.size()){
  mainprocess.push_back({size[i],arr[i]});
  i++;
}
}
bool compare(pair<int,int>&a,pair<int,int>&b){
if(a.first==b.first){
  return a.second<b.second;
}
return a.first<b.first;
}
int main(){
  vector<int>nums={3,7,4,1,5,2,9};
  mul(nums);
  vector<string>arr;
  convert(nums,arr);
  vector<int>size;
  givesize(arr,size);
  vector<pair<int,int>>mainprocess;
  insert(nums,size,mainprocess); 
  sort(mainprocess.begin(),mainprocess.end(),compare);
  int minval=mainprocess[0].second;
  int maxval=mainprocess[mainprocess.size()-1].second;
  int temp=mainprocess[mainprocess.size()-1].first;
  for(int i=mainprocess.size()-2;i>=0;i--){
     if(temp==mainprocess[i-1].first){
       maxval=mainprocess[i].second;
     }    
    }
   int res=minval*maxval;
    int fin=1;
    while(fin!=res){
      if(fin>res){
        cout<<fin;
        return 0;
        break;
      }
      else{
        fin*=2;
      }
    }
    cout<<fin;
}
