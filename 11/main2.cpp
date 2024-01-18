class Solution {
public:
  int maxArea(vector<int>& height) {
    int front = 0, end = height.size()-1;
    int ans = 0;
    while(front < end){
      int tmp = min(height[front], height[end]) * (end - front);
      ans = max(ans, tmp);
      if(height[front] < height[end]){
        front++;
      }else{
        end--;
      }
    }
    return ans;
  }
};
