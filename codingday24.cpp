/*Minimum Operations to Make Binary Array Elements Equal to One I
You are given a binary array nums.
You can do the following operation on the array any number of times (possibly zero):
Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.
Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.
Example 1:
Input: nums = [0,1,1,1,0,0]
Output: 3
Explanation:
We can do the following operations:
Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].
Example 2:
Input: nums = [0,1,1,1]
Output: -1
Explanation:
It is impossible to make all elements equal to 1.
*/
class Solution {
 public:
 bool checking(vector<int>check){
    int i=0;
    while(i<check.size()){
        if(check[i]==0){
            return false;
            break;
        }
        i++;
    }
    return true;
}

public:

    int minOperations(vector<int>& binary) {
        
  int i=0,j=2;
  int n=binary.size();
  int ans=0;
  while(j<n){
    if(binary[i]==0){
        int k=i;
        while(k<=j){
            if(binary[k]==1){
                binary[k]=0;
            }else{
            binary[k]=1;
        }
            k++;

        }
        i++;
        j++;
        ans+=1;
    }
    else{
        i++;
        j++;
      }
  }
  bool check=checking(binary);
  if(check==true){
    return ans;
  }
  else{
    return -1;
  }
    }
};
