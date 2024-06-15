/* doesnt consume any extra space : O(1) space. o(n) time complexity. Have to visit all the nodes. Amortised TC is O(n) as all iterations together will use O(N). uses the concept of threaded binary tree.

inorder: Left Root Right

We can achieve a non-recursive inorder traversal without using extra space by modifying the binary tree itself.

1. We start with the current node as the root.
2. While the current node is not NULL, we do the following:

   1. If the current node does not have a left child, we visit the current node(i.e print it) and move to its right child.

   2. If the current node has a left child, we find the rightmost node of its left subtree.

     2.a If the rightmost node has a right child, we make the right child point to the current node and move to the left child.(i.e make the threaded yellow connection)

     2.b If the rightmost node already has a right child (which points back to the current node), we reset the right child to NULL, visit the current node, and move to its right child.

     this mechanism is to determine that once you reach curr via a preexisting thread we need to determine whether to move left or to right.

3. We repeat this process until we have visited all the nodes in the tree.

*/

vector<int> inOrder(Node* root) {
    vector<int> inOrder;
    Node* curr = root;

    while (curr) {
        if (curr->left == NULL) { //case 1 no left. print curr and move right
            inOrder.push_back(curr->data);
            curr = curr->right;
        } else {
            Node* prev = curr->left;
            while (prev->right && prev->right != curr){
                prev = prev->right;
            }
            //prev is now at the rightmost part
            if (prev->right == NULL) { //rightmost's next is null i.e it is not threaded
                prev->right = curr;
                curr = curr->left;
            } else {
                inOrder.push_back(curr->data);
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }

    return inOrder;
}
---------------------------------------------------------------
Preorder:

vector<int> preOrder(TreeNode* root) {
    vector<int> preOrder;
    TreeNode* curr = root;

    while (curr) {
        if (curr->left == NULL) { //case 1 no left. print curr and move right
            preOrder.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;
            while (prev->right && prev->right != curr){
                prev = prev->right;
            }
            //prev is now at the rightmost part
            if (prev->right == NULL) { //rightmost's next is null i.e it is not threaded
                prev->right = curr;
                preOrder.push_back(curr->val); //print the data when it reaches to curr via a thread.
                curr = curr->left;
            } else {
                
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }

    return preOrder;
}