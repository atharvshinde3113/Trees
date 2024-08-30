// greatest val that is <= key

int floor(Node* root, int x) {
        // Code here
        if(!root) return -1;
        int temp = -1;
        while(root){
            if(root->data == x){
                temp = root->data;
                return temp;
            }
            if(root->data > x){// floor > val. cond fails, find smaller vals
                root=root->left;
            }
            else{
                temp = root->data;
                root=root->right; //make floor as large as possible
            }
        }
        return temp;
    }

