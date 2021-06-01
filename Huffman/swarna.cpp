#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char str[1000];
set<char>character;//to get distinct characters.
map<char,ll>frequency;
map<char,string>encode;
//map<string,char>decode;//for second way
struct node{
          char ch;
          ll freq;
          struct node *left,*right;
};
struct node *pq[1000];
struct node* new_node(char a,ll f,struct node *left_child,struct node *right_child)//creating new node
{
          struct node *temp=(struct node*)malloc(sizeof(struct node));
          temp->ch=a;
          temp->freq=f;
          temp->left=left_child;
          temp->right=right_child;
          return temp;

}
void encoding(struct node *temp,string strg)
{
          if(temp->left==NULL&&temp->right==NULL)
          {
                    encode[temp->ch]=strg;
                   // decode[strg]=temp->ch;
                    cout<<temp->ch<<":"<<strg<<endl;
                    return;
          }
          encoding(temp->left,strg+"0");
          encoding(temp->right,strg+"1");
}
/*
Second way:
void decoding(string prefix_code)
{
          ll i;
          string s;
          for(i=0;prefix_code[i]!='\0';i++)
          {
                    s.push_back(prefix_code[i]);
                    if(decode[s]!='\0'){
                              cout<<decode[s];
                              s="";
                    }
          }
}*/
void decoding(string prefix_code,struct node *root)
{
          ll i;
          struct node *n=(struct node*)malloc(sizeof(struct node));
          n=root;
          for(i=0;prefix_code[i]!='\0';i++)
          {
                    if(prefix_code[i]=='1'&&n->right!=NULL)n=n->right;
                    else if(prefix_code[i]=='0'&&n->left!=NULL)n=n->left;
                    if(n->ch!='\0'){
                              cout<<n->ch;
                              n=root;
                    }
          }
}
void min_heapify(ll n,ll root)
{
          ll l=root*2+1,r=root*2+2,minimum=root;
           cout<<"Inside heapify"<<endl;
          if(l<n&&pq[minimum]->freq>pq[l]->freq)minimum=l;
          if(r<n&&pq[minimum]->freq>pq[r]->freq)minimum=r;
          if(pq[minimum]->freq!=pq[root]->freq)
          {
                    swap(pq[minimum],pq[root]);
                    min_heapify(n,minimum);
          }
}
void insert_heap(ll len)
{
          while(len)
          {
                    ll parent=(len-1)/2;
                    if(pq[parent]->freq>pq[len]->freq){
                              swap(pq[parent],pq[len]);
                              len=parent;
                    }
                    else return;
          }
}
void huffman_code()
{
          set<char>::iterator it;
          ll i=0,n=character.size();
          for(it=character.begin();it!=character.end();it++)
          {
                    pq[i]=new_node(*it,frequency[*it],NULL,NULL);
                    i++;
          }
          for(ll k=i/2-1;k>=0;k--){
                    min_heapify(i,k);
                    cout<<"run";}
          while(n>1)
          {
                    struct node *left_child=(struct node*)malloc(sizeof(struct node)),*right_child=(struct node*)malloc(sizeof(struct node));
                    left_child=pq[0];//inserting the least minimum node as left child in huffman tree
                    swap(pq[0],pq[n-1]);n--;//deleting the minimum node to get next minimum node
                    min_heapify(n,0);//after deleting the minimum node if we min heapify the array we will get the next minimum node
                    right_child=pq[0];//inserting the next minimum node as right child in huffman tree
                    swap(pq[0],pq[n-1]);
                    min_heapify(n-1,0);//after swapping the last node with the root node we are operating min heapify  on the array excluding the last node as we will insert the parent of left and right child rather deleting the last node.
                    pq[n-1]=new_node('\0',left_child->freq+right_child->freq,left_child,right_child);//creating the parent
                    insert_heap(n-1);// inserting the parent in the min heap
          }
          struct node *root=NULL;
          root=pq[0];
          encoding(root,"");
          string pre_code;//prefix code
          cout<<"Encoded message is:"<<endl;
          for(i=0;str[i]!='\0';i++)
          {
                    cout<<encode[str[i]];
                    pre_code=pre_code+encode[str[i]];
          }
          cout<<endl;
          cout<<"length of the prefix code:"<<pre_code.size()<<endl;
          cout<<"Decoded message is:"<<endl;
          decoding(pre_code,root);
}
int main()
{
          FILE *file;
          file=fopen("input.txt","r");
          char a;
          ll i=0;
          while((a=fgetc(file))!=EOF)
          {
                    str[i]=a;
                    frequency[a]++;
                    character.insert(a);
                    i++;
          }
          huffman_code();
          cout<<"\nActual message is:\n"<<str<<endl;
}
