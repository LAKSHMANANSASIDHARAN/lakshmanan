/* Capacity To Ship Packages Within D Days
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
Example 1:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:
Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1*/
class Solution {
    int process(vector<int>& weights, int temp) {
        int day = 1, sum = 0; 
        for (int w : weights) {
            if (sum + w > temp) {
                day++;
                sum = 0;
            }
            sum += w;
        }
        return day;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0, sum = 0;
        for (int w : weights) {
            sum += w;
            maxi = max(maxi, w);
        }
        int left = maxi, right = sum, ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            int temp = process(weights, mid);
            if (temp <= days) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
/*class Solution {
    int process(vector<int>& weights, int temp) {
        int day = 1, sum = 0; 
        for (int w : weights) {
            if (sum + w > temp) {
                day++;
                sum = 0;
            }
            sum += w;
        }
        return day;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0, sum = 0;
        for (int w : weights) {
            sum += w;
            maxi = max(maxi, w);
        }
        int left = maxi, right = sum, ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            int temp = process(weights, mid);
            if (temp <= days) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
/*Maximum Twin Sum of a Linked List
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.
Given the head of a linked list with even length, return the maximum twin sum of the linked list.
Example 1:
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 
Example 2:
Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
Example 3:
Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.*/
class Solution {
public:
    int pairSum(ListNode* head) {
        deque<int>temp;
        int sum=0,maxi=0;
        ListNode*dup=head;
           while (dup != nullptr) {
            temp.push_back(dup->val);
            dup = dup->next;
        }
        while(!temp.empty()){
        sum=temp.front()+temp.back();
        maxi=max(maxi,sum);
        temp.pop_back();
        temp.pop_front();
    }
    return maxi;
    }
};
