class Solution
{
    {
        int m, n;

    public:
        void bfs(int i, int j, vector<vector<int>> &grid, int &count, int n, int m)
        {
            queue<pair<int, int>> q;
            q.push({i, j});
            vector<pair<int, int>> rand = { {-1, -1}, {1, 1}, {-1, 1}, {1, -1},{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

            while (!q.empty())
            {
                pair<int, int> node = q.front();
                q.pop();
                count++;
                for (int i = 0; i < rand.size(); i++)
                {
                    int x = node.first + rand[i].first;
                    int y = node.second + rand[i].second;

                    if (x >= n || x < 0 || y >= m || y < 0 || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 0;
                    q.push({x, y});
                }
            }
        }

        // Function to find unit area of the largest region of 1s.
        int findMaxArea(vector<vector<int>> & grid)
        {
            // Code here
            int maxcount = 1;
            int n = grid.size();
            int m = grid[0].size();

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        int count = -1;
                        bfs(i, j, grid, count, n, m);
                        maxcount = max(maxcount, count);
                    }
                }
            }
            return maxcount;
        }
    };