1.Write a program that enters two integers n and l and generates, in alphabetical order,
all possible "stupid passwords" that consist of the following 5 characters:
#include <iostream>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    for (int d1 = 1; d1 <= n; d1++) {
        for (int d2 = 1; d2 <= n; d2++) {
            for (char c1 = 'a'; c1 < 'a' + l; c1++) {
                for (char c2 = 'a'; c2 < 'a' + l; c2++) {
                    for (int d3 = 1; d3 <= n; d3++) {
                        if (d3 > d1 && d3 > d2) {
                            cout << d1 << d2 << c1 << c2 << d3 << " ";
                        }
                    }
                }
            }
        }
    }

    return 0;
}
2. Write a Jcpp method to calculate the factorial of a given number:
#include <iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}
