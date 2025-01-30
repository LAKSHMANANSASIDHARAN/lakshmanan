 /*A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself.  
Given an integer `n`, return `true` if `n` is a perfect number, otherwise return `false`.  
Example 1:  
Input: `num = 28`  
Output: `true`  
Example 2:  
Input: `num = 7`  
Output: `false*/`
bool isPerfectNumber(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}
/*Given a non-empty array of integers `nums`, every element appears twice except for one. Find that single one.  
Example 1:  
Input: `nums = [2,2,1]`  
Output: `1`  
Example 2:  
Input: `nums = [4,1,2,1,2]`  
Output: `4`  
Example 3:  
Input: `nums = [1]`  
Output: `1`*/
int singleNumber(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }
        if (count == 1) {
            return nums[i];
        }
    }
    return -1;
}

/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.  
Given a string `s`, return `true` if it is a palindrome, or `false` otherwise. 
Example 1:  
Input: `s = "A man, a plan, a canal: Panama"`  
Output: `true`  
Example 2:  
Input: `s = "race a car"`  
Output: `false`*/ 
bool isPalindrome(string s) {
    string str = "";
    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) {
            str += tolower(s[i]);
        }
    }
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
/*Given an integer `n`, return a string array answer (1-indexed) where:  
 answer[i] == "FizzBuzz" if i is divisible by 3 and 5.  
 answer[i] == "Fizz" if i is divisible by 3.  
 answer[i] == "Buzz" if i is divisible by 5.  
 answer[i] == i (as a string) if none of the above conditions are true.
Example 1:  
Input: `n = 3`  
Output: `["1","2","Fizz"]`
Example 2:  
Input: `n = 5`  
Output: `["1","2","Fizz","4","Buzz"]`
Example 3:  
Input: `n = 15`  
Output:  
`["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]`*/
vector<string> fizzBuzz(int n) {
    vector<string> result;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            result.push_back("FizzBuzz");
        } else if (i % 3 == 0) {
            result.push_back("Fizz");
        } else if (i % 5 == 0) {
            result.push_back("Buzz");
        } else {
            result.push_back(to_string(i));
        }
    }
    return result;
}
/*Given a string `date` representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.
Example 1:  
Input: `date = "2019-01-09"`  
Output: `9`
Example 2:  
Input: `date = "2019-02-10"`  
Output: `41`*/
int dayOfYear(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        daysInMonth[1] = 29;
    }

    int totalDays = 0;
    for (int i = 0; i < month - 1; i++) {
        totalDays += daysInMonth[i];
    }
    totalDays += day;

    return totalDays;
}

/*Imagine you're on a quest to discover never-ending loops. Create a program that demonstrates two types of endless journeys: one using a for loop 
and another using a while loop. How will you set up these loops to keep running forever, showcasing their infinite nature?*/
for (int i = 0; i >= 0; i++) {
    cout << "This is a never-ending for loop" << endl;
}

int j = 0;
while (j >= 0) {
    cout << "This is a never-ending while loop" << endl;
}
/*Imagine you need to repeat a cheerful message. Write a program that uses a for loop to print "ALL IS WELL" exactly twenty times. How will you set up your loop to ensure this
message appears the right number of times?*/
for (int i = 0; i < 20; i++) {
    cout << "ALL IS WELL" << endl;
}
/*There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.
You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.
Example 1:
Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
Example 2:
Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.*/
int largestAltitude(vector<int>& gain) {
        int maxi=0,sum=0;
        int i=0;// do the prefix sum and find the maximum by comparing each number
        while(i<gain.size()){
            sum=sum+gain[i];
            maxi=max(maxi,sum);
            i++;
        }
        return maxi;
/*Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".
Example 1:
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"*/
string defangIPaddr(string address) {
        string s2="";
        int i=0;
        while (i<address.size()){
          //if we found the . the add "[.]"
            if(address[i]=='.'){
                s2=s2+"[.]";
            }
              else{
                s2=s2+address[i];
            }
            i++;
        }
        return s2;
/*You're given strings jewels representing the types of stones that are jewels, and 
stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
Letters are case sensitive, so "a" is considered a different type of stone from "A".
Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0*/
int numJewelsInStones(string jewels, string stones) {
     unordered_map<char,int>hashmap;
     for (auto i:jewels){
        hashmap[i]=0;
     }   
     int sum=0;
     for(int i=0;i<stones.size();i++){
        if(hashmap.find(stones[i])!=hashmap.end()){
          sum+=1;
        }

     }
     return sum;


