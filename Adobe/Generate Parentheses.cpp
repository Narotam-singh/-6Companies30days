class Solution
{
    vector<string>v;
    public:
    
    void solve(string &s,int st,int en)
    {
        if(st==0&&en==0)
        {
            v.push_back(s);
            return;
        }
        if(st>0)
        {
            s+='(';
            solve(s,st-1,en);
            s.pop_back();
        }
        if(en>0&&st<en)
        {
            s+=')';
            solve(s,st,en-1);
            s.pop_back();
        }
        
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        string s="";
        solve(s,n,n);
        return v;
    }
};