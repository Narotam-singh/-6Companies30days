class Solution
{
public:
    int CountWays(string s)
    {
        // Code here
        int MOD = 1e9 + 7;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != '0')
                dp[i] = dp[i + 1] % MOD;
            if (i < n - 1)
            {
                int number = (s[i] - '0') * 10 + s[i + 1] - '0';
                if (number >= 10 && number <= 26)
                    dp[i] = ((dp[i] % MOD) + (dp[i + 2] % MOD)) % MOD;
            }
        }
        return dp[0];
    }
};