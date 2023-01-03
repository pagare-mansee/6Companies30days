class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
    
        if(tokens.size()==1)
        return stoi(tokens[0]);
        int ans=0;
        for(string s:tokens)
        {
            if(s=="+" || s=="-" || s=="*" || s=="/" || s=="^")
            {
                int o2=st.top();
                st.pop();
                int o1=st.top();
                st.pop();
                
                if(s=="+")
                ans=o1+o2;

                  else if(s=="-")
                ans=o1-o2;
                  else if(s=="*")
                ans=o1*o2;
                 else if(s=="/")
                ans=o1/o2;
                st.push(ans);

            }
            else
            st.push(stoi(s));

        }
        return ans;
    }
};