/*Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25*/
class Solution {
public:
    double myPow(double x, int n) {
        double output = 1;
        long long power = n;
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        while (power > 0) {
            if (power % 2 == 1) {
                output *= x;
            }
            x *= x;
            power /= 2;
        }
        return output;
    }
};
