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
class FindElements {
public:
    TreeNode* rt;
    FindElements(TreeNode* root) {
        rt=root;
        recover(rt,0);
    }
    unordered_set<int>s;
    void recover(TreeNode* node, int val) {
        if(node==NULL) return;
        node->val = val; // Recover the current node's value
        s.insert(val);
        recover(node->left, 2*val+1); // Recover left subtree
        recover(node->right, 2*val+2); // Recover right subtree
    }

    bool find(int target) {
        return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */