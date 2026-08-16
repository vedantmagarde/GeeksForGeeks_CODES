class Solution {
	public:
	int longestSubarray(vector<int>& arr, int k) {
		unordered_map<int, int>mp;
		int len = 0;
		int pre_sum = 0;
		
		for (int i = 0; i<arr.size(); i++) {
			pre_sum += arr[i];
			
			if (pre_sum == k)
				len = max(len, i + 1);
			
			if (mp.find(pre_sum - k) != mp.end()) {
				len = max(len, i - mp[pre_sum - k]);
			}
			
			if (mp.find(pre_sum) == mp.end()) {
				mp[pre_sum] = i;
			}
		}
		return len;
		
	}
};
