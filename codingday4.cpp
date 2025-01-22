//Partition Array According to Given Pivot.
//Input: nums = [9,12,5,10,14,3,10], pivot = 10
//Output: [9,5,3,10,10,12,14]
// This problem shows that we need to arrange all element in array . We are not going to sort instead of that they have given the pivot element that element will be in given 
//array . The elements less that pivot should be before the pivot and the greater should be after the pivot .
// For this problem Im going to use Two pointer Algorithm.
 vector<int> pivotArray(vector<int>& arr, int pivot) {
          int j=-1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == pivot) {
            j = i;            // First we need to find the pivot element in the array and keep that element index and break the loop 
            break;
        }
    }

    int i = 0;

    
    while (i < arr.size()) {
        if (arr[i] < arr[j] && i > j) {  // if arr[i] is less than arr[j] and index i is greater that j ,then we can swap and make j=i and i=0
            swap(arr[i], arr[j]);    
            j = i;  
            i = 0;  // because we need check aging the array [doing like this we can avoid another loop.]
        } else if (arr[i] > arr[j] && i < j) {
            swap(arr[i], arr[j]);// if arr[i] is greater than arr[j] and index i is lesser that j ,then we can swap and make j=i and i=0
            j = i;
            i = j + 1; // change the i as j+1 because this time we no need to recheck the array . 
        } else if (arr[i] == arr[j] && i != j) {
           
                swap(arr[j + 1], arr[i]); // if array contian two same element " that should be pivot" In this case we need to keep that element next or first pivot element.
            
            i++;
        } else {  //otherwise i will be incremented.
            i++;
        }
    }
    return arr; // return the modified array.
    } 
// Final Value of Variable After Performing Operations-Leetcode[2011]
/*There is a programming language with only four operations and one variable X:

++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.
Example 1:

Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
*/
//Thats what this problem stats!!!!!!
// Logic is very simple !!
// they mentioned that language has only four opertions and one variable ,by that we say two increment and two decrement
// so take one variable assign that value as 0 then according to the opertion in array you can 
//increment or decrement the x .
// return that final answer.

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0,i=0;
        while(i<operations.size()){
            if(operations[i]=="X++" or operations[i]=="++X"){
                x=x+1;
            }
            else{
                x=x-1;
            }
            i++;
        }
        return x;
       }
};

