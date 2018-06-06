#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  pass vector by reference
int maxArea(vector<int> &height) {

  // init to zero
  int ans = 0;
  int l = 0;
  int n = height.size();
  int r = n - 1;
  int area = 0;


  while(l < r){

    if (height[l] < height[r]){
        area = height[l]*(r - l);
        ans = max(ans, area);
        l++;
    }
    else{
        area = height[r]*(r - l);
        ans = max(ans, area);
        r--;
    }
  }

  return ans;
}

// Driver program
int main(){

  vector<int> hgt;
  hgt.push_back(1);
  hgt.push_back(2);

  int ans = maxArea(hgt);

  cout << ans << endl;

  return 0;
}
