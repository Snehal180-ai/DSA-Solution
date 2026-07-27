class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int l=0;
        // int sec_l=0;

        // for(int &num: nums) {
        //     if(num>l) {
        //         sec_l=l;
        //         l=num;
        //     }
        //     else{
        //         sec_l=max(sec_l,num);
        //     }
        // }
        // return (l-1)*(sec_l-1);
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int product=(nums[n-1] - 1) * (nums[n-2] - 1);
        return product;
    }
};