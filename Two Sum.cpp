class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ret;
        for(int i=0;i<numbers.size()-1;i++)
            for(int j=i+1;j<numbers.size();j++)
                if(numbers[i]+numbers[j]==target){
                    ret.push_back(i+1);
                    ret.push_back(j+1);
                    //cout<<"index1="<<i<<", index2="<<j<<endl;
                    return ret;
                }
        return ret;
        
    }
};