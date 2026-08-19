class Solution {
	public:
	int maxSubarraySum(vector<int> &arr) {
		int sum = 0;
		int ans = INT_MIN;
		for (int i = 0; i<arr.size(); i++) {
			sum += arr[i];
			if (sum < 0) {
				ans = max(ans, sum);
				sum = 0;
				continue;
			}
			ans = max(ans, sum);
		}
		return ans;
	}
};
