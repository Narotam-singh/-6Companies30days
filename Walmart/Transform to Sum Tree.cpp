class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int sum(Node* node)
    {
        if(node==NULL)
        return 0;
        else if(node->left==NULL&&node->right==NULL)
        {
            int temp=node->data;
            node->data=0;
            return temp;
        }
       
        node->data=sum(node->left)+sum(node->right);
        return node->data;
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        if(node==NULL)
        return;
        int c=sum(node);
    }
};