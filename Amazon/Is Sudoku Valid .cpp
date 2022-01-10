class Solution
{
public:
    int isValid(vector<vector<int>> board)
    {
        // code here
        // replace board with matrix
        int row[9][9];
        int col[9][9];
        int square[9][9];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                row[i][j] = 0;
                col[i][j] = 0;
                square[i][j] = 0;
            }
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != 0)
                {
                    int num = board[i][j] - 1;

                    if (row[i][num] == 0)
                        row[i][num] = 1;
                    else
                        return false;

                    if (col[j][num] == 0)
                        col[j][num] = 1;
                    else
                        return false;

                    int sq = (i / 3) + 3 * (j / 3);
                    if (square[sq][num] == 0)
                        square[sq][num] = 1;
                    else
                        return false;
                }
            }
        }

        return true;
    }
};