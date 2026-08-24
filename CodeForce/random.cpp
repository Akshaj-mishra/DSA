#include <bits/stdc++.h>
using namespace std;

struct  node{
    int data;
    node* next;

    node(){
        data = 0;
        next = nullptr;
    }

    node (int x){
        data = x;
        next = nullptr;
    }
};



int main(){
    node* head = new node(1);
    node* temp1 = new node(2);

    head->next = temp1;


    node* temp2 = new node(3);

    temp1->next = temp2;

    temp2 ->next = head;



    node* temp = head;
    int count = 0;

    while (count < 3) {
        cout << temp->data << endl;
        temp = temp->next;
        count++;
    }

}