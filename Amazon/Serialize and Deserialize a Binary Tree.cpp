class Solution
{
    public:
    void preorder(Node* root,vector<int> &v)
    {
        if(root==NULL)
        {
            v.push_back(-1);
            return;
        }
        v.push_back(root->data);
        preorder(root->left,v);
        preorder(root->right,v);
    }
    
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> v;
        preorder(root,v);
        //for(int x:v)
        //cout<<x<<" ";
        //cout<<endl;
        return v;
    }
    
    
    //Function to deserialize a list and construct the tree.
    int i=0;
    Node * deSerialize(vector<int> &v)
    {
       //Your code here
        if(i>=v.size()||v[i]==-1)
        {
            i++;
            return NULL;
        }
        Node* root=new Node(v[i++]);
        root->left=deSerialize(v);
        root->right=deSerialize(v);
      
    }

};