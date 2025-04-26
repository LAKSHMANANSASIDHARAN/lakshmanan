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
