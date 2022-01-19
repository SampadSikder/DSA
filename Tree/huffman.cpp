#include<bits/stdc++.h>
using namespace std;


int frequency[26];

void calculatefrequency(string a){
    int i,j;

    for(i=0;a[i]!='\0';i++){
            if(a[i]>='a' && a[i]<='z'){
            j=a[i]-'a';
            frequency[j]++;
        }
            else if(a[i]==' '){
                continue;
            }
    }
}
void generatetree(){




    }



int main(){
    freopen("input.txt","r",stdin);
    string a;
    cin>>a;

    calculatefrequency(a);

    //frequencies
    for(int i=0;i<26;i++){
        cout<<char(i+'a')<<":"<<frequency[i]<<endl;
    }
    cout<<endl;
    sort(frequency,frequency+26);

    generatetree();


}
