#define ull unsigned long long

class ProductOfNumbers {
public:
    vector<ull> arr;
    bool needPref;
    int lastPref;
    ProductOfNumbers() {
        needPref=false;
        lastPref=-1;
    }
    
    void add(int num) {
        arr.push_back(1LL*num);
        needPref=true;
    }
    
    int getProduct(int k) {
        if(needPref){
            for(int i=arr.size()-2;i>lastPref;i--){
                arr[i] *=arr[i+1];
            }
            for(int i=lastPref;i>-1;i--){
                arr[i] *=arr[lastPref+1];
            }
            
            lastPref=arr.size()-1;
        }
        needPref = false;

        return arr[arr.size()-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */