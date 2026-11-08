#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int max=0;
        for(int i=0,j=height.size()-1;i<j,j>i;)
        {
            
               if(height[j]>=height[i])
               {
                int x=height[i]*(j-i);
               }

               else
               {
                int x=height[j]*(j-i);
               }

               
            
        }

        

        return max;
    }
};