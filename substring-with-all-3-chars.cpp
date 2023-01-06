class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0,n=s.length();
        queue<char>q;
    
        int fre[3]={0};
         int i=0,j=0;
         while(j<n)  
         {
             
               while( fre[0]>0 && fre[1]>0 && fre[2]>0)
               {
                 ans+=n-j+1;
                // cout<<i<<" "<<ans<<endl;
                 q.pop();
                 fre[s[i]-'a']--;
                 i++;
               }
                q.push(s[j]);
                fre[s[j]-'a']++;
                j++;
         } 
        //cout<<q.size()<<endl;
        //int size=q.size();
       while(!q.empty()) 
       {
           while( fre[0]>0 && fre[1]>0 && fre[2]>0)
               {
                 ans++;
                 fre[q.front()-'a']--;
                 q.pop();
               }
             break;  
       }
    
return ans;
        
    }
};