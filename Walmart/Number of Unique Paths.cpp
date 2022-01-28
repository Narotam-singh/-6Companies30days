class Solution
{
    public:
    //Function to find total number of unique paths.
    
    
    int NumberOfPath(int a, int b)
    {
        //code here
        int dp[16][16];
        dp[0][0]=1;
        dp[1][0]=1;
        dp[0][1]=1;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if(i==0&&j-1>=0)
                dp[i][j]=dp[i][j-1];
                else if(j==0&&i-1>=0)
                dp[i][j]=dp[i-1][j];
                else if(i!=0&&j!=0)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[a-1][b-1];
    }
};
