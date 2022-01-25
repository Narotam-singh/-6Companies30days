class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
         int n = piles.size();
        int st = 1;
        long long en = 0;
        for(int i=0;i<n;i++)
            en+=piles[i];
        while(st<en)
        {
            long long mid = st+(en-st)/2;
            int ans = 0;
            for(int i = 0;i < n;i++)
            {
                if(piles[i]%mid == 0)
                    ans+=(piles[i]/mid);
                else
                    ans+=(piles[i]/mid+1);
            }
            if(ans>h)
                st = mid+1;
            else
                en = mid;
        }
        return en;
    }
};