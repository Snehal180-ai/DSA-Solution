class Solution {
public:
    int trap(vector<int>& height) {
        // int n = height.size();
        // if(n <= 2) return 0;

        // int left = 0, right = n - 1;
        // int leftMax = 0, rightMax = 0;
        // int water = 0;

        // while(left < right) {
        //     if(height[left] < height[right]) {
        //         if(height[left] >= leftMax)
        //             leftMax = height[left];
        //         else
        //             water += leftMax - height[left];
        //         left++;
        //     } else {
        //         if(height[right] >= rightMax)
        //             rightMax = height[right];
        //         else
        //             water += rightMax - height[right];
        //         right--;
        //     }
        // }

        // return water;

        int ans=0;
        stack<int> st;
        for(int right=0; right<height.size();right++){
            while(!st.empty() && height[right]>height[st.top()]) {
                int cur=st.top();
                st.pop();
                if(st.empty())
                    break;
                int left=st.top();
                int distance=right-left-1;
                int ht_cov=min(height[right],height[left])-height[cur];
                ans += distance*ht_cov;
            }
            st.push(right);
        }
        return ans;
    }
};
