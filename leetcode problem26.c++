
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        bool xors[2048] = {}, res[2048] = {};

        for(int i : nums){
            for(int j: nums){
                xors[i ^ j] = 1;
            }
        }

        for(int i = 0; i < 2048; ++i){

            if(xors[i])
                for(int j : nums){
                    res[i ^ j] = 1;
                }
        }

        return count(res, res + 2048, 1);
    }
};
