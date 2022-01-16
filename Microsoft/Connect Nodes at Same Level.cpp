class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       if(root==NULL)
    return ;
   

    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);
    Node *temp=NULL;
    //int k=0,level=0;
    int k=1;
    while(!q.empty())
    {
           
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            //if(level==k)
            
        //sumo+=node->data;
        if(k!=1)
        {
            //cout<<temp->data<<" ";
            temp->nextRight=node;
            temp=node;
            k++;
        }
        else
        {
            temp=node;
            //cout<<temp->data<<" ";
            k++;
        }
        if(node->left!=NULL)
        q.push(node->left);
        if(node->right!=NULL)
        q.push(node->right);
        
        }
        else if(!q.empty())
        {
            k=1;
            q.push(NULL);
            temp=NULL;
        }
        
        //max1=max(max1,sum);
    }
    
    }    
      
};