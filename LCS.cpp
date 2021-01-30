

//Q. Given two strings, S and T with lengths M and N, find the length of the 'Longest Common Subsequence'.
// For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the
//  same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain
//   all the strings of length varying from 0 to K.




// Sample Input 1 :
// adebc
// dcadb
// Sample Output 1 :
// 3

// Explanation of the Sample Input 1 :
// Both the strings contain a common subsequence 'adb', which is the longest common subsequence with length 3. 



// Sample Input 2 :
// ab
// defg
// Sample Output 2 :
// 0

// Explanation of the Sample Input 2 :
// The only subsequence that is common to both the given strings is an empty string("") of length 0.




#include<iostream>
using namespace std;

int lcs(string s, string t)
{
	int m=s.length();
	int n=t.length();
	
	int dp[m+1][n+1];
	
	
for(int i=0;i<=m;++i)
dp[i][0]=0;

for(int i=0;i<=n;++i)
dp[0][i]=0;




for(int i=1;i<=m;++i){
    for(int j=1;j<=n;++j){
        if(s[m-i]==t[n-j]){
            dp[i][j]=1+dp[i-1][j-1];
        }
        else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}

return dp[m][n];

}

int main()
{
	string s; 
	string t;

	cin >> s;
	cin >> t;

	cout << lcs(s, t) << endl;
}