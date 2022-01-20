class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string ans;
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(isupper(ch))
            {
                if(i==0)
                ans+=tolower(ch);
                else{
                ans+=' ';
                ans+=tolower(ch);
                k=0;}
            }
            else
            {
                ans+=ch;
                k=1;
            }
        }
        return ans;
    }
};