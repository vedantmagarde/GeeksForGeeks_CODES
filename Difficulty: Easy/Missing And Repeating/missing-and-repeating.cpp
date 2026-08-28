class Solution {
	public:
	vector<int> findTwoElement(vector<int>& arr) {
		int n = arr.size();
		
		for (int i = 0; i<n; i++) {
			while (arr[i] != arr[arr[i]-1]) {
				swap(arr[i], arr[arr[i]-1]);
			}
		}
		
		for (int i = 0; i<n; i++) {
			if (arr[i] != i + 1)return {arr[i], i + 1};
		}
		
		return {};
		
	}
};
