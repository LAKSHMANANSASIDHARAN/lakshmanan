/*Question 1:
You are tasked with creating a simple calculator using a while loop and a switch statement. 
Your program should repeatedly prompt the user to choose an arithmetic operation (like addition, subtraction, multiplication, or division) and then perform the selected operation based on user input.
How will you set up your while loop and switch case to keep the calculator running until the user decides to exit?*/


#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2;
    bool running = true;

    while (running) {
        cout << "Choose an operation (+, -, *, /) or 'e' to exit: ";
        cin >> operation;

        if (operation == 'e') {
            running = false;
            break;
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (operation) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << endl;
                } else {
                    cout << "Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Invalid operation." << endl;
                break;
        }
    }

    cout << "Calculator exited." << endl;
    return 0;
}


/* Question 2:
Imagine you're building a calculator that can perform different arithmetic operations. Write a program
that uses a do-while loop and a switch statement to handle user input and perform calculations. How will you set up your program to repeatedly ask 
for input and execute operations like addition, subtraction, multiplication, and division based on user choice?*/


#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2;
    do {
        cout << "Choose an operation (+, -, *, /) or 'e' to exit: ";
        cin >> operation;

        if (operation == 'e') {
            break;
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (operation) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << endl;
                } else {
                    cout << "Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Invalid operation." << endl;
                break;
        }
    } while (operation != 'e');

    cout << "Calculator exited." << endl;
    return 0;
}

Pattern 1: Right-Angle Triangle

*
**
***
****
*****



#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}




Pattern 2: Inverted Right-Angle Triangle

*****
****
***
**
*

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}


 Pattern 3: Square Pattern

*****
*****
*****
*****
*****

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

 Pattern 4: Number Triangle

1
12
123
1234
12345
```

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}


Pattern 5: Pyramid Pattern
    *
   ***
  *****
 *******
*********
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

 Pattern 6: Inverted Number Triangle

12345
1234
123
12
1

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}


 Pattern 7: Diamond Pattern

   *
  ***
 *****
*******
 *****
  ***
   *

#include <iostream>
using namespace std;

int main() {
    int n = 4;

    // Upper part of diamond
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    // Lower part of diamond
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}


 Pattern 8: Hollow Square

*****
*   *
*   *
*   *
*****

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
