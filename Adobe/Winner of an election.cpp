class Solution{
public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        int max1=INT_MIN;
        for(auto x:mp)
        {
            max1=max(max1,x.second);
        }
        vector<string> v;
        for(auto x:mp)
        {
            if(x.second==max1)
            {
                v.push_back(x.first);
                v.push_back(to_string(x.second));
            }
        }
        return v;
    }
};