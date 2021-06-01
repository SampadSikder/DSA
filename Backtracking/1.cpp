#include<iostream>
using namespace std;

void stringPermutation(string str, int left, int right) {
   if(left == right)
      cout << str << endl;
   else {
      for(int i = left; i<= right; i++) {
         if(str[left]==str[i]){
            stringPermutation(str, left + 1, right);
         }
         swap(str[left], str[i]);
         stringPermutation(str, left + 1, right);
         swap(str[left], str[i]); //swap back for backtracking
      }
   }
}

int main() {
   string str = "ABC";
   cout << "All permutations of " << str << " is: " <<endl<<endl;
   stringPermutation(str, 0, str.size()-1);
}
