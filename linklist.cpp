#include <iostream>

class Node{
    public:
    int data;
    Node *Next;
};

void printList(Node *H){
    std::cout<<"Head address in printList "<<H<<std::endl;
    while(H !=NULL){
        std::cout<<H->data<<"|";
        H = H->Next;
    }
    std::cout<<"\n";
}

void insertHead(Node **H, int val){
    Node *newNode = new Node();
    std::cout<<"Head address before insert "<<H<<std::endl;
    std::cout<<"New node address "<<newNode<<std::endl;
    newNode->data = val;
    newNode->Next = *H;
    std::cout<<"Address of new node pointing to "<<newNode->Next<<std::endl;
    *H = newNode;
    std::cout<<"Head address after insert "<<*H<<std::endl;
    //std::cout<<"Address of Head pointing to "<<*H->Next<<std::endl;

}

void insertTail(Node *H, int val){
    Node *newNode = new Node();
    newNode->Next = NULL;
    newNode->data = val;
    while(true)
    {
        if(H->Next == NULL){
            H->Next = newNode;
            break;
        }
        H = H->Next;
    }
}

void insertMid(Node *H, int val, int pos){
    Node *newNode = new Node();
    newNode->data = val;
    Node *temp = new Node();
    int nodePos = 1;
    while (H != NULL){
        if(nodePos == pos){
            temp = H->Next;
            H->Next = newNode;
            newNode->Next = temp;
            break;
        }
        H = H->Next;
        nodePos +=1;
    }   
}

int main(void){
    Node *head = new Node();
    head->data = 13;
    Node *second = new Node();
    second->data = 23;
    head->Next = second;
    Node *third = new Node();
    third->data = 8;
    second->Next = third;
    third->Next = NULL;
    std::cout<<"Head address in main "<<head<<std::endl;
    printList(head);
    //when inseting at tail we just need to pass the address of head pointing to, not the aaddress of head
    insertTail(head, 101);
    printList(head);
    insertTail(head, 120);
    printList(head);
    //when inseting at head we need to pass the address of head
    insertHead(&head, 5);
    printList(head);
    //when inseting at the middle, No need to pass address of head, just like insert tail
    insertMid(head, 109, 3);
    printList(head);
    return 0;
}