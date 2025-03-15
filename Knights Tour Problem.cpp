//Knights Tour problem
#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<vector<int>> &grid, int r, int c, int n, int expVal) // T.C=O(8^(n^2)), since 8 possible moves or 8 diff branches in each cell.
{                                                                        // S.C=O(n^2), since recursion call stack-> 0 to (n^2)-1, and no extra auxiliary space used
    if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=expVal)
    {
        return false;
    }
    if(expVal == n*n-1)
    {
        return true;
    }
    
    // 8 possible moves
    int ans1 = isValid(grid, r-2, c+1, n, expVal+1);
    int ans2 = isValid(grid, r-1, c+2, n, expVal+1);
    int ans3 = isValid(grid, r+1, c+2, n, expVal+1);
    int ans4 = isValid(grid, r+2, c+1, n, expVal+1);
    int ans5 = isValid(grid, r+2, c-1, n, expVal+1);
    int ans6 = isValid(grid, r+1, c-2, n, expVal+1);
    int ans7 = isValid(grid, r-1, c-2, n, expVal+1);
    int ans8 = isValid(grid, r-2, c-1, n, expVal+1);

    return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8; // anyone may return true
}
int main()
{
    vector<vector<int>> grid = {{0,3,6},{5,8,1},{2,7,4}};
    cout<<isValid(grid, 0, 0, grid.size(), 0); // valid Combination: {0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}
    return 0;
}