// * Sliding window
// * Data structure
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = k-1;
        vector<int> ans(n-k+1, -INT_MAX);
        map<int, int> m;
        
        for(int i = l; i <= r; i++){
          m[nums[i]]++;
          ans[0] = max(ans[0], nums[i]);
        }
        
        for(l++, r++; r < n; l++, r++){
          m[nums[r]]++;
          
          if(m[nums[l-1]] == 1){
            auto it = m.find(nums[l-1]);
            m.erase(it);
          }
          else
            m[nums[l-1]]--;
          
          auto it = m.end();
          it--;
          ans[l] = it->first;
        }
        
        return ans;
    }
};