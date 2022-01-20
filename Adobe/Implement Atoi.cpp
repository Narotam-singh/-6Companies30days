class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans=0,k=0;
        if(str[0]=='-')
        {
            k=1;
            str=str.substr(1,str.size()-1);
        }
        for(int i=0;i<str.size();i++)
        {
            if(isalpha(str[i]))
            return -1;
            ans=ans*10+str[i]-'0';
        }
        if(k)
        ans*=(-1);
        return ans;
    }
};