class ParkingSystem {
public:
    map<int,int> type;
    ParkingSystem(int big, int medium, int small) {
        type[1]=big;
        type[2]=medium;
        type[3]=small;
    }
    
    bool addCar(int carType) {
        if(type[carType]){
            type[carType]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */