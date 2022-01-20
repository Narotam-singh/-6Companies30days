class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
         int ans = 0;
       if(n == 1) 
       return 1;
       if(n==2)
       return 2;

        vector<vector<int>>dp(n, vector<int>(10001,0));
        
        for(int i = 0; i < n; i++) 
        {
            for(int j = i + 1; j < n; j++) 
            {

                int diff = A[j] - A[i];

                dp[j][diff] = max(dp[i][diff] + 1, 2);

                ans = max(ans, dp[j][diff]);
            }
        }

        return ans;
    }
};