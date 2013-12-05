#include <iostream>
#include <string>
using namespace std;


class Solution {
public:

	
/*Manacher's ALGORITHM: O(n)时间求字符串的最长回文子串*/
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
	string preProcess(string s) {
		int n = s.length();
		if (n == 0) return "^$";
		string ret = "^";
		for (int i = 0; i < n; i++)
			ret += "#" + s.substr(i, 1);

		ret += "#$";
		return ret;
	}

	string longestPalindrome(string s) {
		string T = preProcess(s);
		int n = T.length();
		int *P = new int[n];
		int C = 0, R = 0;//R 代表最远的回文子串边界
		for (int i = 1; i < n-1; i++) {
		    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
		    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
	    
		    // Attempt to expand palindrome centered at i
	    	while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
	    		P[i]++;

	    	// If palindrome centered at i expand past R,
	    	// adjust center based on expanded palindrome.
	    	if (i + P[i] > R) {
	    		C = i;
	    		R = i + P[i];
	    	}
		}

	    // Find the maximum element in P.
		int maxLen = 0;
		int centerIndex = 0;
		for (int i = 1; i < n-1; i++) {
			if (P[i] > maxLen) {
				maxLen = P[i];
				centerIndex = i;
			}
		}
		delete[] P;

		return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
	}
string longestPalindrome1(string s) {

		/*dp O(n^2)，The Key Is dp[i][j] :between i and j(include i,j) ,if has a Palindrome*/
	bool dp[1001][1001];
	int len=0;
	len=s.size();
	if(len==0)
		return s;
	for(int i=0;i<len;i++)
		dp[i][i]=1;
	for(int i=1;i<len;i++)
		dp[i][i-1]=1;
	int start,stop;
	start=1;
	stop=0;
		for(int m=0;m<len;m++){//m: interval of i and j
			for(int i=0;i<len-m;i++){
				int j=i+m;
				if((i==j)||(s[i]==s[j]&&dp[i+1][j-1]==1)){
					dp[i][j]=1;
					if(stop-start<m){
						start=i;
						stop=j;
					}
				}else{
					dp[i][j]=0;
				}
			}
		}
		return s.substr(start,stop-start+1);
	}

	string longestPalindrome2(string s){
		/*暴力算法，O(n^3),超时*/
		int l[1001];
		int max=-1;
		int result;
		for(int i=0;i<s.size();i++){
			l[i]=1;
			for(int j=s.size();j>i;j--){
				if(isPalindrome(s,i,j)){
					l[i]=j-i+1;
					break;
				}             
			}
			if(l[i]>max){
				max=l[i];
				result=i;
			}
			
		}
		return s.substr(result,max);
	}
	bool isPalindrome(string s,int begin,int end){//make sure begin < end
		while(begin<end){
			if(s[begin]!=s[end])
				return false;
			begin++;
			end--;
		}
		return true;
	}


	/*
	O(n^2)time O(1)space
	遍历所有以i为中心和以(i,i+1)为中心的最长的回文串，找出最大的那个即可
	*/
	string expandAroundCenter(string s, int c1, int c2) {
		int l = c1, r = c2;
		int n = s.length();
		while (l >= 0 && r <= n-1 && s[l] == s[r]) {
			l--;
			r++;
		}
		return s.substr(l+1, r-l-1);
	}

	string longestPalindromeSimple3(string s) {
		int n = s.length();
		if (n == 0) return "";
		string longest = s.substr(0, 1);  // a single char itself is a palindrome
		for (int i = 0; i < n-1; i++) {
			string p1 = expandAroundCenter(s, i, i);
			if (p1.length() > longest.length())
				longest = p1;

			string p2 = expandAroundCenter(s, i, i+1);
			if (p2.length() > longest.length())
				longest = p2;
		}
		return longest;
	}
};
int main(){

	Solution solution;
	string str;
	while(cin>>str){
		cout<<solution.longestPalindrome(str)<<endl;	
	}
	system("PAUSE");
	return 0;
}