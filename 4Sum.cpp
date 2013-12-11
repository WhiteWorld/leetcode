#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*穷举。。稍微剪枝*/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num,int target) {
                vector<vector<int>> ret;
                if(num.size()<4)
                        return ret;
                sort(num.begin(),num.end());
                if(num[num.size()-1]<(target/4-1))
                    return ret;
                int lasti=num[0]-1;
                for(int i=0;i<num.size()-3;i++){
						if(num[i]>(target/4+1))
							break;
                        if(num[i]==lasti)
                                continue;
                        int lastj=num[i+1]-1;
                        for(int j=i+1;j<num.size()-2;j++){
								if(num[i]+num[j]>(target/2+1))
									break;
                                if(num[j]==lastj)
                                        continue;
                                int lastk=num[j+1]-1;
                                for(int k=j+1;k<num.size()-1;k++){
										if(num[i]+num[j]+num[k]>(3*target/4+1))
											break;
                                        if(num[k]==lastk)
                                                continue;
                                        int lastl=num[k+1]-1;
                                        for(int l=k+1;l<num.size();l++){
											if(num[l]==lastl)
												continue;
                                            if(num[i]+num[j]+num[k]+num[l]==target){
                                                vector<int> v;
                                                v.push_back(num[i]);
                                                v.push_back(num[j]);
                                                v.push_back(num[k]);
                                                v.push_back(num[l]);
                                                ret.push_back(v);
                                                break;
                                            }else if(num[i]+num[j]+num[k]+num[l]>target)
												break;
                                            lastl=num[l];
                                        }
                                        lastk=num[k];
                                }
                                lastj=num[j];
                        }
                        lasti=num[i];
                }
                return ret;
    }
};
int main(){
	Solution solution;
	vector<int> vin;
	int t;
	while(cin>>t){
		vin.push_back(t);
	}
	int target = vin[vin.size()-1];
	vin.pop_back();
	vector<vector<int>> ans;
	ans=solution.fourSum(vin,target);
	system("PAUSE");
	return 0;
}