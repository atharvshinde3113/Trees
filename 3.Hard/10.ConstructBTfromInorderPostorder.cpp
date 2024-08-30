

    TreeNode* solve(vector<int>& inorder, int inStart, int inEnd,vector<int>& postorder,int postStart, int postEnd, map<int, int>& nodeToIndex) {
        if (postStart > postEnd || inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);// root of the tree

        int inRoot = nodeToIndex[postorder[postEnd]]; // index of where is root in the hashmap
        int numsLeft = inRoot - inStart; // no of elements in LHS

        root->left = solve(inorder, inStart, inRoot-1,postorder,postStart,postStart+numsLeft-1, nodeToIndex);
        root->right = solve(inorder, inRoot+1, inEnd,postorder,postStart+numsLeft,postEnd-1, nodeToIndex);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        
        map<int, int> nodeToIndex; //inorder hashmap
        for (int i = 0; i < inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
        
        return solve(inorder, 0, inorder.size()-1,postorder,0,postorder.size()-1, nodeToIndex);
    }