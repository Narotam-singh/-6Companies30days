class Solution
{
	public:
	
	void dfs(vector<int> v[],int i,vector<bool> &vis,int p)
	{
	    //if(vis[i])
	    //return;
	    vis[i]=true;
	    for(auto x:v[i])
	    {
	        if(!vis[x])
	        if(x!=p)
	        dfs(v,x,vis,i);
	    }
	}
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
       vector<int>::iterator it1 = find(adj[c].begin(),adj[c].end(),d);
        if(it1 != adj[c].end()){
            adj[c].erase(it1);
        }
        vector<int>::iterator it2 = find(adj[d].begin(),adj[d].end(),c);
        if(it2 != adj[d].end()){
            adj[d].erase(it2);
        }
        
        vector<bool> vis(V+1,false);

        dfs(adj,c,vis,-1);

       return (vis[d]==0);
    }
};