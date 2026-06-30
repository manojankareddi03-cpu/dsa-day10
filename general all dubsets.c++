#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& nums, vector<int>& subset, int index) {
    if (index == nums.size()) {
        cout << "{ ";
        for (int x : subset)
            cout << x << " ";
        cout << "}" << endl;
        return;
    }

    // Include current element
    subset.push_back(nums[index]);
    generateSubsets(nums, subset, index + 1);

    // Backtrack
    subset.pop_back();

    // Exclude current element
    generateSubsets(nums, subset, index + 1);
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> subset;

    generateSubsets(nums, subset, 0);

    return 0;
}
