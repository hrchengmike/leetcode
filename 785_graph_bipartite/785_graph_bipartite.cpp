class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        //initialzed to 0 for each node
        //0: unvisited, 1 and 2 are two different colors
        vector<int> color(n, 0);
        queue<int> q;
        int smallest_unvisited = 0; 
        while(true){
            //push smallest unvisited node, essential since graph may be disconnected
            for(int i = smallest_unvisited; i < n; i++){
                if(color[i] == 0){
                    color[i] = 1;
                    q.push(i);
                    smallest_unvisited = i;
                    break;
                }
                if(i == n-1){
                    return true;
                }
            }
            
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(auto neighbor : graph[cur]){
                //unvisited(unpainted) child, paint different color, push to back of queue
                    if(color[neighbor] == 0){
                        color[neighbor] = 3 - color[cur];
                        q.push(neighbor);
                    }else{
                        if(color[neighbor] + color[cur]!=3){
                            return false;
                        }
                    }
                }
            }
        }
    }
};