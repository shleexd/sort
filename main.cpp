#include <iostream>
#include <vector>
#include <string>

using namespace std;

//using insert sort.
void incertSort(vector<int> &nums){
    for(int i = 1; i < nums.size(); ++i)
    {
       int key = nums[i] ;
       int j = i - 1;
       while( j > 0 && nums[j] > key )
       {
           nums[j + 1] = nums[j];
           --j;
       }
       nums[j + 1] = key;
    }
}

//using merge sort.

//merg sorted numbers num[p]~nums[q] and nums[q+1]~ nums[r]
void merge(vector<int> &nums, int p, int q, int r){
    if( p > q || q > r) return;
    vector<int> lnums(nums.begin() + p, nums.begin() + q + 1);
    vector<int> rnums(nums.begin() + q + 1, nums.begin() + r + 1);
    lnums.push_back(0xffff);
    rnums.push_back(0xffff);

    int rIndex = 0, lIndex = 0;
    for(int i = p; i <= r; ++i)
    {
       if(lnums[lIndex ] > rnums[rIndex ]){
           nums[i] = rnums[rIndex ];
           ++rIndex ;
       }
       else {
           nums[i] = lnums[lIndex ];
           ++lIndex ;
       }
    }
}
void mergeSort(vector<int> &nums, int p, int q){
    if( p < q){
        int mid = (p + q)  / 2;
        mergeSort(nums, p, mid);
        mergeSort(nums, mid + 1, q);
        merge(nums,p, mid, q);
    }
}

//buble sort.
void buble_sort(vector<int> &nums){
    for(int i = 0; i < nums.size(); ++i){
        for(int j = 0; j < nums.size() - 1; ++j){
            if(nums[j] > nums[j + 1])
                swap(nums[j],nums[j + 1]);
        }
    }
}

int main(int argc, char *argv[])
{
    
    //vector<int> nums = {100,39,2,40, 32,32, 435, 543, 214523};
    vector<int> nums;
    int data;
    while(std::cin >> data){
        nums.push_back(data);
    }
    //incertSort(nums);
    //mergeSort(nums, 0, nums.size() - 1);
    
    buble_sort(nums);
    for(auto &i : nums)
    {
        cout << i  << " " << std::endl;
    }
    return 0;
}
