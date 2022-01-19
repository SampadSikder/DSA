#include<bits/stdc++.h>
#define N 100
using namespace std;

int tree[N]={-1};

struct node{
    int root;
    node *left,*right;
};
node *root=NULL;
int pre_index=1;

node *buildPreAndin(vector <int>&pre,vector<int>&in,int start,int end){
    if(start>end)return NULL;
    node *temp= (node*)malloc(sizeof(node));

    temp->root=pre[pre_index++];
    temp->left=temp->right=NULL;

    if(pre_index==2)root=temp;

    if(start==end)return temp;

    int inorder_index;

    for (int i=0;i<(int)in.size();i++){
		if (in[i] == temp->root) {
			inorder_index = i;
			break;
		}
	}
	node *l = buildPreAndin(pre,in,start,inorder_index-1);
	node *r = buildPreAndin(pre,in,inorder_index+1,end);


	temp->left = l;
	temp->right = r;
	return temp;
}
void tree_generate(int index,node *cur){
    tree[index] = cur->root;
	if (cur->left == NULL && cur->right == NULL) return;

	if (cur->left != NULL) tree_generate(index*2,cur->left);
	if (cur->right != NULL) tree_generate(index*2 + 1, cur->right);
}

int main (){

	int n;
	cout<<"Enter number of nodes:";
	cin>>n;

	memset(tree,-1,N);

	vector<int> pre,in,post;

	//0th index theke suru korar jonno
	pre.push_back(-1);
	in.push_back(-1);

	cout<<"Enter Preorder: ";
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		pre.push_back(x);
	}
	//cout<<endl;

	cout<<"Enter postorder: ";
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		in.push_back(x);
	}
	//cout<<endl;
	pre_index = 0;
	buildPreAndin(pre,in,1,n);

	tree_generate(1,root);

	for (int i=1;i<=10;i++) cout << tree [i] << " ";
	cout << endl;
}
