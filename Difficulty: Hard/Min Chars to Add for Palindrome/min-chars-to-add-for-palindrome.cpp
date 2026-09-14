class Solution {
	public:
	int minChar(string &s) {
		string rev = s;
		reverse(rev.begin(), rev.end());
		
		int n = s.length();
		
		string combined = s + "#" + rev;
		int total_len = combined.length();
		
		vector<int> lps(total_len, 0);
		int i = 1;
		int len = 0;
		
		while (i < total_len) {
			if (combined[i] == combined[len]) {
				len++;
				lps[i] = len;
				i++;
			} else {
				if (len != 0) {
					len = lps[len - 1];
				} else {
					lps[i] = 0;
					i++;
				}
			}
		}
		
		return n - lps.back();
	}
};
