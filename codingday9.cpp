/*Today problem is maximum score after spliting the array
They have given the binary string we need split the string one by one 
and count the number zero in leftstring and number one in rightstring and add it up . Do thin until the last char in a string
Example :
Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3

Input: s = "1111"
Output: 3
*/
int maxScore(string s) {
        int countone=0,totalsum=0,leftsum=0;
        int i=0;
  // count the number of one in the string .
        while(i<s.size()){
            if(s[i]=='1'){
                countone++;
             }
            i++;
        }
        i=0;
        int maxi=0;
        while(i<s.size()-1){
          //if the char is 0 then increment the leftsum 1 and add it with countone[number of one] 
             if(s[i]=='0'){
                leftsum++;
                totalsum=leftsum+countone;
            }// if the char is 1 then decrement the countone and add it with totalsum 
            else{
                countone--;
                totalsum=leftsum+countone;
            }
            i++;
            maxi=max(maxi,totalsum);// question is we need to find the maximum score so using max fuction we can get the max value
        }
        return maxi;
    }
// Time complexity is O(N)
// Space complexity is O(1)

// Its sounds like simple but thing the logic and implementatio  of the code is a real task .
