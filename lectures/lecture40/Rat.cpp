// Rat in a Maze trap Problem Using Recursion

// Recursion-Day 10

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(int row, int col, vector<vector<int>> &maze,
           int n, string path, vector<string> &ans)
{

    // Destination reached
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // Down
    if (row + 1 < n && maze[row + 1][col] == 1)
    {
        maze[row][col] = 0; // Mark visited
        solve(row + 1, col, maze, n, path + "D", ans);
        maze[row][col] = 1; // Backtrack
    }

    // Left
    if (col - 1 >= 0 && maze[row][col - 1] == 1)
    {
        maze[row][col] = 0;
        solve(row, col - 1, maze, n, path + "L", ans);
        maze[row][col] = 1;
    }

    // Right
    if (col + 1 < n && maze[row][col + 1] == 1)
    {
        maze[row][col] = 0;
        solve(row, col + 1, maze, n, path + "R", ans);
        maze[row][col] = 1;
    }

    // Up
    if (row - 1 >= 0 && maze[row - 1][col] == 1)
    {
        maze[row][col] = 0;
        solve(row - 1, col, maze, n, path + "U", ans);
        maze[row][col] = 1;
    }
}

vector<string> ratInMaze(vector<vector<int>> &maze, int n)
{

    vector<string> ans;

    // Start or destination is blocked
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
        return ans;

    solve(0, 0, maze, n, "", ans);

    return ans;
}

int main()
{

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    int n = maze.size();

    vector<string> ans = ratInMaze(maze, n);

    for (string path : ans)
    {
        cout << path << endl;
    }

    return 0;
}