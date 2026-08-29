class Solution {
	public:
	
	int fun(vector<int>&wt, int W, vector<int>&val, int i, vector<vector<int>> &dp) {
		if (i >= wt.size())return 0;
		if (dp[W][i] != -1)
			return dp[W][i];
		int skip = fun(wt, W, val, i + 1, dp);
		
		int take = 0;
		if (W - wt[i] >= 0)
			take = val[i]+ fun(wt, W - wt[i], val, i + 1, dp);
		
		return dp[W][i] = max(skip, take);
	}
	int knapsack(int W, vector<int> &val, vector<int> &wt) {
		vector<vector<int>> dp(W + 1, vector<int>(val.size() + 1, -1));
		return fun(wt, W, val, 0, dp);
	}
};
