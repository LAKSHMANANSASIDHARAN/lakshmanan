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

/*Question 1: Washing Machine Time Estimation
A washing machine uses sensors to measure the weight of clothes and selects the water level (Low, Medium, or High). Based on these, it calculates the time needed for washing.
If the weight is 0, the time is 0 minutes.
If the weight is less than or equal to 2000 grams, and water level is Low (L), the time is 25 minutes.
If the weight is between 2001 and 4000 grams, and water level is Medium (M), the time is 35 minutes.
If the weight is above 4000 grams, and water level is High (H), the time is 45 minutes.
The washing machine's maximum capacity is 7000 grams.
If the weight exceeds 7000 grams, print "OVERLOADED".
If the weight is negative, print "INVALID INPUT".
Input format:
An integer (weight of clothes) and a character (L, M, or H for water level).
Output format:
Time Estimated: NN Minutes or OVERLOADED or INVALID INPUT.*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int weight;
    char waterLevel;
    cin >> weight >> waterLevel;
    if (weight < 0) {
        cout << "INVALID INPUT" << endl;
    } else if (weight == 0) {
        cout << "Time Estimated: 0 Minutes" << endl;
    } else if (weight > 7000) {
        cout << "OVERLOADED" << endl;
    } else {
        if (waterLevel == 'L' && weight <= 2000) {
            cout << "Time Estimated: 25 Minutes" << endl;
        } else if (waterLevel == 'M' && weight > 2000 && weight <= 4000) {
            cout << "Time Estimated: 35 Minutes" << endl;
        } else if (waterLevel == 'H' && weight > 4000) {
            cout << "Time Estimated: 45 Minutes" << endl;
        } else {
            cout << "INVALID INPUT" << endl;
        }
    } 
 return 0;
}
/*Question 1: Washing Machine Time Estimation
A washing machine uses sensors to measure the weight of clothes and selects the water level (Low, Medium, or High). Based on these, it calculates the time needed for washing.
If the weight is 0, the time is 0 minutes.
If the weight is less than or equal to 2000 grams, and water level is Low (L), the time is 25 minutes.
If the weight is between 2001 and 4000 grams, and water level is Medium (M), the time is 35 minutes.
If the weight is above 4000 grams, and water level is High (H), the time is 45 minutes.
The washing machine's maximum capacity is 7000 grams.
If the weight exceeds 7000 grams, print "OVERLOADED".
If the weight is negative, print "INVALID INPUT".
Input format:
An integer (weight of clothes) and a character (L, M, or H for water level).
Output format:
Time Estimated: NN Minutes or OVERLOADED or INVALID INPUT.
Question 2: Safe Addition and Subtraction
You are given two numbers. Perform both addition and subtraction with the following rules:
Addition:
If the result is negative, display its absolute value.
Subtraction:
If the result is negative, display its absolute value.
Input format:
Two integers.
Output format:
Addition of 2 values: NN
Subtraction of 2 values: NN*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int num1, num2;
    cin >> num1 >> num2;

    int addition = abs(num1 + num2);
    int subtraction = abs(num1 - num2);

    cout << "Addition of 2 values: " << addition << endl;
    cout << "Subtraction of 2 values: " << subtraction << endl;
    return 0;
}



