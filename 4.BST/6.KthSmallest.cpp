// inorder of any BST is in sorted order. cnt =  count of nodes visited so far

// when you reach at a node-> cnt++, if(cnt==k) return node->val

// can also do morris traversal for o(1) SC

void inorder(TreeNode* root, int k, int& cnt, int& ans) { //cnt and ans pass by reference
    if (!root) return;
    inorder(root->left, k, cnt, ans);

    //Node reached
    cnt++;
    if (cnt == k) {
        ans = root->val;
        return;
    }

    inorder(root->right, k, cnt, ans);
}

int kthSmallest(TreeNode* root, int k) {
    int ans = -1, cnt = 0;
    inorder(root, k, cnt, ans);
    return ans;
}
