#include<bits/stdc++.h>
using namespace std;

int cutting_chocolate(int p[][100], int tp[], int tpl[], int tpw[], int chocolate_area, int len, int wid){
    int i, j, maxx=-1;

    //finding pieces and max profit
    for(i=1;i<=len; i++){
        for(j=i;i*j<=chocolate_area && j<=wid; j++){
            if( p[i][j]+ tp[chocolate_area-(i*j)]>maxx ){
                maxx=p[i][j]+ tp[chocolate_area-(i*j)];
                tpw[chocolate_area]=j;
                tpl[chocolate_area]=i;
            }
        }
    }
    tp[chocolate_area]=maxx;

    return 1;
}

void print_max_profit_and_pieces(int tp[],int tpl[],int tpw[], int chocolate_area){
    int i;

    cout<<tp[chocolate_area]<<" ";
    cout<<"If we want to make a chocolate of area ("<<chocolate_area<<") then our max profit is: "<<tp[chocolate_area]<<" ";
    cout<<"and for that we need to take ";

    for(i=chocolate_area;i!=0;){
        cout<<"(";
        cout<<tpl[i]<<"*"<<tpw[i];
        i-=(tpl[i]*tpw[i]);
        cout<<")";
        if(i!=0) cout<<", ";
    }
    cout<<" area of single piece chocolate."<<endl;
}

int main()
{
    int profit[100][100]={}, track_piece_W[100]={}, track_piece_L[100]={}, tot_profit[100]={};
    int number, length, width, tot_area, k, l;

    //taking input
    ifstream file("chocolateinput.txt");
    file>>number;
    length= number;

    file>>number;
    width=number;

    for(k=1; k<=length; k++){
        for(l=1;l<=width; l++){
            file>>number;
            profit[k][l]=number;
        }
    }

    file.close();

    //calculating tot_area
    tot_area=length*width;

    //calculating max profit and finds using which rods we get max profit
    for(k=1;k<=tot_area; k++) cutting_chocolate(profit, tot_profit, track_piece_L, track_piece_W, k, length, width);

    //printing max profit, how much single piece rod we need
    for(k=1;k<=tot_area; k++) print_max_profit_and_pieces(tot_profit, track_piece_L, track_piece_W, k);
}
