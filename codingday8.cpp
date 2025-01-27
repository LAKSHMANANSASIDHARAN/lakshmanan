/*1.Today problem is Minimum number of operations to move all balls to each box
They have given the binary string , if the string is 0 box is empty ,if its 1 box has ball .
we need to calculate the distance of ball to move to the each boxes*/
/*Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, 
and move one ball from the second box to the third box in one operation.*/
vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>answer(n,0);
        for(int i=0;i<boxes.size();i++){
            for(int j=0;j<boxes.size();j++){
              /* if we found the some box has ball , store the distance of current position and position of the ball*/
                if(boxes[j]=='1'){
                    answer[i]+=abs(i-j);
                }
            }
        }
        return answer;

// time complexity is O(n^2)
// space complexity is O(1)
/*2.Second problem states they have given the array and k value . We need to find the sum k element in the array and store that 
 in new array . 
 For example:
 Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers. 
The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
if k is negative we need to add in reverse manner:
Input: code = [2,4,9,3], k = -2
Output: [12,5,6,13]
Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. 
If k is negative, the sum is of the previous numbers.
 */
/*But the task is implementation of code for both condition */
int i, j;
vector<int> ans;
int n = code.size();
        if (k > 0) { // if k positive i is 1 and j is k
    i = 1;
    j = k;
} 
else { // if it negative i is size of array - k and j is size of array -1
    i = n + k;  
    j = n - 1;  
}
int sum = 0;
while (i <= j) { // first add the k element in array
    sum = sum + code[i % n];
    i++;
}

if (k > 0) {
    i = 1;
    j = k;
} else {
    i = n + k;
    j = n - 1;
}
// re-initialzing
ans.push_back(sum);
int remaining = n - 1;
// use the sliding window algorithm
while (remaining) {
    sum = sum - code[i % n];
    sum = sum + code[(j + 1) % n];
    ans.push_back(sum);
    remaining--;
    i++;
    j++;
}
return ans;
    }
// time complexity is O(n)
//space complexity is 0(1);
