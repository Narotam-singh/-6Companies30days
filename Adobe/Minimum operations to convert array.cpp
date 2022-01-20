class Solution {
  public:
  
  int solve(vector<int>& nums,int n) {
     vector<int> v;
    for(int i=0; i<nums.size(); i++)
    {
        auto it = lower_bound(v.begin(),v.end(),nums[i]);
        if(it == v.end())
            v.push_back(nums[i]);
        else
        *it = nums[i];
    }
    return v.size();
}
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        set<int> s;
        for(int i=0;i<M;i++)
        s.insert(B[i]);
        vector<int> v;
        for(int i=0;i<N;i++)
        {
            if(s.find(A[i])!=s.end())
            v.push_back(A[i]);
        }
        return N+M-2*solve(v,v.size());
    }
};