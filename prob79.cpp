stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='('||c=='{'||c=='['){st.push(c);}
            else{
                if(!st.empty() and (('('==st.top() and c==')') || ('{'==st.top() and c=='}') || ('['==st.top() and c==']'))){
                    st.pop();
                }else return false;
            }
        }
        if( st.empty()) return true;
        else return false;