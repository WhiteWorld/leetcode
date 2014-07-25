class Solution {
public:
    /*先排序，不排序的话可以考虑输出时插入排序*/
    vector<vector<int> > subsets(vector<int> &S) {
        std::sort(S.begin(), S.end());
        vector<vector<int> > result;
        if(S.size()==0)
            return result;
        vector<int> v;
        result.push_back(v);
        v.push_back(S[0]);
        result.push_back(v);
        for(int i=1;i<S.size();i++){
            int old_size = result.size();
            for(int j=0;j<old_size;j++){
                vector<int> v = result[j];
                v.push_back(S[i]);
                result.push_back(v);
            }
        }
        return result;
    }
};