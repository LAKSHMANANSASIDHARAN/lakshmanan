/*Number of 1 Bits
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
Example 1:
Input: n = 11
Output: 3
Explanation:
The input binary string 1011 has a total of three set bits.
Example 2:
Input: n = 128
Output: 1
Explanation:
The input binary string 10000000 has a total of one set bit.
Example 3:
Input: n = 2147483645
Output: 30
Explanation:
The input binary string 1111111111111111111111111111101 has a total of thirty set bits.*/
class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        count=__builtin_popcount(n);
        while(n>1){
            count+=n%2;
            n/=2;
            }
            return count;
    }
};
/*Sort List
Given the head of a linked list, return the list after sorting it in ascending order.
Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:
Input: head = []
Output: []
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr or head->next==nullptr){
            return head;
        }
        vector<int>arr;
        ListNode*temp=head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        int i=0;
        temp=head;
        while(temp!=nullptr){
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }
      //  delete temp;
        return head;
        
    }
};
/* Kth Largest Element in an Array
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?
Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     sort(nums.begin(),nums.end());
      int i=nums.size()-1;
      int res;
      int count=1;
      while(i>=0){
        if(count==k){
            res=nums[i];
            break;
        }
        i--;
        count++;
     }
     return res;
    }
};
