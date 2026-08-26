class Solution {
	public:
	// 	int inc(int prev, int curr, int n, vector<int>&nums, vector<int>&dp_inc) {
	// 		if (curr >= n)return 0;
	// 		if (dp_inc[prev] != 0)return dp_inc[prev];
	// 		int skip = fun(prev, curr + 1, n, nums, dp_inc);
	// 		int take;
	// 		if (prev == -1 || nums[prev]< nums[curr]) {
	// 			take = 1 + fun(curr, curr + 1, n, nums, dp_inc);
	// 		}
	
	// 		return dp_inc[prev] = max(skip, take);
	// 	}
	// 	int dec(int prev, int curr, int n, vector<int>&nums, vector<int>&dp_dec) {
	// 		if (curr >= n)return 0;
	
	// 		if (dp_dec[prev] != 0)return dp_dec[prev];
	// 		int skip = fun(prev, curr + 1, n, nums, dp_dec);
	// 		int take;
	// 		if (prev == -1 || nums[prev]> nums[curr]) {
	// 			take = 1 + fun(curr, curr + 1, n, nums, dp_dec);
	// 		}
	
	// 		return dp_dec[prev] = max(skip, take);
	// 	}
	
	// int fun()
	int longestBitonicSequence(int n, vector<int> &nums) {
		
		if (n == 0)
			return 0;
		vector<int>dp_inc(n, 1);
		vector<int>dp_dec(n, 1);
		
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<i; j++) {
				if (nums[j]<nums[i]) {
					dp_inc[i] = max(dp_inc[i], 1 + dp_inc[j]);
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; i<j; j--) {
				if (nums[j]<nums[i]) {
					dp_dec[i] = max(dp_dec[i], 1 + dp_dec[j]);
				}
			}
		}
		// 		inc(-1, 0, n, nums, dp_inc);
		// 		dec(-1, 0, n, nums, dp_dec);
		int ans = 0;
		
		for (int i = 0; i<n; i++) {
			if (dp_inc[i] > 1 && dp_dec[i] > 1)
				ans = max(ans, dp_inc[i]+dp_dec[i]-1);
		}
		return ans;
	}
};
