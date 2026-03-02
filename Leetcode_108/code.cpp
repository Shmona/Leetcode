#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  
class Solution {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            
            return BST(nums, 0, nums.size() - 1);    
    }
    private:
       TreeNode* BST(vector<int>& nums, int low , int high)
       {
            while(low <= high)
            {
                int mid = low + (high - low)/2;
                TreeNode *root = new TreeNode(nums[mid]);

                root->left = BST(nums, low, mid - 1);
                root->right = BST(nums, mid + 1, high);

                return root;
            }
            return nullptr;
       }
};
//Helper function to show the tree
void inorder(TreeNode* root) 
{
    if (root == nullptr) 
        return;
    
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    Solution sol;
    vector<int> v1 = {-10,-3,0,5,9};
    TreeNode * root = sol.sortedArrayToBST(v1);

    cout << "Inorder Traversal :" << endl;
    inorder(root);

    return 0;
}
