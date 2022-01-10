class Solution {
public:
    bool isvalid(int i,int j,int m,int n)
    {
        if(i>=0&&i<m&&j>=0&&j<n)
            return 1;
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<pair<int,pair<int,int>>> vp;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    vp.push_back({0,{i,j}});
            }
        }
        int ans=0;
        for(int k=0;k<vp.size();k++)
        {
            int i=vp[k].second.first,j=vp[k].second.second,h=vp[k].first;
            if(isvalid(i+1,j,m,n)&&grid[i+1][j]==1)
            {
                grid[i+1][j]=2;
                vp.push_back({h+1,{i+1,j}});
            }
            if(isvalid(i,j+1,m,n)&&grid[i][j+1]==1)
            {
                grid[i][j+1]=2;
                vp.push_back({h+1,{i,j+1}});
            }
            if(isvalid(i-1,j,m,n)&&grid[i-1][j]==1)
            {
                grid[i-1][j]=2;
                vp.push_back({h+1,{i-1,j}});
            }
            if(isvalid(i,j-1,m,n)&&grid[i][j-1]==1)
            {
                grid[i][j-1]=2;
                vp.push_back({h+1,{i,j-1}});
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        for(auto x:vp)
        {
            ans=max(ans,x.first);
        }
        return ans;
    }
};