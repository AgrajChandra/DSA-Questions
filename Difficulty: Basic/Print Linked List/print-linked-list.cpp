//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};


// } Driver Code Ends

class Solution {
  public:
    // Function to display the elements of a linked list in same line
    void printList(Node *head) {
        // your code goes here
        Node* temp=head; // temp ptr pointing to head
        while(temp!=NULL){  //traverse till the last element
            cout<<temp->data<<" "; //print each element
            temp=temp->next; // increment temp ptr
        }
    }
};








//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        // Building the linked list from input
        while (ss >> x) {
            if (head == nullptr) {
                head = new Node(x);
                tail = head;
            } else {
                tail->next = new Node(x);
                tail = tail->next;
            }
        }

        Solution ob;
        ob.printList(head);
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends