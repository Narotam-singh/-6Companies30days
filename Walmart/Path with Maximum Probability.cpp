class Solution {
    int inf=1e7;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end)      {
        for(int i=0;i<succ.size();i++)
            succ[i]=-log10(succ[i]);
        vector<vector<pair<int,double>>> graph(n);
        vector<double> dist(n,inf);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],succ[i]*1.0});
            graph[edges[i][1]].push_back({edges[i][0],succ[i]*1.0});
        }
        dist[start]=0.0;
        set<pair<double,int>> s;
        s.insert({0.0,start});
        while(!s.empty())
        {
            auto x= *(s.begin());
            s.erase(x);
            for(auto it:graph[x.second])
            {
                if(dist[it.first]>dist[x.second]+it.second)
                {
                    s.erase({dist[it.first],it.first});
                    dist[it.first]=dist[x.second]+it.second; 
                    s.insert({dist[it.first],it.first});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(end==i)
                return pow(10,-dist[i]);
        }
        return 0;
    }
};