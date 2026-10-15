#include<iostream>
using namespace std;

//Node of the BST
class Node{
    public:
    int key;
    Node* left;
    Node* right;

    //constructor
    Node(int value){
        key = value;
        left = nullptr;
        right = nullptr;
    }
};

//Iterative Binary Search Tree
class IterativeBST{
    public:
        Node* root;

        IterativeBST(){
            root=nullptr;
        }

        //===================================
        //INSERTION - ITERATIVE
        //===================================

        void insert(int key){

            //Create new node
            Node* newNode = new Node(key);

            //If tree is Empty
            if(root == nullptr){
                root = newNode;
                return;
            }

            //Start from root
            Node* current = root;

            //iterative BST insertion using while loop.
            //using while loop cuz we dont have fixed values to be inserted.
            while(true){

                //if key is smaller than the node.
                if(key < current->key){
                    
                    //if left doent exists
                    //insert in the newnode
                    if(current->left == nullptr){
                        current->left = newNode;
                        return;
                    }
                    //positioned to the newly inserted left Node.
                    current = current->left;
                }

                else if(key > current->key){

                    //if the child dosent exists
                    //insert newNode.
                    if(current->right == nullptr){
                        current->right = newNode;
                        return;
                    }
                    current = current->right;
                }

                else{
                    delete newNode;
                    return;
                }
            }
        }

        //==================================
        //SEARCHING - ITERATIVE
        //==================================

        bool search(int key){

            //start searching from root
            Node* current = root;

            //continue until the tree/subtree becomes empty/
            while (current != nullptr) {

                //key found
                if (key == current->key) {
                    return true;
                }

                else if (key < current->key) {
                    current = current->left;
                }

                else {
                    current = current->right;
                }
            }
            return false;
        }
};

int main(){

    IterativeBST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    if (bst.search(40))
        cout << "40 Found" << endl;
    else
        cout << "40 Not Found" << endl;


    if (bst.search(90))
        cout << "90 Found" << endl;
    else
        cout << "90 Not Found" << endl;

    return 0;
}