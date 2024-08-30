// inorder traversal is sorted. store it in an array, do the same 2 pointer 2 sum math on the array O(2N) O(N)

 void inorder(TreeNode* root, vector<int> &inn) {
        if(root == NULL)
            return;

        inorder(root->left, inn);
        inn.push_back(root->val);
        inorder(root->right, inn);
    }


    bool findTarget(TreeNode* root, int k) {
        vector<int> ino;
        inorder(root, ino);

        int i=0;
        int j=ino.size()-1;

        while(i<j) {
            int sum = ino[i] + ino[j];
            
            if(sum == k)
                return true;
            else if (sum > k)
                j--;
            else
                i++;
        }
        return false;
    }


/*
 2 iterators: BSTIterators, next() and before()

- The next() function returns the next smallest element in the BST by popping the top element from the left stack and pushing all the leftmost nodes in its right subtree to the stack.
- The before() function returns the next largest element in the BST by popping the top element from the right stack and pushing all the rightmost nodes in its left subtree to the stack.

apply 2 pointer logic with these iterators
*/

stack<TreeNode*> stl;
stack<TreeNode*> str;

void pushLeft(TreeNode* root) {
    while (root) {
        stl.push(root);
        root = root->left;
    }
}

void pushRight(TreeNode* root) {
    while (root) {
        str.push(root);
        root = root->right;
    }
}

int next() {
    if (stl.empty()) return 1e9; //flag
    TreeNode* ans = stl.top();
    stl.pop();
    if (ans->right) {
        pushLeft(ans->right);
    }
    return ans->val;
}

int before() {  // Right Node Left Traversal
    if (str.empty()) return 1e9;
    TreeNode* ans = str.top();
    str.pop();
    if (ans->left) {
        pushRight(ans->left);
    }
    return ans->val;
}

bool findTarget(TreeNode* root, int k) {
    pushLeft(root);
    pushRight(root);

    int l = next();
    int r = before();
    while (l < r) {
        if (l == 1e9 || r == 1e9) return false;
        if (l + r == k) return true;
        else if (l + r < k) l = next(); //smaller so increase.
        else r = before(); // larger so decrease
    }

    return false;
}

