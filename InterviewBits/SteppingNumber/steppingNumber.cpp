void dfs(int n, int m, int stepNum,vector<int> &res) 
{ 
    // If Stepping Number is in the 
    // range [n,m] then display 
    if (stepNum <= m && stepNum >= n) 
        res.push_back(stepNum); 
  
    // If Stepping Number is 0 or greater 
    // than m, then return 
    if (stepNum == 0 || stepNum > m) 
        return ; 
  
    // Get the last digit of the currently 
    // visited Stepping Number 
    int lastDigit = stepNum % 10; 
  
    // There can be 2 cases either digit 
    // to be appended is lastDigit + 1 or 
    // lastDigit - 1 
    int stepNumA = stepNum*10 + (lastDigit-1); 
    int stepNumB = stepNum*10 + (lastDigit+1); 
  
    // If lastDigit is 0 then only possible 
    // digit after 0 can be 1 for a Stepping 
    // Number 
    if (lastDigit == 0) 
        dfs(n, m, stepNumB,res); 
  
    // If lastDigit is 9 then only possible 
    // digit after 9 can be 8 for a Stepping 
    // Number 
    else if(lastDigit == 9) 
        dfs(n, m, stepNumA,res); 
    else
    { 
        dfs(n, m, stepNumA,res); 
        dfs(n, m, stepNumB,res); 
    } 
} 
vector<int> Solution::stepnum(int A, int B) {
    vector<int> res;
    for(int i=0;i<=9;i++)
    {
        dfs(A,B,i,res);
    }
    sort(res.begin(),res.end());
    return res;
    
}