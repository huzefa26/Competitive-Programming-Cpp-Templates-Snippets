


int longest_repeating_subsequence(string &s)
{ // string has 2 occurences of this LRS
	int l = s.size();
	vector<int> prev(l+1, 0);
	for(int i=1; i<=l; i++)
	{
		vector<int> cur(l+1);
		cur[0] = 0;
		for (int j=1; j<=l; j++)
		{
			if (s[i-1]==s[j-1] && i!=j)
				cur[j] = 1 + prev[j-1];
			else
				cur[j] = max(prev[j], cur[i-1]);
		}
		prev = cur;
	}
	return prev[l];
}