#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
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
			//cout<<"index:"<<index<<endl;
			if(index==0){
				int l=0,r=len-1;
				while(l<r){
					int tmp=num[l];
					num[l]=num[r];
					num[r]=tmp;
					l++;
					r--;
				}
			}
			else{
				for(int i=len-1;i>=index;i--)
					if(num[i]>num[index-1]){
						//swap index-1 i-1
						int tmp=num[i];
						num[i]=num[index-1];
						num[index-1]=tmp;
						break;
					}
			}
		}
};
int main(){
	Solution s;
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	num.push_back(5);
	//num.push_back(4);
	//num.push_back(5);
	//num.push_back(6);
	s.nextPermutation(num);
	for(int i=0;i<num.size();i++)
		cout<<num[i]<<endl;
	return 0;



}
