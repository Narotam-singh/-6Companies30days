class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        
        if(N<3)
        return {}; 
        vector<int> s(N),g(N);
        s[0]=arr[0];
        g[N-1]=arr[N-1];
        for(int i=1;i<N;i++)
        s[i]=min(s[i-1],arr[i]);
        for(int i=N-2;i>=0;i--)
        g[i]=max(g[i+1],arr[i]);
        for(int i=0;i<N;i++)
        {
            if(arr[i]>s[i]&&arr[i]<g[i])
            return {s[i],arr[i],g[i]};
        }
        return {};
        
    }
};