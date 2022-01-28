class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        v[i]={efficiency[i],speed[i]};
        sort(v.begin(),v.end(),greater<int>());
        priority_queue<int,vector<int>,greater<int>> pq;
        long sum=0;
        long ans=0;
        for(auto x : v)
        {
            int eff=x.first,speed=x.second;
            sum+=speed;
            pq.push(speed);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,sum*eff);
        }
        return ans % (int)(1e9+7);
    }
};