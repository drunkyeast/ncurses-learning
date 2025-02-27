#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lower_bound(vector<int>& nums, int target) {
    // 题解有详细说明.
    int l = 0, r = nums.size();
    while(l < r) {
        int mid = l + r >> 1;
        if (nums[mid] < target) l = mid + 1;
        else r = mid;
    }
    return l;
}

int binary_search(vector<int>& nums, int target) {
    int l = lower_bound(nums, target);
    return l != nums.size() && !(target < nums[l]); // 如果target < nums[l]的话, 那就合理啊, 应该在这个位置插入.
}

int upper_bound(vector<int>& nums, int target) { // 这个upper_bound与lower_boud也几乎一样, 都是while(l < r);
    int l = 0, r = nums.size();
    while(l < r) {
        int mid = l + r >> 1;
        if (target < nums[mid]) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() 
{
    std::vector<int> nums{1, 3, 3, 4, 5, 8};
    std::cout << lower_bound(nums.begin(), nums.end(), 2) - nums.begin() << std::endl;
    std::cout << lower_bound(nums.begin(), nums.end(), 3) - nums.begin() << std::endl;
    std::cout << lower_bound(nums.begin(), nums.end(), 4) - nums.begin() << std::endl;
    std::cout << upper_bound(nums.begin(), nums.end(), 3) - nums.begin() << std::endl;
    std::cout << binary_search(nums.begin(), nums.end(), 0) << std::endl;
    std::cout << binary_search(nums.begin(), nums.end(), 1) << std::endl;
    std::cout << binary_search(nums.begin(), nums.end(), 2) << std::endl;
    std::cout << binary_search(nums.begin(), nums.end(), 3) << std::endl;

    std::cout << std::endl <<  "===========================" << std::endl;
    cout << lower_bound(nums, 2) << endl;
    cout << lower_bound(nums, 3) << endl;
    cout << lower_bound(nums, 4) << endl;
    cout << upper_bound(nums, 3) << endl;
    cout << binary_search(nums, 0) << endl;
    cout << binary_search(nums, 1) << endl;
    cout << binary_search(nums, 2) << endl;
    cout << binary_search(nums, 3) << endl;


    /*
    输出:
    1
    1
    3
    3
    0
    1
    0
    1

    ===========================
    1
    1
    3
    3
    0
    1
    0
    1
    */
    return 0;
}