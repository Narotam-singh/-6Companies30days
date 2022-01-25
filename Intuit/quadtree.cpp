class Solution {
public:
    
    Node* solve(Node* &root,vector<vector<int>> &grid,int i,int j,int s)
    {
        /*if(r*c==1)
        {
            root=new Node(grid[i][j],true);
            return;
        }*/
        
        if(s==0)
            return NULL;
        int cnt=0;
        Node* temp=root;
        for(int ii=i;ii<i+s;ii++)
        {
            for(int jj=j;jj<j+s;jj++)
                cnt+=grid[ii][jj];
        }
        if(cnt==0)
        {
            temp=new Node(0,1);
            return temp;
        }
        if(cnt==(s)*(s))
        {
            temp=new Node(1,1);
            return temp;
        }
        Node* _topLeft=NULL; Node* _topRight=NULL; Node* _bottomLeft=NULL; Node* _bottomRight=NULL;
        temp=new Node(1,0);
        temp->topLeft=solve(_topLeft,grid,i,j,s/2);
        temp->topRight=solve(_topRight,grid,i,j+s/2,s/2);
        temp->bottomLeft=solve(_bottomLeft,grid,i+s/2,j,s/2);
        temp->bottomRight=solve(_bottomRight,grid,i+s/2,j+s/2,s/2);
        //root=new Node(1,0,_topLeft,_topRight,_bottomLeft,_bottomRight);
        return temp;
        
    }
    
    Node* construct(vector<vector<int>>& grid) {
        Node* root=NULL;
        root=solve(root,grid,0,0,grid.size());
        return root;
    }
};