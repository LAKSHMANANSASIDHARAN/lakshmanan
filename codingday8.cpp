/*Today problem is Minimum number of operations to move all balls to each box
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
