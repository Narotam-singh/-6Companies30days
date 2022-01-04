class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int temp[n+1]={0};
        int *v=new int[2];
        for(int i=0;i<n;i++)
        {
            temp[arr[i]]++;
        }
        for(int i=0;i<=n;i++)
        {
            if(temp[i]==0&&i!=0)
            v[1]=i;
            else if(temp[i]==2)
            v[0]=i;
        }
        return v;
    }
};