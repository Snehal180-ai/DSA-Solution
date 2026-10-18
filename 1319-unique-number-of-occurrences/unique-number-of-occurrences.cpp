class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        unordered_set<int> count;

        for(int x: arr){
            freq[x]++;
        }
        for(auto it: freq){
            if(count.find(it.second) != count.end()){
                return false;
            }
            count.insert(it.second);
        }
        return true;
    }
};