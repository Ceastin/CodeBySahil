class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int fact=0;
        for(int i=x;i<(x+k/2);i++)
        {
            fact++;
            for(int j=y;j<y+k;j++)
            {
                int temp=grid[i][j];
                cout<<grid[i][j]<<" "<<grid[x+k-fact][j]<<endl;
                grid[i][j]=grid[x+k-fact][j];
                grid[x+k-fact][j]=temp;
            }
            cout<<endl;
        }
        return grid;
    }
};