#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> v;
    vector<pair <string ,string> > pv;
    string temp;
    string pushstr="";
    bool flag=false;
    for(int i=0;i<record.size();i++){
        for(int j=0;j<record[i].size();j++){
            if(record[i][j]==' '){
                v.push_back(temp);
                temp="";
            }else{
                temp+=record[i][j];
            }
        }
        v.push_back(temp);
        temp="";
        if(v[0]=="Enter"){
            for(int j=0;j<pv.size();j++){
                if(pv[j].first==v[1]){
                    pv[j].second=v[2];
                    flag=true;
                }
            }
            if(!flag){
                pv.push_back({v[1],v[2]});
            }
            flag=false;
        }else if(v[0]=="Change"){
            for(int j=0;j<pv.size();j++){
                if(pv[j].first==v[1]){
                    pv[j].second=v[2];
                }
            }
        }
      
        v.clear();    
    }
   
    for(int i=0;i<record.size();i++){
        for(int j=0;j<record[i].size();j++){
            if(record[i][j]==' '){
                v.push_back(temp);
                temp="";
            }else{
                temp+=record[i][j];
            }
        }
        v.push_back(temp);
        temp="";
        if(v[0]=="Enter"){
            for(int j=0;j<pv.size();j++){
                if(pv[j].first==v[1]){
                    pushstr=pv[j].second+"´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
                    answer.push_back(pushstr);
                    pushstr="";
                }
            }
        }else if(v[0]=="Leave"){
            for(int j=0;j<pv.size();j++){
                if(pv[j].first==v[1]){
                    pushstr=pv[j].second+"´ÔÀÌ ³ª°¬½À´Ï´Ù.";
                    answer.push_back(pushstr);
                    pushstr="";
                }
            }
        }
        v.clear();
    }
    
    
    return answer;
}
