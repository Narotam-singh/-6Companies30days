class Solution{
public:

    bool valid(int i,int j,int m,int n)
    {
        if(i<m&&i>=0&&j<n&&j>=0)
        return 1;
        return 0;
    }

    void dfs(vector<vector<char>> &board,string word,map<pair<int,int>,bool> &mp,
    int idx,int i,int j,int f,int &ans)
    {
        if(idx==word.size())
        {
            if(f==1)
            ans=1;
            return;
        }
        if(f==0)
        return;
        if(mp[{i,j}])
        return;
        if(board[i][j]==word[idx])
        mp[{i,j}]=1;
        else
        return;
        int m=board.size(),n=board[0].size();
        if(valid(i+1,j,m,n)&&!mp[{i+1,j}])
        {
            //if(board[i+1][j]==word[idx+1])
            dfs(board,word,mp,idx+1,i+1,j,f,ans);
        }
        if(valid(i,j+1,m,n)&&!mp[{i,j+1}])
        {
            //if(board[i+1][j]==word[idx+1])
            dfs(board,word,mp,idx+1,i,j+1,f,ans);
        }
        if(valid(i-1,j,m,n)&&!mp[{i-1,j}])
        {
            //if(board[i+1][j]==word[idx+1])
            dfs(board,word,mp,idx+1,i-1,j,f,ans);
        }
        if(valid(i,j-1,m,n)&&!mp[{i,j-1}])
        {
            //if(board[i+1][j]==word[idx+1])
            dfs(board,word,mp,idx+1,i,j-1,f,ans);
        }
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        map<pair<int,int>,bool> mp;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                int ans=0;
                if(!mp[{i,j}]&&board[i][j]==word[0])
                {
                    dfs(board,word,mp,0,i,j,1,ans);
                    if(ans==1)
                    return 1;
                    mp.clear();
                }
            }
        }
        return 0;
    }
};