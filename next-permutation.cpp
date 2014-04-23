#include <iostream>
#include <vector>
using namespace std;
/*找数学规律, 从数组后往前找*/
class Solution {
	public:
		void swap(int a,int b,vector<int>&num){
			int tmp=num[a];
			num[a]=num[b];
			num[b]=tmp;
		}
		void nextPermutation(vector<int> &num){
			int len=num.size();
			if(len==0)
				return;
			int index=0;
			for(int i=len-1;i>0;i--)
				if(num[i]>num[i-1]){
					index=i;
					break;
				}
			if(index==0){
				int l=0,r=len-1;
				while(l<r){
					swap(l,r,num);
					l++;
					r--;
				}
			}
			else{
				for(int i=len-1;i>=index;i--)
					if(num[i]>num[index-1]){
						swap( index-1, i,num);
						break;
					}
				int l=index,r=len-1;
				while(l<r){
					swap(l,r,num);
					l++;
					r--;
				}
			}
		}
};
int main(){
	Solution s;
	vector<int> num;
	num.push_back(1);
	num.push_back(3);
	num.push_back(2);
	//num.push_back(4);
	//num.push_back(5);
	//num.push_back(6);
	s.nextPermutation(num);
	for(int i=0;i<num.size();i++)
		cout<<num[i]<<endl;
	return 0;



}
