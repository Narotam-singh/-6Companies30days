void set1(Node* root)
{
    if(root==NULL)
    return;
    if(root->left!=NULL)
    set1(root->left);
    if(root->right!=NULL)
    set1(root->right);
    if(root->left!=NULL)
    root->data+=root->left->data;
    if(root->right!=NULL)
    root->data+=root->right->data;
}

void inorder(Node* root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int find(Node* root,int x)
{
    if(root==NULL)
    return 0;
    if(root->data==x)
    return 1+find(root->left,x)+find(root->right,x);
    return find(root->left,x)+find(root->right,x);
}

//Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	set1(root);
	//inorder(root);
	return find(root,X);
	return 0;
	
}