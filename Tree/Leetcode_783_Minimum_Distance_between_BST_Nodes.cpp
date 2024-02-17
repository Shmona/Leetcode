/*
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two
different nodes in the tree.

Example 1:
    Input: root = [4,2,6,1,3]
    Output: 1

Example 2:
    Input: root = [1,0,48,null,null,12,49]
    Output: 1

###Constraints:
    The number of nodes in the tree is in the range [2, 100].
    0 <= Node.val <= 10^5
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
    void inorder (TreeNode * root, vector<int> &vec)
    {
        if (root == NULL)
            return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);

        int ans = INT_MAX;
        for ( int i = 0; i < vec.size()-1; i++)
        {
            for ( int j = i + 1; j < vec.size(); j++)
                ans = min(ans, vec[j]- vec[i]);
        }
        return ans;
    }
};