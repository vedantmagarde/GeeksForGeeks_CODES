class Solution {
	public:
	int fun(int n, int k, vector<vector<int>> &dp) {
		
		if (k <= 0 || n <= 0)
			return 0;
		
		if (k == 1)
			return 1;
		if (n == 1)
			return k;
		
		if (dp[n][k] != -1)return dp[n][k];
		int min_moves = INT_MAX;
		int low = 1, high = k;
		
		while (low <= high) {
			int mid = low + (high - low) / 2;
			
			int breaki = fun(n - 1, mid - 1, dp);
			int not_ = fun(n, k - mid, dp);
			
			int worst_case = 1 + max(breaki, not_);
			min_moves = min(min_moves, worst_case);
			
			if (breaki < not_) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return dp[n][k] = min_moves;
	}
	int eggDrop(int n, int k) {
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
		return fun(n, k, dp);
	}
};
