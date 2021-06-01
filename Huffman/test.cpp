#include<bits/stdc++.h>
#include<cstdio>

#define MAX 100
using namespace std;

set<char>s;
map<char,int>frequency;

int main(){
    freopen("input.txt","r",stdin);
    char a[100]={};
    int i=0;
    while(a[i]!=EOF){
        cin>>a[i];
        frequency[a[i]]++;
        s.insert(a[i]);
        i++;
    }

    fflush(stdin);



    set<char>::iterator x;

     for (x = s.begin(); x != s.end(); ++x) {
        cout << '\t' <<*x<<"\n";

    }
    map<char, int>::iterator itr;
    cout << "\nThe map gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = frequency.begin(); itr != frequency.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;



//    calculatefrequency(a);


//
//    //frequencies
//    for(int i=0;i<26;i++){
//
//          cout<<char(i+'a')<<":"<<item[i]<<" ";
//    }
//    cout<<endl;
//    sort(frequency,frequency+26);
//
//    int n=0;
//
//    while(a[n]!=0){n++;}

//    huffmancodes();


}
