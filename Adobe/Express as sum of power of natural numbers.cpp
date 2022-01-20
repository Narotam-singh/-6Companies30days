class Solution{
     
    public:
    
   
    int numOfWays(int n, int x)
    {
        // code here
       long long int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;

        for(long long int i=1;i<=n;i++)
        {
            for(long long int j=n;j>=i;j--)
            {
                long long int y=pow(i,x);
                if(j>=y)dp[j]+=dp[j-y];
            }
        }
        return dp[n];

    }
};