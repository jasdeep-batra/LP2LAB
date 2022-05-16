#include<bits/stdc++.h>
using namespace std;
void SelectionSort(vector<int> nums)
{
    for(int i=0;i<nums.size()-1;i++)
    {
        int mind = i;
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]<nums[mind])
            {
                mind = j;
            }
        }
        if(i!=mind)
        {
            swap(nums[mind],nums[i]);
        }
    }
    for(auto itr: nums)
    {
        cout<<itr<<" ";
    }
}
int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        nums.push_back(val);
    }
    SelectionSort(nums);
}
