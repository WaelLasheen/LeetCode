class FoodRatings {
public:
    unordered_map<string,int> foodRate;
    unordered_map<string,string> cf;
    unordered_map<string,set<pair<int,string>>> top;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodRate[foods[i]] = ratings[i];
            cf[foods[i]] = cuisines[i];
            top[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        top[cf[food]].erase({-foodRate[food],food});
        top[cf[food]].insert({-newRating,food});
        foodRate[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return top[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */