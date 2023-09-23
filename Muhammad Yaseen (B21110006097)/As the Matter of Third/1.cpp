// A#05(As the Matter of Third).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
using namespace std;


struct Node {
    int val;
    Node* next;
    Node* prev;
};
Node* head = NULL;
Node* tail = NULL;


void ADD(int new_val) {
    Node* new_node = new Node;
    new_node->val = new_val;
    new_node->next = NULL;
    new_node->prev = tail;

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }
    else {
        Node* curr = head;
        //insertion at head(when only one node)
        if (curr == head && curr->next == NULL) {//it means only one node in list
            new_node->next = curr;
            curr->prev = new_node;
            tail = curr;//new addition (issue resolved)
            new_node->prev = NULL;
            head = new_node;
            return;
        }
        while (curr->next != NULL) {//when curr == last node it stops
            curr = curr->next;
        }
        //curr is the last node:
        curr->next = new_node;
        new_node->prev = curr;
        tail = new_node;
        tail->prev = curr;//addition
    }

}

void printThirdLastNode() {
    //Node* curr = head;
    if (tail == NULL) {
        cout << "-1" << endl;
        // cout << "Thre is no node in the list!" << endl;
    }
    else if (tail->prev == NULL) {
        cout << "-1" << endl;
        //cout << "Thre is only one node in the list!" << endl;
    }
    //else if (tail->prev->prev == NULL) {
    //    cout << "-1" << endl;
    //    //cout << "Thre is only two node in the list!" << endl;
    //}
    //else if (tail->prev->prev->prev == NULL) {
    //    cout << "-1" << endl;
    //    //cout << "Thre is only three node in the list!" << endl;
    //}
    else {
        Node *curr = tail->prev;
        cout << "Address of Third last node is: " << tail->prev->prev << endl;
        cout << "Third last node value is: " << tail->prev->prev->val << endl;
        cout<<curr->val<<endl;
    }
}

int main()
{
    int num;
    ifstream file;
    file.open("D:/YASEEN/yaseen/4th semester/DSA/Assignment#02/As the Matter of Third/Test01.txt");
    while(file.eof() == 0){
        file>>num;
        ADD(num);
        // file.get();
    }
    cout<<tail->val<<endl;
    printThirdLastNode();



    // cout<<tail<<endl;



    
    // int num, checker = 0;
    // fstream file;
    // file.open("D:/YASEEN/yaseen/4th semester/DSA/Assignment#02/As the Matter of Third/Test01.txt");
    // while (checker != -1) {
    //     file >> num;
    //     ADD(num);
    //     //cout << "Address of Third last node is: " << tail->prev->prev << endl;
    //     //cout << "Third last node value is: " << tail->prev->prev->val << endl;
    //     checker = file.get();
    // }
    // // Node* ans = tail->prev->prev->prev;
    // // cout << ans->val;
    // printThirdLastNode();


   
    // ADD(2);
    // ADD(3);
    // ADD(4);
    // ADD(5);
    // ADD(6);
    // ADD(2);
    // ADD(2);


    // printThirdLastNode();
    
    return 0;
}

