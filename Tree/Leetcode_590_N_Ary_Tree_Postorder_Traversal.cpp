/*
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal. 
Each group of children is separated by the null value (See examples)

Example 1:
    Input: root = [1,null,3,2,4,null,5,6]
    Output: [5,6,3,2,4,1]

Example 2:
    Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 
Constraints:
    The number of nodes in the tree is in the range [0, 10^4].
    0 <= Node.val <= 10^4
    The height of the n-ary tree is less than or equal to 1000.
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/
//RECURSIVE APPROACH
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
    void posttraversal ( Node * root, vector<int> &v)
    {
        if (root == NULL)
            return;
        
        for ( auto x : root->children)
            posttraversal(x, v);
        
        v.push_back(root->val);
        
    }
    vector<int> postorder(Node* root) {

        vector<int> vec;
        if (root == NULL)
            return vec;

        posttraversal (root, vec);
        return vec;
    }
};

//ITERATIVE APPROACH
class Solution {
public:
    vector<int> postorder(Node* root) {

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
            for (auto x : root->children)
                st.push(x);
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};