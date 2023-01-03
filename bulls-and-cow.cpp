
class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0,cow=0;
        int fre[10]={0};
        for(char c:secret)
        fre[c-'0']++;
        int n=secret.length();
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            {
            bull++;
            fre[secret[i]-'0']--;
            }
        }
            for(int i=0;i<n;i++)
            {   if(secret[i]!=guess[i])
                 {
                if(fre[guess[i]-'0']>0)
                {
                    cow++;
                    fre[guess[i]-'0']--;
                }
                 }
            }
      
        string ans="";
        ans+=to_string(bull);
        ans+='A';
        ans+=to_string(cow);
        ans+='B';
        return ans;
     
    }
};