/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */

// @lc code=start
class ParkingSystem {
public:
    int size[3];
    ParkingSystem(int big, int medium, int small) {
        size[0] = big;
        size[1] = medium;
        size[2] = small;
    }
    
    bool addCar(int carType) {
        if(size[carType-1] == 0) return false;
        size[carType-1]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

