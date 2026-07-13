class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      stack<int> st;
      st.push(-1);
      int max_area=0;
      for(int i=0;i<heights.size();i++){
        while(st.top()!=-1 && heights[st.top()] >= heights[i])  //process higher buildings
        {
            int curr_bar_height=heights[st.top()];  //on stack
            st.pop();
            int curr_width=i-st.top()-1;
            max_area=max(max_area, curr_bar_height*curr_width);
        }
        st.push(i);  //push the curr shorter building into stack
      }
      //when height array is traversed, now process the remaining element in stack

      int n = heights.size();
        while(st.top() != -1) {
            int curr_bar_height = heights[st.top()];
            st.pop();
            int curr_width = n - st.top() - 1;  // FIXED
            max_area = max(max_area, curr_bar_height * curr_width);
        }

        return max_area;
    }
};