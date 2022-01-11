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
       

        if (node->data == target) 
        {
            ans = max( ans, height(node->right) );
            ans = max( ans, height(node->left) );
            return 1;
        }
       
        

        int res = find(node->right, target, ans);
        if (val!=0)
          
        {
            ans = max( ans, res + height(node->left) );
          
            return res + 1;
        }
        res = find(node->left, target, ans);
        if (val!=0)
         
        {
            ans = max( ans, res + height(node->right) );
            
            return res + 1;
        }

        return 0;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
          int ans = 0;
        find(root, target, ans);
        return ans;
        
    }
};