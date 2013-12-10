/*暴力解法。重复值过滤掉。*/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int ret=0;
		int min=0x7fffffff;
		if(num.size()<3)
			return ret;
		sort(num.begin(),num.end());
		int lasti=num[0]-1;
		for(int i=0;i<num.size()-2;i++){
			if(num[i]==lasti)
				continue;
			int lastj=num[i+1]-1;
			for(int j=i+1;j<num.size()-1;j++){
				if(num[j]==lastj)
					continue;
				int lastk=num[j+1]-1;
				for(int k=j+1;k<num.size();k++){
					if(num[k]==lastk)
						continue;
					if(abs(num[i]+num[j]+num[k]-target)<min){
						ret=num[i]+num[j]+num[k];
						min=abs(ret-target);
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