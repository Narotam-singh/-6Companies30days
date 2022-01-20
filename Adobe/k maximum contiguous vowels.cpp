class Solution
{
  public:
    int kvowelwords(int N, int K) {
        // Write Your Code here
        
        vector<vector<long long int>> dp(N+1,vector<long long int>(K+1,0));
        int mod=1e9+7;
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=K;j++)
            {
                if(i==0)
                {
                    dp[0][j]=1;
                    continue;
                }
                dp[i][j]=(dp[i-1][K]*21)%mod;
                if(j-1>=0)
                dp[i][j]=(dp[i][j]+dp[i-1][j-1]*5%mod)%mod;
            }
        }
        return dp[N][K];
    }
};