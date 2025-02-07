#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Enter a number: ";
    cin >> n;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    cout << "Sum of digits: " << sum << endl;
    return 0;
}



#include <iostream>
using namespace std;

int main() {
    int n, flag = 1;
    cout << "Enter a number: ";
    cin >> n;

    if (n <= 1) flag = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }

    if (flag)
        cout << n << " is a prime number." << endl;
    else
        cout << n << " is not a prime number." << endl;

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    cout << "The largest element is: " << largest << endl;
    return 0;
}



#include <iostream>
using namespace std;

int main() {
    int n, reverse = 0;
    cout << "Enter a number: ";
    cin >> n;

    while (n > 0) {
        reverse = reverse * 10 + (n % 10);
        n /= 10;
    }

    cout << "Reversed number: " << reverse << endl;
    return 0;
}



#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, rev;
    cout << "Enter a string: ";
    cin >> str;

    rev = string(str.rbegin(), str.rend());

    if (str == rev)
        cout << str << " is a palindrome." << endl;
    else
        cout << str << " is not a palindrome." << endl;

    return 0;
}


