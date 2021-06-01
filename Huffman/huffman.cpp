#include<bits/stdc++.h>
#include<cstdio>

#define MAX 100
using namespace std;
char a[1000]={};

set<char>s;
map<char,int>frequency;
map<char,string>enmsg;

struct MinNode{
    char item;
    int freq;
    struct MinNode *left,*right;
};
struct MinNode *node[1000];

//struct MinHeap{
//    int len;
//    int cap;
//    struct MinHeap **arr;
//};


//Creating new node func
struct MinNode *newNode(char x,int y,struct MinNode *left_child, struct MinNode *right_child){
    struct MinNode *temp=(struct MinNode*)malloc(sizeof(struct MinNode));

    temp->left=left_child;
    temp->right=right_child;
    temp->item=x;
    temp->freq=y;

    return temp;

}

//Creating New Heap func
//struct MinHeap *createMinH(int cap){
//    struct MinHeap *newHeap=(struct MinHeap*)malloc(sizeof(struct MinHeap));
//    MinHeap->len=0;
//    MinHeap->cap=cap;
//
//    MinHeap->arr=(struct MinHeap**)malloc(MinHeap->cap*sizeof(struct MinHeap*));
//
//    return MinHeap;
//}
//
//
//
//struct MinNode *buildTree(int item[],int n){
//    struct MinHeap *minHeap=createMinH(n);
//
//    for(int i=0;i<n;i++){
//        minHeap->arr[i]=
//    }
//}

void MinHeapify(int n,int root){
    int l=root*2+1,r=root*2+2;
    int mn=root;//minimum value


    if(l<n && node[mn]->freq > node[l]->freq) mn=l;
    if(r<n && node[mn]->freq > node[r]->freq) mn=r;

    if(node[mn]->freq != node[root]->freq){
        swap(node[mn],node[root]);
        MinHeapify(n,mn);
    }

}

void InsertHeap(int len){
    while(len){
        int parent=(len-1)/2;
        if(node[parent]->freq > node[len]->freq){
            swap(node[parent],node[len]);
            len=parent;
        }
        else return;
    }
}
void encode(struct MinNode *temp, string str){
    if(temp->left == NULL && temp->right == NULL){
        enmsg[temp->item]=str;
        cout<<temp->item<<":"<<str<<endl;
        return;
    }
    encode(temp->left ,str+"0");//left er dike 0
    encode(temp->right, str+"1");//right e gele 1
}

void decode(struct MinNode *temp, string str){
    int i;
    struct MinNode *n = (struct MinNode*)malloc(sizeof(struct MinNode));
    n=temp;

    for(i=0 ; str[i] !='\0';i++){
        if(str[i]=='1' && n->right != NULL) n=n->right; //GO right if 1
        if(str[i]=='0' && n->left != NULL) n=n->left;   //Go left if 0

        if(n->item!='\0'){
                cout<<n->item;
                n=temp;

        }
    }

}




void huffmancodes(){
    int i=0,n=s.size();

    set<char>::iterator itr;
    for(itr=s.begin();itr!=s.end();itr++){
        node[i]=newNode(*itr,frequency[*itr],NULL,NULL);
        i++;
    }
    for(int k=i/2-1;k>=0;k--){
       MinHeapify(i,k);
    }
    while(n>1){
            struct MinNode *left_child=(struct MinNode*)malloc(sizeof(struct MinNode));
            struct MinNode *right_child=(struct MinNode*)malloc(sizeof(struct MinNode));

            left_child=node[0]; //Inserting smallest value as left child
            swap(node[0],node[n-1]);
            n--;  //deleting minimum node to get next minimum node
            MinHeapify(n,0);

            right_child=node[0]; //inserting next smallest as right child
            swap(node[0],node[n-1]);
            node[n-1]=newNode('\0',left_child->freq+right_child->freq,left_child,right_child);

            MinHeapify(n-1,0);

            //node[n-1]=newNode('\0',left_child->freq+right_child->freq,left_child,right_child);//Parent is the sum of two small frequencies

            //InsertHeap(n-1);
    }
    struct MinNode *root = NULL;
    root=node[0];
    string enc;

    encode(root, "");
    cout<<"Encoded msg is: "<<endl;

    for(i=0;a[i]!='\0';i++){
        cout<<enmsg[a[i]];
        enc=enc+enmsg[a[i]];
    }
    cout<<endl;

    cout<<"Decoded message is:"<<endl;
    decode(root,enc);


}

//void calculatefrequency(char a[]){
//    int i,j;
//
//    for(i=0;a[i]!='\0';i++){
//            if(a[i]>='a' && a[i]<='z'){
//            j=a[i]-'a';
//            frequency[j]++;
//        }
//            else if(a[i]==' '){
//                continue;
//            }
//    }
//}



int main(){
    FILE *file;
    file=fopen("input.txt","r");
    char x;
    int i=0;
    while((x=fgetc(file))!=EOF)
    {
            a[i]=x;
            frequency[x]++;
            s.insert(x);
            i++;
    }


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
    huffmancodes();

    cout<<"\nActual msg:"<<a<<endl;

}
