class Solution {
public:

    
    
    int maxDistance(vector<vector<int>>& grid) {
         int n=grid.size();
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==0) return -1;
        if(q.size()==n*n) return -1;
        
        int dirx[]={-1,1,0,0};
        int diry[]={0,0,-1,1};
        int d=0;
        
        while(!q.empty()){
            int t=q.size(); 
            while(t--){
            auto [x,y]=q.front(); q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dirx[i]; int ny=y+diry[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]==0){
                    grid[nx][ny]=1;
                    q.push({nx,ny});                    
                }
            }
           }      
            d++;
        }
         
        return d-1;
        
    }
};
