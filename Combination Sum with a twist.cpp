class Solution {
public:
        void cal(vector<vector<int> >&ans,int k,int n,int c,int ind,vector<int>&v)
        {    
          
                if(c==k)
                {
                        if(n==0)
                        {
                            ans.push_back(v);   
                        } 
                        return;
                }
                for(int i=ind;i<=9;i++)
                {
                      if(i>n) 
                      break;
                     v.push_back(i);
                        c++;
                     cal(ans,k,n-i,c,i+1,v);
                       v.pop_back();
                        c--;
                }
                
        }
    vector<vector<int>> combinationSum3(int k, int n) {
            
            vector<vector<int> >ans;
         vector<int>v;
            cal(ans,k,n,0,1,v);
            return ans;
        
    }
};