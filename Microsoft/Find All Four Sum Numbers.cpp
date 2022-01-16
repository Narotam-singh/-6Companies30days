class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int n=arr.size();
       
        map<vector<int>,bool> mp;
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                vector<int> v;
                int n1=arr[i],n2=arr[j];
                int st=j+1,en=n-1;
                while(st<en)
                {
                    if(n1+n2+arr[st]+arr[en]==k&&!mp[{n1,n2,arr[st],arr[en]}])
                    {
                        mp[{n1,n2,arr[st],arr[en]}]=1;
                        v.push_back(n1);
                        v.push_back(n2);
                        v.push_back(arr[st]);
                        v.push_back(arr[en]);
                        ans.push_back(v);
                        v.clear();
                        en--;
                    }
                    else if(n1+n2+arr[st]+arr[en]>k)
                    en--;
                    else
                    st++;
                }
                //if(!v.empty())
                
            }
        }
        return ans;
    }
};