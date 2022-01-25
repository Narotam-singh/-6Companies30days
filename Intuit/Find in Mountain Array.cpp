class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        if(n==3)
        {
            int x=mountainArr.get(1);
            int y;
                y=mountainArr.get(2);
            int z;
                z=mountainArr.get(0);
            if(z==target)
                return 0;
            if(x==target)
                return 1;
            if(y==target)
                return 2;
            return -1;
        }
       
       
        //z x y
        int st=0,en=n-1;
        int mn=n;
        int peak;
        while(st<=en)
        {
            int mid=(st+en)/2;
            int x=mountainArr.get(mid);
            int y=n-1;
            if(mid+1<n)
                y=mountainArr.get(mid+1);
            int z=0;
            if(mid-1>=0)
                z=mountainArr.get(mid-1);
            if(x>y&&x>z)
            {
                peak=mid;
                break;
            }
            else if(z>x&&x>y)
                en=mid-1;
            else
                st=mid+1;
        }
         if(mountainArr.get(peak)==target)
            return peak;
        st=0;
        en=peak-1;
        while(st<=en)
        {
            int mid=(st+en)/2;
            int x=mountainArr.get(mid);   
            if(x==target)
            {
                mn=min(mn,mid);
                break;
            }
            else if(x>target)
                en=mid-1;
            else
                st=mid+1;
        }
        st=peak+1;
        en=n-1;
        while(st<=en)
        {
            int mid=(st+en)/2;
            int x=mountainArr.get(mid);   
            if(x==target)
            {
                mn=min(mn,mid);
                break;
            }
            else if(x<target)
                en=mid-1;
            else
                st=mid+1;
        }
        if(mn==n)
            return -1;
        return mn;
        
        
    }
};