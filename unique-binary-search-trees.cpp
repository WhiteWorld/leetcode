#include <iostream>
#include <vector>
using namespace std;
/*找规律*/
class Solution {
		public:
				int numTrees(int n) {
						vector<int> f;
						f.push_back(0);
						f.push_back(1);
						f.push_back(2);
						f.push_back(5);
						for(int i=4;i<=n;i++){
								int sum=0;
								for(int j=1;j<=i-2;j++)
										sum+=f[j]*f[i-1-j];
								f.push_back(2*f[i-1]+sum);
						}
						return f[n];
				}
};
int main(){
	Solution s;
	cout<<s.numTrees(3)<<endl;
	cout<<s.numTrees(4)<<endl;
	return 0;
}