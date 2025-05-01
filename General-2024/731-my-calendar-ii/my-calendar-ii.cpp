class MyCalendarTwo {
public:
    vector<pair<int,int>> cal ,ints;  //ints >>>  intersection

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // check if ther three events have some non-empty intersection
        for(int i=0;i<ints.size();i++){
            if(start < ints[i].second && end > ints[i].first){
                return false;
            }
        }

        for(int i=0;i<cal.size();i++){
            if(start < cal[i].second && end > cal[i].first){
                ints.push_back({max(start,cal[i].first) ,min(end,cal[i].second)});
            }
        }

        cal.push_back({start,end});

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */