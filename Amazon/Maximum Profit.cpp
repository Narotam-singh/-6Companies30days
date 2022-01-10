class Solution {
  public:
  
 
    int maxProfit(int k, int n, int arr[]) {
        // code here
    
        
        if(n == 0 || k== 0) 
        return 0;
        
        vector<vector<int>> v(k+1,vector<int> (n));
        
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 || j == 0)
                    {
                        v[i][j] = 0;
                        continue;
                    }
                
                
                    v[i][j] = v[i][j-1];
                    
                    int h = j - 1;
                    while(h >= 0)
                    {
                        v[i][j] = max(v[i][j] , v[i-1][h] + (arr[j] - arr[h]) );
                        h--;
                    }
            
            }
        }
        
        return v[k][n-1];
    }
};