/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
1. The left  subtree of a node contains only nodes with keys less than the node's key.
2. The right subtree of a node contains only nodes with keys greater than the node's key.
3. Both the left and right subtrees must also be binary search trees.
 

Example 1:
    Input: root = [2,1,3]
    Output: true

Example 2:
    Input: root = [5,1,4,null,null,3,6]
    Output: false
    Explanation: The root node's value is 5 but its right child's value is 4.

###Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
    -2^31 <= Node.val <= 2^31 - 1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Using Inorder Traversal
/*
Time complexity : O(N)
Space Complexity : O(N)
*/
class Solution {
public:
    void inorder(TreeNode* root, vector<int> & vec)
    {
        if (root == NULL)
            return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    bool isValidBST(TreeNode* root) {

        vector<int> res;
        inorder(root, res);

        int n = res.size();
        for ( int i = 1; i < n; i++)
        {
            if (res[i-1] >= res[i])
                return false;
        }
        return true; 
    }
};

// RECURSIVE APPROACH
/*
Time complexity : O(N)
Space Complexity : O(1)
*/
class Solution {
public:
    bool CompareVal(TreeNode* root, long minVal, long maxVal)
    {
        if (root == NULL)
            return true;
        TreeNode* curr = root;
        if(curr->val >= maxVal || curr->val <= minVal)
            return false;

        return (CompareVal(curr->left, minVal, curr->val) 
                && CompareVal(curr->right, curr->val, maxVal));
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        return CompareVal(root, LONG_MIN, LONG_MAX); 
    }
};