class Solution {
public:
    int helper(stack<char>&st1){
        int num1=0,j=0;
        while(!st1.empty()){
            num1+=st1.top()*(pow(10,j));
            j++;

        }
        return num1;
    }
    int calculate(string s) {
        int ans=0;
        stack<char> st1;
        for(int i=0;i<s.size();i++){
        
            if(s[i]='+'){
                int num1=helper(st1);
                while(s[i]!='+' ||s[i]!='-'||s[i]!='*'||s[i]!='/' ){
                    st1.push(s[i]);
                }
                i--;
                int num2=helper(st1);
                ans=num1+num2;
                
            }
             if(s[i]='*'){
                int num1=helper(st1);
                while(s[i]!='+' ||s[i]!='-'||s[i]!='*'||s[i]!='/' ){
                    st1.push(s[i]);
                }
                i--;
                int num2=helper(st1);
                ans=num1*num2;
                
            }
             if(s[i]='-'){
                int num1=helper(st1);
                while(s[i]!='+' ||s[i]!='-'||s[i]!='*'||s[i]!='/' ){
                    st1.push(s[i]);
                }
                i--;
                int num2=helper(st1);
                ans=num1-num2;
                
            }
             if(s[i]='/'){
                int num1=helper(st1);
                while(s[i]!='+' ||s[i]!='-'||s[i]!='*'||s[i]!='/' ){
                    st1.push(s[i]);
                }
                i--;
                int num2=helper(st1);
                ans=num1/num2;
                
            }
        }
    }
};