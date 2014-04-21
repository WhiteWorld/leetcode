#include <iostream>
#include <cstring>
using namespace std;
class Solution {
		public:
				string getPermutation(int n, int k) {

						int tab[10];
						bool used[10];
						tab[0]=1;
						string s;
						for(int i=1;i<10;i++){
								tab[i]=tab[i-1]*i;
								used[i]=false;
						}
						
						int cnt=n;
						while(cnt>1){
								cnt--;
								int i;
								if(k%tab[cnt]==0){
									i=k/tab[cnt];
									k=tab[cnt];
								}else{
									i=k/tab[cnt]+1;
									k=k%tab[cnt];
								}
								int m=0;
								for(int j=1;j<=n;j++){
									if(!used[j])
										m++;
									if(m==i){
										used[j]=true;
										s.push_back(j+'0');
										break;
									}		
								}
						}
						for(int j=1;j<=n;j++)
								if(!used[j])
										s.push_back(j+'0');
						return s;
				}
};

int main(){
	Solution s;
	int n,k;
	cin>>n>>k;
	cout<<s.getPermutation(n,k)<<endl;
	return 0;
}
