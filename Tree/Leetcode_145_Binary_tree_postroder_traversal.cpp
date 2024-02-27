/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
    Input: root = [1,null,2,3]
    Output: [3,2,1]

Example 2:
    Input: root = []
    Output: []

Example 3:
    Input: root = [1]
    Output: [1]

###Constraints:
    The number of the nodes in the tree is in the range [0, 100].
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
    void postorder(TreeNode* root, vector<int> &v)
    {
        if (root == NULL)
            return;
        
        postorder(root->left, v);
        postorder(root->right, v);
        v.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        if ( root == NULL )
            return vec;

        postorder(root, vec);
        return vec;
    }
};

//ITERATIVE APPROACH  : Using Stack
/* Time complexity : O(N)
Space complexity : o(N)
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        if ( root == NULL )
            return vec;

        stack<TreeNode*> st;
        TreeNode *  curr = root, *last = NULL;
        while (!st.empty() || curr)
        {
            if (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode* temp = st.top();
                if (temp->right && temp->right != last)
                    curr = temp->right;
                else
                {
                    st.pop();
                    vec.push_back(temp->val);
                    last = temp;
                }
            }
        }
        return vec;
    }
};