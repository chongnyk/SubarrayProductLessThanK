class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int windowLength = 0;
        int subarrCount = 0;
        int product = 1;
        int left = 0, right = 0; //elements from [left, right) form a subarray window, with windowLength as its size
        while(right < nums.size()){
            if(product * nums[right] < k){ //if element at index right can be added to current window (< k)
                product *= nums[right++];
                windowLength++;
                subarrCount += windowLength;
            }
            else if(product * nums[right] >= k && left != right){
                product /= nums[left++];
                windowLength--;
            }
            else if(product*nums[right] >= k && left == right){
                left++; right++;
            }
        }
        return subarrCount;
    }
};
