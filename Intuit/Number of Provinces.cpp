class Solution {
    
public:
    
    int get(vector<vector<int>> &adj,vector<bool> &vis,int idx)
    {
        if(vis[idx])
            return 0;
        int ans=1;
        vis[idx]=1;
        for(auto x:adj[idx])
        {
            if(!vis[x])
            {
                ans+=get(adj,vis,x);
                vis[x]=1;
            }
        }
        return ans;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(isConnected[i][j])
                    adj[i].push_back(j);
        }
        vector<bool> vis(n,0);
        vector<int> comp;
        for(int i=0;i<n;i++)
            if(!vis[i])
                comp.push_back(get(adj,vis,i));
        return comp.size();
    }
};