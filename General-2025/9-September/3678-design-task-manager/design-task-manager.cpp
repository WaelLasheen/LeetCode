class TaskManager {
public:
    unordered_map<int,vector<int>> mp;  // taskID: [priority ,taskId ,userId]
    set<vector<int>> q; // [priority ,taskId ,userId]

    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i][1]] = {-tasks[i][2] ,-tasks[i][1] ,tasks[i][0]};
            q.insert(mp[tasks[i][1]]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {-priority ,-taskId ,userId};
        q.insert(mp[taskId]);
    }
    
    void edit(int taskId, int newPriority) {
        q.erase(mp[taskId]);
        mp[taskId][0] = -newPriority;
        q.insert(mp[taskId]);
    }
    
    void rmv(int taskId) {
        q.erase(mp[taskId]);
        mp.erase(taskId);
    }
    
    int execTop() {
        if(q.size()){
            vector<int> task = *(q.begin());
            rmv(-1*task[1]);
            return task[2];
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */