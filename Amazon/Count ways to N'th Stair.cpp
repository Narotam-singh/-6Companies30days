class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int n)
    {
        // your code here
        long long dp[1000001];
		    dp[0]=1;
		    dp[1]=1;
		    for(int i=2;i<=n;i++)
		    {
		        dp[i]=1+dp[i-2];
		    }
		    return dp[n];
    }
};