class Solution {
public:
    string decodeString(string s) {
        stack<int> countstack;
        stack<string> stringstack;
        string  curr="";
        int k=0;

        for(char c: s){
            if(isdigit(c)) {
                k=k*10+(c-'0');
            }
            else if(c=='[') {
                countstack.push(k);
                stringstack.push(curr);

                k=0;
                curr="";
            }
            else if(c==']'){
                int repeat=countstack.top();
                countstack.pop();

                string prev=stringstack.top();
                stringstack.pop();

                while(repeat--){
                    prev += curr;
                }
                curr=prev;
            }
            else{
                curr += c;
            }
        }
        return curr;
    }
};