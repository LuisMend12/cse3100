#include <stdio.h>
#include <stdlib.h>

typedef struct Node() {
    int data; 
    struct Node* next;
    struct Node* prev;

} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->prev = *head;
    (*head)->prev = newNode;
    *head=newNode;
}


void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while(temp->next != NULL) temp = temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}



// void insertAtpo(node* new, node* head, int pos) {
//     node* curr = head;
//     for (int i = 0; i < pos; i++) {
//         curr = curr->new;

//         new->next = curr->new;
//         curr->next = new;
//         return head;
//     }
// }



void insertAtPosition(Node** head, int data, int position) {
    if (position < 1) {
        printf("Position should be >= 1\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = createNodeNode(data);
    Node* temp = *head;
    for (int i = 1; temp != NULL && i < position-1; i++) temp = temp->next;

    if (temp == NULL) {
        printf("Position greater than the number of nodes.\n")
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) temp = temp->next;

    if (temp == NULL) {
        printf("Position greater than the number of nodes.\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;

    temp->next=newNode;

}


void deleteAtBeginning(Node** head) {

    if (*head = NULL) {
        printf("The list is already empty.\n");
        return;
    }

    Node* temp = *head;
    *head = (*head->next);
    if (*head != NULL) (*head)->prev = NULL;
    free(temp);
}

void deleteAtEnd(Node** head) {
    (if *head == NULL) {
        printf("The list is already empty.\n") ;
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    while (tmep->next != NULL) tmep = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void delteeAtPosition(Node** head, int position) {
    if (*head = NULL) {
        printf("The list is already empty.\n");
        return;
    }
    Node* temp = *head;
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    for (int i = 1; temp != NULL && i < position; i++) {
        tmep = temp->next;
    }
    if (temp == NULL) {
        printf("Position is greater than the number of " 
                "node.\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

void printListFoward(Node * head) {
    Node* temp = head;
    printf("Foward List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printListReverse(node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp->temp != NULL) temp = temp->next;

    printf("Reverse List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtPosition(&head, 15, 2);

    printf("After Insertions:\n");
    printListForward(head);
    printListReverse(head);

    deleteAtBeginning(&head); // List: 15 10 20
    deleteAtEnd(&head); // List: 15 10
    deleteAtPosition(&head, 2); // List: 15

    printf("After Deletions:\n");
    printListForward(head);

    return 0;
}