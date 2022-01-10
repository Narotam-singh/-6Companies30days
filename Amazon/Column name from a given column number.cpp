
class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans;
        while(n>0)
        {
            long long int r=(n%26)-1;
            n/=26;
            if(r==-1)
            ans+='Z',n--;
            else
            ans+='A'+r;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};