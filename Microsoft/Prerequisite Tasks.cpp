class Solution{
public:

bool iscycle(int src,vector<vector<int>>&adj,vector<bool>& vis,vector<int>& stack)
{
    stack[src]=true;
    if(!vis[src])
    {
        vis[src]=true;
        for(auto i:adj[src])
        {
            if(!vis[i] && iscycle(i,adj,vis,stack))
            return true;
            if(stack[i])
            return true;
        }
    }
    stack[src]=false;
    return false;
}

	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    int p=pre.size();
	    vector<vector<int>> adj(N);
	    for(int i=0;i<p;i++)
	    {
	        adj[pre[i].first].push_back(pre[i].second);
	    }
	    vector<int> stack(N,0);
	    vector<bool> visited(N,0);
	    bool cycle=false;
	    for(int i=0;i<N;i++)
	    {
	        if(!visited[i] && iscycle(i,adj,visited,stack))
	        cycle=true;
	    }
	    
	    if(cycle)
	    return 0;
	    return 1;
	}
};