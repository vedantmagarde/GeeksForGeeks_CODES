class Solution {
	public:
	
	int fun(int W, vector<int> &val, vector<int> &wt, int i, vector<vector<int>> &dp) {
		if (i >= wt.size())
			return 0;
		
		if (dp[W][i] != -1)return dp[W][i];
		
		int skip = fun (W, val, wt, i + 1, dp);
		int take = 0;
		if (W - wt[i] >= 0)
			take += val[i]+ fun(W - wt[i], val, wt, i + 1, dp);
		
		return dp[W][i] = max(skip, take);
	}
	int knapsack(int W, vector<int> &val, vector<int> &wt) {
		vector<vector<int>> dp(W + 1, vector<int>(wt.size() + 1, -1));
		return fun(W, val, wt, 0, dp);
	}
};
