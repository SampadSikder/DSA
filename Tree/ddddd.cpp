#include<bits/stdc++.h>
using namespace std;

const int N = 101;
int bal[N];
// basically ekhane order gula store kore rekhe pore print korbe
vector<int> sumoner_bal; // post order
vector<int> baler_sumon; // pre order
vector<int> sumon_nije_bal; // in order


// func for preorder
void sumon_re_chudi_one(int cur,int total_node){

	if(cur >= total_node) return;
	if(bal[cur] == -1) return;

	baler_sumon.push_back(bal[cur]);

	//1st recursive call -> left e jabe
	sumon_re_chudi_one(2*cur,total_node);
	//2nd recursive call -> right e jabe
	sumon_re_chudi_one(2*cur+1,total_node);
}

// func for postorder
void sumon_re_chudi_two(int cur, int total_node){

	if (cur >= total_node) return;
	if (bal[cur] == -1) return;

	sumon_re_chudi_two(2*cur,total_node);
	sumon_re_chudi_two(2*cur+1,total_node);

	sumoner_bal.push_back(bal[cur]);
}

// fucn for in order
void sumon_re_chudi_three(int cur, int total_node){

	if (cur >= total_node) return;
	if (bal[cur] == -1) return;

	//sumoner_bal.push_back(bal[cur]);

	sumon_re_chudi_three(2*cur,total_node);

	sumon_nije_bal.push_back(bal[cur]);

	sumon_re_chudi_three(2*cur+1,total_node);

	//sumoner_bal.push_back(bal[cur]);
}


int main (){

	int n;
	cin>>n;

	int blank_soho = 1;
	int asole_ase_koyta = 0;

	while (1){
		int x;
		cin>>x;

		if (x==-1){
			bal[blank_soho++] = x;
		}
		else {
			bal[blank_soho++] = x;
			asole_ase_koyta++;
		}
		if (asole_ase_koyta == n) break;
	}

	for (int i = 1; i<blank_soho;i++){

		printf("%4d ",bal[i]);
	}
	puts("");
	for (int i=1;i<blank_soho;i++){
		printf("%4d ",i);
	}
	puts("");

	sumon_re_chudi_one(1,blank_soho);

	printf("Pre order : ");
	for (int x : baler_sumon) printf("%4d ",x) ;
	puts("");

	sumon_re_chudi_two(1,blank_soho);

	printf("Post order : ");
	for (int x : sumoner_bal) printf("%4d ",x) ;
	puts("");

	sumon_re_chudi_three(1,blank_soho);

	printf("In order : ");
	for (int x : sumon_nije_bal) printf("%4d ",x) ;
	puts("");
}
