class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        vector<vector<string>> ans;

        map<string, vector<string>> mp;

        for (int i = 0; i < string_list.size(); i++)
        {
            string s = string_list[i];
            sort(s.begin(), s.end());
            mp[s].push_back(string_list[i]);
        }

        for (auto x : mp)
        {
            ans.push_back(x.second);
        }

        return ans;
    }
};