/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
    Input: root = [1,null,2,3]
    Output: [1,3,2]

Example 2:
    Input: root = []
    Output: []

Example 3:
    Input: root = [1]
    Output: [1]
 
###Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 
Follow up: Recursive solution is trivial, could you do it iteratively?
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


//RECURSIVE APPROACH
/* Time complexity : O(N)
Space complexity : o(1)
*/
class Solution {
public:
    void inorder(TreeNode * root,  vector<int> & vec)
    {
        if (root == NULL)
            return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        
        inorder(root, res);
        return res;
    }
};

//ITERATIVE APPROACH  : Using Stack
/* Time complexity : O(N)
Space complexity : o(N)
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        
        stack<TreeNode*> s;
        TreeNode * temp = root;
        while(temp || !s.empty())
        {
            while (temp)
            {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            res.push_back(temp->val);
            s.pop();
            temp = temp->right;
        }
        return res;
    }
};