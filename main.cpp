#include <iostream>

using namespace std;

class node{
public:
    node* next;
    int val;

    node(){
        next = nullptr;
    }
};

class list{
private:
    node* head;
public:

    list(){
        head = nullptr;
    }

    void insert(int val);

    void sortList();

    void bubbleSort();

    bool checkIfListIsOrdered(node* list);

    friend
        ostream& operator<<(ostream &os, const list &l){
        node* iter = l.head;
        while(iter != nullptr){
            cout << iter->val << " -> ";
            iter = iter->next;
        }
        cout << "NULLPTR";
    }
};

bool list::checkIfListIsOrdered(node* list) {
    node* iter = head;
    while(iter->next != nullptr){
        if(iter->val > iter->next->val){
            return false;
        }
        iter = iter->next;
    }
    return true;
}

void list::bubbleSort() {
    node* iter1 = head;
    int app;
    while(iter1->next != nullptr){
        if(iter1->val > iter1->next->val){
            app = iter1->val;
            iter1->val = iter1->next->val;
            iter1->next->val = app;
        }
        else
            iter1 = iter1->next;
    }
}

void list::sortList() {
    while(!checkIfListIsOrdered(head))
        bubbleSort();
}

void list::insert(int val){
    node* iter = head;
    node* nuovo = new node();
    nuovo->val = val;

    if(head == nullptr){
        head = nuovo;
        nuovo->next = nullptr;
    }
    else{
        while(iter->next != nullptr){
            iter = iter->next;
        }
        iter->next = nuovo;
        nuovo->next = nullptr;
    }
}

int main() {
    list l;

    l.insert(1);
    l.insert(10);
    l.insert(5);
    l.insert(9);
    l.insert(11);
    l.insert(12);
    l.insert(4);
    l.insert(16);

    l.sortList();

    cout << l;
}
