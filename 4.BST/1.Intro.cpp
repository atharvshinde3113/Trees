/* Left<node<right no presence of =	
every node left of root should be smaller than root
every node right of root should be larger than root
entire left subtree and right subtree should be a BST

ht of BST is generally log2(n). general TC is log2(n) as youre performing BS on a tree

A binary search tree is considered valid if its inorder traversal is in increasing order.


leftmost ele in BST is smallest, rightmost is largest
*/

bool isValidBST(vector<int> &order) {
    for (int i = 1; i < order.size(); i++) {
        if (order[i - 1] >= order[i]) {
            return false;
        }
    }
    return true;
}


//Search in a BST
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    if (root->val > val) return searchBST(root->left, val);
    else return searchBST(root->right, val);
}

//Min Val in BST == leftmost node
int minVal(Node* root) {
    if (!root) return -1;
    while (root->left)
        root = root->left;
    return root->data;  
}
