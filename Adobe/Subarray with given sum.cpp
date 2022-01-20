class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
         vector<int> v;
        int sum=0,k=0;
        int first=0,sec=0;
        for(int i=0;1;i++)
        {
            if(sum>s)
            {
                if(first<n)
                sum-=arr[first++];
                else
                break;
            }
            else if(sum<s)
            {
                if(sec<n)
                sum+=arr[sec++];
                else
                break;
            }
            else
            {
                k=1;
                v.push_back(first+1);
                v.push_back(sec);
                break;
            }
        }
        if(k==0)
        {
            return {-1};
        }
        return v;
    }
};