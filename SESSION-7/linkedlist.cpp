// =================================================

// NAME : ABHINEET
// UID : 24BCS10039

// =================================================

#include<iostream>
using namespace std;

class LinkedList {
    struct Node {
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
    };
    Node* head = nullptr;

    public:

    void addToEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void removeLast() {

        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void removeValue(int val) {

        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (head->value == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->value != val) 
        {
            temp = temp->next;
        }

        if (temp->next && temp->next->value == val) 
        {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        else 
        {
            cout << "Value not found\n";
        }
    }

    void showList() const {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty\n";
            return;
        }
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void clearList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void removeFromMiddle(int val) {
        if (!head || !head->next) {
            cout << "List too short\n";
            return;
        }
        if (head->value == val) {
            cout << "Cannot remove first node with this function\n";
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->next && temp->next->value != val) {
            temp = temp->next;
        }

        if (temp->next && temp->next->value == val && temp->next->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Removed from middle: " << val << "\n";
        } else {
            cout << "Node is not in the middle or not found\n";
        }
    }
};

int main() {
    LinkedList l;
    l.addToEnd(10);
    l.addToEnd(20);
    l.addToEnd(30);
    l.addToEnd(40);
    l.showList();

    // Try to remove a middle node (20)
    l.removeFromMiddle(20);
    l.showList();

    // Try to remove first node (should not remove)
    l.removeFromMiddle(10);
    l.showList();

    // Try to remove last node (should not remove)
    l.removeFromMiddle(40);
    l.showList();

    // Try to remove a value not in list
    l.removeFromMiddle(99);
    l.showList();

    l.clearList();
    l.showList();
    return 0;
}


// ======================================================================
// Time Complexity Of Each Function

// addToEnd:         O(n)   // Traverses the list to add at the end
// removeLast:       O(n)   // Traverses to the second last node
// removeValue:      O(n)   // Traverses to find the value
// showList:         O(n)   // Prints all nodes
// clearList:        O(n)   // Deletes all nodes
// removeFromMiddle: O(n)   // Traverses to find the value (not first/last)