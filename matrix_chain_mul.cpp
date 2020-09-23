#include<bits/stdc++.h>
using namespace std;

const int MXN = 11;
int dp[MXN][MXN];

int MCM(vector<int> &a, int i, int j)
{
	if (dp[i][j] == -1)
	{
		int &ans = dp[i][j];
		if (i >= j)
		{
			ans = 0;
		}
		else if (i+1 == j)
		{
			ans = a[i-1]*a[i]*a[j];
		}
		else
		{
			ans = INT_MAX;
			for(int k=i; k<j; k++)
				ans = min(ans, MCM(a, i, k) + MCM(a, k+1, j) + a[i-1]*a[k]*a[j]);
		}
	}
	return dp[i][j];
}

// ABCD : {4, 2, 3, 1, 3}
// ((AB)C)D  24 + 12 + 12 X
// (AB)(CD)  24 +  9 + 36 X
// (A(BC))D   6 +  8 + 12 
// A((BC)D)   6 +  6 + 24 X
// A(B(CD))   9 + 18 + 24 X


int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	int n; cin >> n;
	vector<int> a(n+1);
	for(int &x: a)
		cin >> x;

	memset(dp, -1, sizeof(dp));
	cout << MCM(a, 1, n) << '\n';
}

