#include <sstream>
#define deb(x) cout<<#x<<" : "<<x<<endl
vector<string> Solution::prettyJSON(string A) {
    vector<string> res;
    int indent=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='{'||A[i]=='[')
        {
            string temp(1,A[i]);
            for(int j=0;j<indent;j++)
            {
               temp= "\t"+temp;
            }
            res.push_back(temp);
            indent++;
            continue;
        }
        else if((i)<A.size()&&A[i]!='{'&&A[i]!='['&&A[i]!='}'&&A[i]!=']')
        {
           string temp(1,A[i]);
            while((i+1)<A.size()&&A[i+1]!='{'&&A[i+1]!='['&&A[i+1]!='}'&&A[i+1]!=']')
            {
                temp=temp+A[i+1];
                i++;
                
            }
                //deb(temp);
                string token;
                int start=0,end=0;
                for(int j=0;j<temp.size();j++)
                {
                    if(temp[j]==',')
                    {
                        token=temp.substr(start,j-start+1);
                        for(int j=0;j<indent;j++)
                                token="\t"+token; 
                        res.push_back(token);
                        start=j+1;
                    }
                    
                }
                
                token=temp.substr(start,temp.size()-start);
                if(token.size()>0)
                {for(int j=0;j<indent;j++)
                    token="\t"+token;
                res.push_back(token);}
        }
           else if(A[i]=='}')
            {
                indent --;
                string token="}";
               for(int j=0;j<indent;j++)
                        token="\t"+token; 
                res.push_back(token);
                //i++;
                
            }
            if(A[i]==']')
            {
                indent --;
                string token="]";
               for(int j=0;j<indent;j++)
                        token="\t"+token; 
                res.push_back(token);
               // i++;
                
            }
            //i--;
            //deb (i);

    }
    
    return res;
}

