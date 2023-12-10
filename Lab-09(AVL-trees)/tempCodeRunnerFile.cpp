        node *temp=Inpre(root->left);
        root->data=temp->data;
        root->left=deletebst(root->left, temp->data);