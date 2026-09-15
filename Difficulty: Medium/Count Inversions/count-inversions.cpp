class Solution {
	public:
	int merge(vector<int>&arr, int st, int mid, int end) {
		vector<int>temp;
		int count = 0;
		int i = st;
		int j = mid + 1;
		while (i <= mid && j <= end) {
			if (arr[i] <= arr[j]) {
				temp.push_back(arr[i]);
				i++;
			} else {
				temp.push_back(arr[j]);
				j++;
				count += mid - i + 1;
			}
		}
		while (i <= mid) {
			temp.push_back(arr[i]);
			i++;
		}
		while (j <= end) {
			temp.push_back(arr[j]);
			j++;
		}
		
		for (int idx = 0; idx<temp.size(); idx++) {
			arr[st + idx] = temp[idx];
		}
		return count;
	}
	int mergeSort(vector<int>&arr, int st, int end) {
		if (st >= end)
			return 0;
		
		int mid = st + (end - st)/2;
		
		int leftInver = mergeSort(arr, st, mid);
		int rightInver = mergeSort(arr, mid + 1, end);
		
		int invCount = merge(arr, st, mid, end);
		
		return leftInver + rightInver + invCount;
		
	}
	int inversionCount(vector<int> &arr) {
		return mergeSort(arr, 0, arr.size()-1);
	}
};
