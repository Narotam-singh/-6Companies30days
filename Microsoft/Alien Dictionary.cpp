class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K]; 
        vector<int> indeg(K,0);
        for(int i=0;i<N-1;i++)
        {
            string s1=dict[i],s2=dict[i+1];
            for(int j=0;j<s1.size()&&j<s2.size();j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    indeg[s2[j]-'a']++;
                    break;
                }
            }
        }
        queue<int> q;
        for(int i=0;i<K;i++)
        {
            if(indeg[i]==0)
            q.push(i);
        }
        string ans;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            ans+=x+'a';
            for(int y:adj[x])
            {
                indeg[y]--;
                if(indeg[y]==0)
                q.push(y);
            }
        }
        return ans;
    }
};