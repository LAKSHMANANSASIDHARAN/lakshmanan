/* Todays problem is very simple and easy .We are going to take one number as n and start addition from 1 to that n . Now the questions is 
there is some  addition of subnumbers in between 1 to n give the same value that has given by total sum 1 to n.
Its sounds like easy but implementation of code is task*/

    int pivotInteger(int n) {
       vector<int> arr1;
        vector<int> arr2;
        int Firstsum = 0;
        int Secondsum = 0;
        int i = 1, j = n;

      /* we going to take two array and do addition from 1 to n and store that all value in first array and do addition from n to 1 and store that all value 
      in second array*/
        while (i <= n && j >= 1) {
            Firstsum += i;
            arr1.push_back(Firstsum);
            Secondsum += j;
            arr2.push_back(Secondsum);
            i++;
            j--;
        }
       /*Now compare last value from array one and frist value from array two . Do this until we find the same value and return the number*/
     
        int l = 0, r = arr2.size() - 1;
        while (l < arr1.size() && r >= 0) {
            if (arr1[r] == arr2[l]) {
                return n - l;
            }
            l++;
            r--;
        }
        return -1;
    }
// Time complexity is O(n)
//space complexity is O(n)

