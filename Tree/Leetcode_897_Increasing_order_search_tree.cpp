/*
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in 
the tree is now the root of the tree, and every node has no left child and only one right child.

Example 1:
    Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
    Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

Example 2:
    Input: root = [5,1,7]
    Output: [1,null,5,null,7]

###Constraints:
    The number of nodes in the given tree will be in the range [1, 100].
    0 <= Node.val <= 1000
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
class Solution {
public:
    void inorder(TreeNode * root,  TreeNode * &res)
    {
        if (root == NULL)
            return;

        inorder(root->left, res);
        res->right = new TreeNode(root->val);
        res = res->right;
        inorder(root->right, res);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode();
        TreeNode *temp = res;
        inorder(root, temp);
        return res->right;
    }
};

// Other way: using vector 
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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);

        TreeNode* res = NULL, *temp;

        for (auto x : arr)
        {
            if (res == NULL)
            {
                res = new TreeNode(x);
                temp = res;
            }
            else
            {
                temp->right = new TreeNode(x);
                temp = temp->right;
            }
        }
        return res;
    }
};