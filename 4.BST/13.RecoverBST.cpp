/* swap any 2 nodes so that the given BST is a valid one

Brute: do any traversal, sort it, you now have the correct inorder traversal of the BST. do an inorder traversal and compare node's val with the the stored correct inorder and change.

change the node->val when you visit the node TC nlogn+n+n SC n

Optimal: first mid last pointers whenever violation of BST rule occurs
o(n) TC o(1) sc if morris traversal
*/
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;
    TreeNode* prev;

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        //Node is reached. Perform Operations 
        if(prev!=NULL && prev->val > root->val){ //a[i] < a[i-1] BST fails


            if(first==NULL){ // this is the first violation. mark these nodes as first and mid
                first = prev;
                mid = root;
            }
            else{
            	// 2nd violation as first has some value. mark this node as last
                last = root;
            }
        }
        prev = root; //progress forward
        inorder(root->right);
    }



    void recoverTree(TreeNode* root) {
        first=mid=last=NULL;
        TreeNode* prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first!=NULL && last!=NULL) swap(first->val,last->val); // 2 violations exists
        else if(first && mid) swap(first->val,mid->val); // 1 violation exists
    }

