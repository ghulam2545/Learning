#include <iostream>
struct Node {
    int data;
    Node *link;
};
int main() {
    Node *head;
    Node *node[5];
    for(int i=0; i<5; i++) {
        node[i] = new Node();
        node[i]->data = (i+100);
    }
    head = node[0];
    for(int i=0; i<4; i++) {
        node[i]->link = node[i+1];
    }
    node[4]->link = NULL;

    // Printing ...
    Node *temp = head;
    while(temp != NULL) {
        std::cout<<temp->data<<" ";
        temp = temp->link;
    }
    return 0;
}