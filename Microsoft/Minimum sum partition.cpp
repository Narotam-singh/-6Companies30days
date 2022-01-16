class Solution{
public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	     int sum=0;
       for(int i=0;i<n;i++){
           sum+=arr[i];
       }
       int temp=(sum%2==0)?0:1;
       sum/=2;
       vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
    
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=sum;j++)
           {
               if(j>=arr[i-1])
                   dp[i][j]=max(arr[i-1]+dp[i-1][j-arr[i-1]],dp[i-1][j]);
               else
                   dp[i][j]=dp[i-1][j];
           }
       }
       
       return 2*sum+temp-2*dp[n][sum];
	    
	} 
};