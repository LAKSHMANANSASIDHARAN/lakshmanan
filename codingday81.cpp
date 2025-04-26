/*Minimum sum between range of l and r*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    vector<int> nums = {3,-2,1,4};
    int l = 2, r = 3;
    int n = nums.size();
    int i = 0, j = 0, sum = 0;
    int ans = INT_MAX;

    while(j < n){
        sum += nums[j];
        int len = j - i + 1;
        if(len > r){
            sum -= nums[i];
            i++;
            len = j - i + 1;
        }
        if(len >= l && len <= r && sum > 0){
            ans = min(ans, sum);
        }
        j++;
    }

    if(ans == INT_MAX) cout << -1;
    else cout << ans;
}
/*Merge Similar Items
You are given two 2D integer arrays, items1 and items2, representing two sets of items. Each array items has the following properties:
items[i] = [valuei, weighti] where valuei represents the value and weighti represents the weight of the ith item.
The value of each item in items is unique.
Return a 2D integer array ret where ret[i] = [valuei, weighti], with weighti being the sum of weights of all items with value valuei.
Note: ret should be returned in ascending order by value.
Example 1:
Input: items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
Output: [[1,6],[3,9],[4,5]]
Explanation: 
The item with value = 1 occurs in items1 with weight = 1 and in items2 with weight = 5, total weight = 1 + 5 = 6.
The item with value = 3 occurs in items1 with weight = 8 and in items2 with weight = 1, total weight = 8 + 1 = 9.
The item with value = 4 occurs in items1 with weight = 5, total weight = 5.  
Therefore, we return [[1,6],[3,9],[4,5]].
Example 2:
Input: items1 = [[1,1],[3,2],[2,3]], items2 = [[2,1],[3,2],[1,3]]
Output: [[1,4],[2,4],[3,4]]
Explanation: 
The item with value = 1 occurs in items1 with weight = 1 and in items2 with weight = 3, total weight = 1 + 3 = 4.
The item with value = 2 occurs in items1 with weight = 3 and in items2 with weight = 1, total weight = 3 + 1 = 4.
The item with value = 3 occurs in items1 with weight = 2 and in items2 with weight = 2, total weight = 2 + 2 = 4.
Therefore, we return [[1,4],[2,4],[3,4]].
Example 3:
Input: items1 = [[1,3],[2,2]], items2 = [[7,1],[2,2],[1,4]]
Output: [[1,7],[2,4],[7,1]]
Explanation:
The item with value = 1 occurs in items1 with weight = 3 and in items2 with weight = 4, total weight = 3 + 4 = 7. 
The item with value = 2 occurs in items1 with weight = 2 and in items2 with weight = 2, total weight = 2 + 2 = 4. 
The item with value = 7 occurs in items2 with weight = 1, total weight = 1.
Therefore, we return [[1,7],[2,4],[7,1]].*/
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int,int>mp;
        for(int i=0;i<items1.size();i++){
            mp[items1[i][0]]+=items1[i][1];
        }
        for(int i=0;i<items2.size();i++){
            mp[items2[i][0]]+=items2[i][1];
        }
        vector<vector<int>>res;
        for(auto &[f,s]:mp){
            res.push_back({f,s});
        }
        sort(res.begin(),res.end());
        return res;

    }
};
