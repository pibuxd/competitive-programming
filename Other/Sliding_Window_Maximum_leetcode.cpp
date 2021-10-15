// * Sliding window
// * Data structure
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        
        int l = 0, r = 0;
        while(r <= k - 1){
            int add = nums[r];
            while(!dq.empty() && dq.back() < add)
                dq.pop_back();
            
            dq.push_back(add);
            r++;
        }
        ans.push_back(dq.front());
        
        r--;
        while(r < n-1){
            int add = nums[r+1];
            while(!dq.empty() && dq.back() < add)
                dq.pop_back();
            dq.push_back(add);
            
            if(!dq.empty() && dq.front() == nums[l])
                dq.pop_front();
            ans.push_back(dq.front());
            l++, r++;
        }
        
        return ans;
    }
};