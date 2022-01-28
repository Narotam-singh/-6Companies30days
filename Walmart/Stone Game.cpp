class Solution {
public:
    
    int solve(vector<vector<int>> &dp,vector<int> &piles,int i,int n,int k)
    {
        if(i>n||n<0)
            return 0;
        if(dp[k][i]!=-1)
            return dp[k][i];
        if(k==0)
            dp[k][i]=max(piles[i]+solve(dp,piles,i+1,n,1),piles[n]+solve(dp,piles,i,n-1,1));
        else
            dp[k][i]=max(piles[i]+solve(dp,piles,i+1,n,0),piles[n]+solve(dp,piles,i,n-1,0));
        return dp[k][i];
    }
    
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(2,vector<int> (piles.size()+1,-1));
        int suma=0,sumb=0;
        int c=solve(dp,piles,0,piles.size()-1,0);
        for(int j=0;j<dp[0].size();j++)
                suma=max(suma,dp[0][j]);
        for(int j=0;j<dp[1].size();j++)
                sumb=max(sumb,dp[1][j]);
        return suma>sumb;
    }
};