class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n==0)
	    return 0;
	    if(n==1)
	    return arr[0];
	    if(n==2)
	    return max(arr[0],arr[1]);
	    int val1=arr[0];
	    int val2=max(arr[0],arr[1]);
	    int max_val=0;
	    for(int i=2;i<n;i++)
	    {
	        max_val=max(val2,val1+arr[i]);
	        val1=val2;
	        val2=max_val;
	    }
	    return max_val;
    }
};