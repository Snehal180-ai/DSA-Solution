class Solution {
public:

    int binsearch(vector<int>& arr, int tar, int st, int end){
        if(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid]==tar) return mid;
            else if(arr[mid]<=tar) return binsearch(arr,tar,mid+1,end);
            else return binsearch(arr,tar,st,mid-1);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binsearch(nums,target,0,nums.size()-1);
    }
};