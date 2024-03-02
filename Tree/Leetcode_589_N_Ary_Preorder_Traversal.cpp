/*
Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. 
Each group of children is separated by the null value (See examples)

 

Example 1:
    Input: root = [1,null,3,2,4,null,5,6]
    Output: [1,3,5,6,2,4]

Example 2:
    Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 
Constraints:
    The number of nodes in the tree is in the range [0, 10^4].
    0 <= Node.val <= 10^4
    The height of the n-ary tree is less than or equal to 1000.
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/
//RECUSRIVE APPROACH
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void pretraversal(Node* root, vector<int> & v)
    {
        if (root == NULL)
            return;

        v.push_back(root->val);
        for(auto x : root->children)
            pretraversal(x, v);
    }
    vector<int> preorder(Node* root) {
        vector<int> vec; 
        if (root == NULL)
            return vec;
        pretraversal(root, vec);
        return vec; 
    }
};

//ITERATIVE APPROACH

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> vec; 
        if (root == NULL)
            return vec;
        
        stack<Node*> st;
        st.push(root);

        while (!st.empty())
        {
            root = st.top();
            st.pop();
            vec.push_back(root->val);
            int n = root->children.size();
            for (int i = n-1; i >=0 ; i--)
                st.push(root->children[i]);
        }
        return vec; 
    }
};