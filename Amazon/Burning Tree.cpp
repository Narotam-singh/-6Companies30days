class Solution
{
public:
   int height(Node* node)
    // finding the most distant leaf node from given node
    {
        if (node==NULL) 
        return 0;
        return 1 + max( height(node->left) , height(node->right) );
    }

    int find(Node* node, int target, int &ans)
    {
         if (node==NULL) 
        return 0;
       

        if (node->data == target) {
            ans = max( ans, height(node->right) );
            ans = max( ans, height(node->left) );
            return 1;
        }
       
        

        int val = find(node->right, target, ans);
        if (val)
          
        {
            ans = max( ans, val + height(node->left) );
          
            return val + 1;
        }
        val = find(node->left, target, ans);
        if (val)
         
        {
            ans = max( ans, val + height(node->right) );
            
            return val + 1;
        }

        return 0;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
          int ret = 0;
        find(root, target, ret);
        return ret;
        
    }
};