class Solution {
	public:
	vector<int> nextSmallerEle(vector<int>& arr) {
		vector<int>ans;
		stack<int>st;
		int i = arr.size() - 1;
		while (i >= 0) {
			while (!st.empty() && st.top()>=arr[i]) {
				st.pop();
			}
			st.empty()?ans.push_back(-1):ans.push_back(st.top());
			st.push(arr[i]);
			i--;
		}
		
		reverse(ans.begin(),ans.end());
		return ans;
	}
};
