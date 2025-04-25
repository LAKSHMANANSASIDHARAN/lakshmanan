/*Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:
Input: lists = []
Output: []
Example 3:
Input: lists = [[]]
Output: []
 */
class Solution {
    void process(ListNode*head,  priority_queue<int>&pq){
        ListNode*temp=head;
        while(temp!=NULL){
            pq.push(temp->val);
            temp=temp->next;
        }

    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<int>pq;
       for(int i=0;i<lists.size();i++){
        process(lists[i],pq);
       }
       vector<int>arr;
       while(!pq.empty()){
        arr.push_back(pq.top());
        pq.pop();
       }
       reverse(arr.begin(),arr.end());
     if (arr.empty()) return NULL;

        ListNode* res = new ListNode(arr[0]);
        ListNode* temp = res;
        for (int i = 1; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }

        return res;
    }
};
/*Ugly Number
An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.
Given an integer n, return true if n is an ugly number.
Example 1:
Input: n = 6
Output: true
Explanation: 6 = 2 × 3
Example 2:
Input: n = 1
Output: true
Explanation: 1 has no prime factors.
Example 3:
Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.*/
class Solution {
public:
    bool isUgly(int n) {
     if(n<=0){
        return false;
     }
     while(n%2==0) n/=2;
      while(n%3==0) n/=3;
       while(n%5==0) n/=5;
       return n==1;
    }
};
