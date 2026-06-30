#include <iostream>
#include <vector>
using namespace std;

void permute(vector<int>& nums, int index) {
    if (index == nums.size()) {
        for (int x : nums)
            cout << x << " ";
        cout << endl;
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);

        permute(nums, index + 1);

        // Backtrack
        swap(nums[index], nums[i]);
    }
}

int main() {
    vector<int> nums = {1, 2, 3};

    permute(nums, 0);

    return 0;
}
