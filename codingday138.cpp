/*2236. Root Equals Sum of Children
You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.
Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.
Example 1:
Input: root = [10,4,6]
Output: true
Explanation: The values of the root, its left child, and its right child are 10, 4, and 6, respectively.
10 is equal to 4 + 6, so we return true.
Example 2:
Input: root = [5,3,1]
Output: false
Explanation: The values of the root, its left child, and its right child are 5, 3, and 1, respectively.
5 is not equal to 3 + 1, so we return false.*/
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root->val==root->left->val+root->right->val) return true;
        return false;
    }
};
/*1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
Given two binary trees original and cloned and given a reference to a node target in the original tree.
The cloned tree is a copy of the original tree.
Return a reference to the same node in the cloned tree.
Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.
Example 1:
Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.
Example 2:
Input: tree = [7], target =  7
Output: 7
Example 3:
Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4*/
class Solution {
    TreeNode* ans(TreeNode* cloned, TreeNode* target) {
        if (!cloned) return nullptr;
        if (cloned->val == target->val) return cloned;
        TreeNode* left = ans(cloned->left, target);
        if (left) return left;
        return ans(cloned->right, target);
    }

public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return ans(cloned, target);
    }
};
/*2331. Evaluate Boolean Binary Tree
You are given the root of a full binary tree with the following properties:
Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
The evaluation of a node is as follows:
If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
Return the boolean result of evaluating the root node.
A full binary tree is a binary tree where each node has either 0 or 2 children.
A leaf node is a node that has zero children.
Example 1:
Input: root = [2,1,3,null,null,0,1]
Output: true
Explanation: The above diagram illustrates the evaluation process.
The AND node evaluates to False AND True = False.
The OR node evaluates to True OR False = True.
The root node evaluates to True, so we return true.
Example 2:
Input: root = [0]
Output: false
Explanation: The root node is a leaf node and it evaluates to false, so we return false.*/
class Solution {
public:
    bool evaluateTree(TreeNode* root) {

        if(root->left==nullptr && root->right==nullptr){
            return root->val;
        }
        int op=root->val;
        int left=evaluateTree(root->left);
        int right=evaluateTree(root->right);
        if(op==2){
            if(left==1 or right==1)return true;
        }
        else if(left==1 && right==1){
            return true;
        }
        return false;
    }
};
/*700. Search in a Binary Search Tree
You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
Example 1:
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:
Input: root = [4,2,7,1,3], val = 5
Output: []*/
class Solution {
    void search(TreeNode*root,int val,bool& check,TreeNode* &ans){
     if(root==nullptr || check){
            return ;
        }
        if(root->val==val) {
          ans=root;
          check=true;
        }
        search(root->left,val,check,ans);
        search(root->right,val,check,ans);

    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
    
      bool check=false;
      TreeNode*ans=nullptr;
      search(root,val,check,ans);
      return ans;
        }
};
