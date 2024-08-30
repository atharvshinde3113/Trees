/* preorder + postorder: cant create a unique BT
inorder + pre/post order : can create a unique BT
however can create a BT in any cases

preorder: Root Left Right

Inorder: Left Root Right

first element in preorder vector is the root of the tree. you have to search this element in inorder vector. All elements left to this in inorder form left subtree and to the right form right subtree

therefore, has the inorder, as youll have to visit it frequently.

Assume there are x elements left of val found in inorder. this will be the inorder of the new subtree. 
Now, take x elements from ahead of root in preorder. This is the 2nd preorder.

Same for right: Ele right of root in inorder = new inorder for right subtree
Remaining ele in preorder = new preorder for right subtree 

^^^ Keep on doing this (recursion)
*/
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int,int> inordermap;
    for (int i = 0; i < inorder.size(); ++i)
    {
        inordermap[inorder[i]]=i;
    }
    TreeNode* root = solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inordermap);
    return root;
}

TreeNode* solve(vector<int>& preorder,int preStart, int preEnd, vector<int>& inorder,int inStart, int inEnd, map<int,int>& inordermap){
    if(preStart>preEnd || inStart>inEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);

    int inRoot = inordermap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = solve(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inordermap);

    root->right = solve(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inordermap);

    return root;
}