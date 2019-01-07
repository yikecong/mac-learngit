#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;


vector<Interval> merge(vector<Interval>& intervals) {
    int len = intervals.size();
    if (len == 0)
        return intervals;
    sort(intervals.begin(), intervals.end(), cmp);
    vector<Interval> res;
    res.push_back(intervals[0]);
    
    for (int i = 1; i < len; i++){
        Interval& back = res.back();//引用
        
        if (intervals[i].start <= back.end){//=也算重合
            //back.end = intervals[i].end;
            back.end=max(back.end,intervals[i].end);//
        }
        else{
            res.push_back(intervals[i]);
        }
        
    }
    return res;
}

vector<Interval> res;
int main()

{
    
    int m;
    cin>>m;
    int n=m;
    vector<string> v;
    while(m--)
    {
        string s;
        cin>>s;
        v.push_back(s);
        
    }
    
    vector<Interval> vv;
    int c=0;
    Interval temp;
    for(int i=0;i<n;i++)
        
    {
        int index=0;
        for(int j=0;j<v[i].size();j++)
        {
            string ss;
            
            if(v[i][j]==','||v[i][j]==';'||j==v[i].size()-1)
              {
                if(j==v[i].size()-1)
                    j++;
                  
                ss=v[i].substr(index,j-index);
                int b=stoi(ss,NULL);
                  
                  if(c%2==0)
                  {  temp.start=b;
                      c++;
                  }
                  else
                  {   temp.end=b;
                      c++;
                      vv.push_back(temp);
                  }
                index=j+1;
              }
            
        }
        
     }
    res=merge(vv);
    
    for(int i=0;i<res.size();i++)
    cout<<res[i].start<<','<<res[i].end<<';';
    cout<<endl;
    return 0;
 
}
