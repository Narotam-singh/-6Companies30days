class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=n-1;j>=0;j--)
            {
                if(grid[i][j]==0)
                   c++;
                else
                    break;
            }
            v[i]=c;
        }
        
        vector<int> temp=v;
        sort(temp.begin(),temp.end());
        for(int i=n-1;i>=0;i--)
        {
            if(temp[i]<i)
                return -1;
            else
            {
                if(i-1>=0)
                temp[i-1]+=(temp[i]-1);
            }
        }
        int swaps = 0;

	for(int i=0; i<n; i++)
	{
		if(v[i] < n-1-i) 
		{
			int j = i+1;
			while(j<n && v[j] < n-1-i) j++;
			if(j == n) return -1;

			while(j > i)
			{
				swap(v[j], v[j-1]);
				j--;
				swaps++;
			}
		}
	}
	return swaps;
        
    }
};