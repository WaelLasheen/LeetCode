class MyCalendar {
public:
    vector<pair<int,int>> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // sort(cal.begin(),cal.end());
        for(int i=0;i<cal.size();i++){
            if(start < cal[i].second && end > cal[i].first){
                return false;
            }
        }
        cal.push_back({start,end});

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */