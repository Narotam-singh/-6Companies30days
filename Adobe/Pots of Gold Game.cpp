class Solution{
public:

    int find(vector<vector<int>> &dp,vector<int> &A,int i,int j)
    {
        if(i>j)
        return dp[i][j]=0;
        if(i==j)
        return dp[i][j]=A[i];
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int n1,n2;
        n1=A[i];
        n1+=min(find(dp,A,i+2,j),find(dp,A,i+1,j-1));
        n2=A[j];
        n2+=min(find(dp,A,i,j-2),find(dp,A,i+1,j-1));
        return dp[i][j]=max(n1,n2);
        
    }

    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
	    return find(dp,A,0,n-1);
    }
};