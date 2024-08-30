/*
Question:

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. 

boolean hasNext() Returns true if there exists a number in the inorder traversal to the right of the pointer, otherwise returns false.

int next() Moves the pointer to the right, then returns the number at the pointer.

Approach:
- stack to keep track of the nodes during the inorder traversal

- In the constructor initialize the stack by pushing all the leftmost nodes in the BST to the stack. go to extreme left( as it is Left Root Right )

- The next() function returns the top element of the stack (which will be the next smallest element in the BST) and pops it from the stack.

- If the node has a right child, we push all the leftmost nodes in the right subtree to the stack before returning the node's value.

- The hasNext() function simply checks if the stack is empty or not.

O(H) SC | O(1) TC for calling next() and hasNext() O(H) TC for constructor
*/


//Brute: Do an inorder traversal store it and return

stack<TreeNode*> st;

BSTIterator(TreeNode* root) {
    pushLeft(root);
}

void pushLeft(TreeNode* root) {
    while (root) {
        st.push(root);
        root = root->left;
    }
}

int next() {
    TreeNode* ans = st.top();
    st.pop();
    if (ans->right) {
        pushLeft(ans->right);
    }
    return ans->val;
}

bool hasNext() {
    return (!st.empty());
}


// the first time next() is called, it'll be inorder's first element which is the leftmost element
 

// to implement before() -> push all rights. Right Node left traversal = descending order