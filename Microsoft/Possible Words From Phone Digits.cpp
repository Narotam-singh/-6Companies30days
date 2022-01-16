class Solution
{
    public:
    void find(int a[],int n,vector<string> &ans,int i,string &s,map<int,string> &mp)
    {
        if(i>=n)
        {
            ans.push_back(s);
            return ;
        }

        string val=mp[a[i]];
        for(int j=0;j<val.size();j++)
        {
            s+=val[j];
            find(a,n,ans,i+1,s,mp);
            s.pop_back();
        }
        
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        vector<string> ans;
        string s;
        find(a,N,ans,0,s,mp);
        return ans;
    }
};