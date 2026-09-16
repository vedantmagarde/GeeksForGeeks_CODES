class Solution {
	public:
	int fun(int n, int k, vector<vector<int>> &dp) {
		if (k <= 0 || n <= 0)return 0;
		if (k == 1)return 1;
		if (n == 1)return k;
		
		if (dp[n][k] != -1)return dp[n][k];
		
		int l = 1;
		int h = k;
		int ans = INT_MAX;
		while (l <= h) {
			int mid = l + (h - l)/2;
			
			int broken = fun(n - 1, mid - 1, dp);
			int survived = fun(n, k - mid, dp);
			
			int chances = 1 + max(broken, survived);
			ans = min(ans, chances);
			
			if (broken<survived) {
				l = mid + 1;
			} else {
				h = mid - 1;
			}
			
		}
		return dp[n][k] = ans;
	}
	int eggDrop(int n, int k) {
		vector<vector<int>> dp(n + 2, vector<int>(k + 2, -1));
		return fun(n, k,dp);
	}
};
