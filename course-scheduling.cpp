class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector< vector<int> >g(numCourses+1);
            int n=prerequisites.size();
            
        for(int i=0;i<n;i++)
        {    if(prerequisites[i][1]==prerequisites[i][0])
                return false;
             g[prerequisites[i][1]].push_back(prerequisites[i][0]); 
        }
           
            vector<bool>vis(numCourses+1,0),recur(numCourses+1,0);
            
             return !(dfs (g,numCourses,vis,recur));
    }
         bool dfs (vector<vector<int>>&g, int n, vector<bool> & vis, vector<bool> & recur)
         {
             for(int i=0;i<n;i++)  
             {
                if(vis[i]==0)
                {
                 if(cyclic(g,i,vis,recur) )
                        return true;
                  
                        
                }
             }
                    
            return false;     
         }
        bool cyclic(vector<vector<int>>&g, int r, vector<bool> & vis, vector<bool> & recur)
        {   
                if(vis[r]==0)
                 {
                         vis[r]=1;
                         recur[r]=1;
                        
                    for(auto v:g[r]) 
                    {
                       if(vis[v]==0 && cyclic(g,v,vis,recur) )
                        return true;
                       else if (recur[v]==1)
                          return true;
                    }
                        
                }
            //    cout<<r<<" "<<recur[r]<<endl;
                recur[r]=0;
                // cout<<g[r].size()<<" "<<recur[r]<<endl;
                return false;
        }
};