int maximumPoints(int n, vector<vector<int>> &grid) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // Add the primary diagonal element
        ans += grid[i][i];
        // Add the secondary diagonal element, if it's not the same as the primary diagonal element
        if (i != n - 1 - i) {
            ans += grid[i][n - 1 - i];
        }
    }
    return ans;
}
