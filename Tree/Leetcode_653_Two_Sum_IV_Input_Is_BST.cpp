/*
Given the root of a binary search tree and an integer k, return true if there exist two elements in the
BST such that their sum is equal to k, or false otherwise.

Example 1:
    Input: root = [5,3,6,2,4,null,7], k = 9
    Output: true

Example 2:
    Input: root = [5,3,6,2,4,null,7], k = 28
    Output: false

###Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
    -10^4 <= Node.val <= 10^4
    root is guaranteed to be a valid binary search tree.
    -10^5 <= k <= 10^5
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
    void Inorder (TreeNode * root, vector<int> &vec)
    {
        if (root == NULL)
            return;

        Inorder(root->left, vec);
        vec.push_back(root->val);
        Inorder(root->right, vec);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        Inorder(root, vec);

        int l = 0, r = vec.size()-1;
        while (l < r)
        {
            int sum = vec[l] + vec[r];
            if (sum == k)
                return true;
            else if (sum > k)
                r--;
            else
                l++;
        }
        return false;
    }
};