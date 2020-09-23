#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b)
{
	int la = a.size(), lb = b.size();
	if (la < lb)
	{
		swap(la, lb);
		swap(a, b);
	}

	vector<int> prev(lb+1, 0);
	for(int i=1; i<=la; i++)
	{
		vector<int> cur(lb+1);
		cur[0] = 0;
		for (int j=1; j<=lb; j++)
		{
			cur[j] = ((a[i-1] == b[j-1])?1+prev[j-1]:max(cur[j-1], prev[j]));
		}
		prev = cur;
	}

	return prev[lb];
}

int longest_palidromic_subsequence(string &a)
{
	string b(a.rbegin(), a.rend());
	return LCS(a, b);
}

int min_deletion_to_make_palindrome(string &s)
{
	return (int)s.size() - longest_palidromic_subsequence(s);
}

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

int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	string s = "ahsalfhsalkf";
	// cin >> s;

	cout << longest_repeating_subsequence(s) <<'\n';

}
