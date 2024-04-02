#include <iostream>
#include<stack>
using namespace std;
// void Solve(stack<int> &s, int target){
//   if(s.empty()){
//     s.push(target);
//     return;
//   }
//   int topelement=s.top();
//   s.pop();
//   //recursive call
//   Solve(s,target);
//   //backtrack
//   s.push(topelement);
// }
void insertAtBottom(stack<int>&s,int target){
  if(s.empty()){
    s.push(target);
    return;
  }
  int topelement=s.top();
  s.pop();
  //recursive call
  insertAtBottom(s,target);
  //backtrack
  s.push(topelement);
}

void reversestack(stack<int>& s){
  //base case
  if(s.empty()){
    return;
  }
  int target=s.top();
  s.pop();

  //reverse stack
  reversestack(s);
  //insert at bottom
  insertAtBottom(s,target);
}

void insertSorted(stack<int>&s, int target){
  //base case
  if(s.empty()){
    s.push(target);
    return;
  }
  if(s.top()>=target){
    s.push(target);
    return;
  }

  int topelement=s.top();
  s.pop();
  insertSorted(s,target);
  //BT
  s.push(topelement);
}
void sortStack(stack<int>&s){
  //base case
  if(s.empty()){
    return;
  }
  int topelement=s.top();
  s.pop();
//recursion
  sortStack(s);
  //insert
  insertSorted(s,topelement);
}
int main() {
  // stack<int>s;
  // s.push(10);
  //  s.push(20);
  //  s.push(30);
  //  s.push(40);
  //  s.push(50);
  // if(s.empty()){
  //   cout<<"Stack is empty"<<endl;
  //   return 0;
  // }
  // int target=s.top();
  // s.pop();
  
  // insertAtBottom(s,target);

  // cout<<"Printing Stack "<<endl;

  // while(!s.empty()){
  //   cout<<s.top()<<" ";
  //   s.pop();
  // }


  //reverse a stack
  // stack<int>s;
  // s.push(10);
  // s.push(20);
  // s.push(30);
  // s.push(40);
  // s.push(50);

  // // cout<<"Printing Stack "<<endl;

  // // while(!s.empty()){
  // //   cout<<s.top()<<" ";
  // //   s.pop();
  // // }
  // reversestack (s);

  // cout<<"Printing Stack "<<endl;

  // while(!s.empty()){
  //   cout<<s.top()<<" ";
  //   s.pop();
  // }



  //sort a stack
  stack<int>s;
  s.push(7);
  s.push(11);
  s.push(3);
  s.push(5);
  s.push(9);

  sortStack(s);

  cout<<"Printing Stack "<<endl;

  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }cout<<endl;
  return 0;
}