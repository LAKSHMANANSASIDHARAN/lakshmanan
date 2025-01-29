/*1.You have a number to examine, and your mission is to write a program that checks 
whether this number can be divided evenly by 27. Can you find out if it‟s a multiple of 
27?*/
#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num % 27 == 0) {
        cout << num << " is a multiple of 27" << endl;
    } else {
        cout << num << " is not a multiple of 27" << endl;
    }

    return 0;
}

/*2.You have two numbers, and your challenge is to write a program that performs both 
addition and subtraction with them. However, if any subtraction results in a negative 
number, display it as a positive value. How will you tackle this and show the final 
results?*/
#include <iostream>
using namespace std;
int main(){
  int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int sum = a + b;
    int diff = a - b;
    if (diff < 0) {
        diff = -diff;
    }

    cout << "Addition: " << sum << endl;
    cout << "Subtraction: " << diff << endl;
  return 0;
}
/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/
/*Example 2:
Input: s = "()[]{}"
Output: true
Example 3:
Input: s = "(]"
Output: false*/
//We are going to use the stack because stack only save its value in order of First in last out
// By this we can easy compare the all closed bracket with top of the stack
  bool isValid(string s) {
    stack<char> st;
    
    for (char c : s) {
      // we are storing all type of opening bracket in stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
        // if we  find the closed bracket  then compare it with top of the stack 
          // if its not same return false
        else {
            if (st.empty()) return false;
            if ((c == ')' && st.top() != '(') || 
                (c == '}' && st.top() != '{') || 
                (c == ']' && st.top() != '[')) {
                return false;
            }
            st.pop();
        }
    }
     return st.empty();
    }
/*Time complexity is O(n)
Space complexity is O(n) because we are using stack*/
