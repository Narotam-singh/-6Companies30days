class Solution {
public:
    
    
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        if(n<=2)
            return 0;
        map<int,int> mp;
        //for(int i=0;i<n;i++)
          //  cout<<points[i][0]<<" "<<points[i][1]<<endl;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                mp[pow(points[j][0]-points[i][0],2)+pow(points[j][1]-points[i][1],2)]++;
            }
            for(auto x:mp)
        {
            ans+=x.second*(x.second-1);
            //cout<<x.first<<" "<<x.second<<endl;
        }
            mp.clear();
        }
        //int ans=0;
        
        return ans;
        
    }
};