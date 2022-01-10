class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        bool inc=0,dec=0;
        int maxlen=0;
        int j=0,k=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]<arr[i+1])
            {
                if(dec)
                {
                    if(inc)
                    {
                        j++;
                    }
                    else
                    {
                        maxlen=max(maxlen,j-k+2);
                        dec=0;
                    }
                    //maxlen=max(maxlen,j-k+1);
                }
                if(!dec)
                {
                    k=i;
                    j=i;
                    dec=1;
                    inc=1;
                }
            }
            else if(arr[i]>arr[i+1])
            {
                if(dec)
                {
                    j++;
                    inc=0;
                }
                else
                {
                    k=i;
                    j=i;
                }
            }
            else
            {
                if(dec)
                {
                    if(!inc)
                    {
                        j++;
                        maxlen=max(maxlen,j-k+1);
                        dec=0;
                    }
                    else
                    {
                        j++;
                        dec=0;
                    }
                }
            }
            if(j!=k&&dec&&!inc)
            maxlen=max(maxlen,j-k+1);
        }
        //if(dec&&inc)
          //  return 0;
        if(dec&&!inc)
            maxlen=max(maxlen,j-k+2);
        return maxlen;
    }
};