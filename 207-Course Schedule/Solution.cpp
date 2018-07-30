class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (prerequisites.empty()){return true;}
        vector<int> tmp(numCourses, 0);
        vector<vector<int> > schedule(numCourses, tmp);
        vector<int> indegree(numCourses, 0);
        
        for (int i = 0; i < prerequisites.size(); i++){
            int first = prerequisites[i].second;
            int end = prerequisites[i].first;
            schedule[first][end] = 1;
            indegree[end]++;
        }
        
        for (int i = 0; i < numCourses; i++){
            int j = 0;
            for (; j < numCourses; j++){
                if (indegree[j] == 0){
                    break;
                }                
                
            }
            if (j == numCourses){
                    return false;
            }
            indegree[j] = -1;
            for (int k = 0; k < numCourses; k++){
                if (schedule[j][k] == 1){
                    indegree[k]--;
                }
            }
        }
        return true;
        
        
    }
};
