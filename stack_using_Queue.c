#include <stdio.h>
#define SIZE 5

int queue1[SIZE], queue2[SIZE];
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;

//Function to insert an element into the stack
void push(int item) {
    if(rear1 == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    if(front1 == -1 && rear1 == -1) {
        front1 = rear1 = 0;
        queue1[rear1] = item;
        return;
    }
    queue1[++rear1] = item;
}

//Function to remove an element from the stack
int pop() {
    if(front1 == -1 || front1 > rear1) {
        printf("Stack Underflow\n");
        return -1;
    }
    while(front1 != rear1) {
        queue2[++rear2] = queue1[front1];
        front1++;
    }
    int element = queue1[front1];
    front1 = rear2 = -1;
    while(front2 <= rear2) {
        queue1[++rear1] = queue2[front2];
        front2++;
    }
    return element;
}

//Function to display the stack
void display() {
    if(front1 == -1 || front1 > rear1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    for(int i = front1; i <= rear1; i++) {
        printf("%d ", queue1[i]);
    }
    printf("\n");
}

//Main function to test the implementation
int main() {
    int choice, item;
    while(1) {
        printf("\nMenu:\n");
        printf("1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Display the stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if(item != -1) {
                    printf("The popped element is: %d\n", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting from the program\n");
                return 0;
            default:
                printf("Invalid choice, please try again!\n");
        }
    }
    return 0;
}
