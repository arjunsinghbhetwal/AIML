#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;


// Node
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
};


// Iterative BST
class IterativeBST {
public:
    Node* root;

    IterativeBST() {
        root = nullptr;
    }

    void insert(int key) {
        Node* newNode = new Node(key);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;

        while (true) {
            if (key < current->key) {

                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                }

                current = current->left;
            }

            else if (key > current->key) {

                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                }

                current = current->right;
            }

            else {
                // Duplicate element
                delete newNode;
                return;
            }
        }
    }


    bool search(int key) {
        Node* current = root;

        while (current != nullptr) {

            if (key == current->key)
                return true;

            else if (key < current->key)
                current = current->left;

            else
                current = current->right;
        }

        return false;
    }
};


// Recursive BST
class RecursiveBST {
public:
    Node* root;

    RecursiveBST() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    Node* insertRecursive(Node* root, int key) {

        if (root == nullptr)
            return new Node(key);

        if (key < root->key)
            root->left = insertRecursive(root->left, key);

        else if (key > root->key)
            root->right = insertRecursive(root->right, key);

        return root;
    }


    bool search(int key) {
        return searchRecursive(root, key);
    }

    bool searchRecursive(Node* root, int key) {

        if (root == nullptr)
            return false;

        if (root->key == key)
            return true;

        else if (key < root->key)
            return searchRecursive(root->left, key);

        else
            return searchRecursive(root->right, key);
    }
};


int main() {

    const int N = 10000;
    const int SEARCHES = 1000;

    vector<int> values;
    vector<int> searchValues;

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dist(1, 1000000);


    // Generate 10,000 random elements
    for (int i = 0; i < N; i++) {
        values.push_back(dist(gen));
    }


    // Select 1,000 search values
    for (int i = 0; i < SEARCHES; i++) {
        searchValues.push_back(values[i]);
    }


    // ---------------- ITERATIVE BST ----------------

    IterativeBST iterativeBST;

    auto start = high_resolution_clock::now();

    for (int value : values)
        iterativeBST.insert(value);

    auto end = high_resolution_clock::now();

    double iterativeInsertTime =
        duration<double>(end - start).count();


    start = high_resolution_clock::now();

    for (int value : searchValues)
        iterativeBST.search(value);

    end = high_resolution_clock::now();

    double iterativeSearchTime =
        duration<double>(end - start).count();


    // ---------------- RECURSIVE BST ----------------

    RecursiveBST recursiveBST;

    start = high_resolution_clock::now();

    for (int value : values)
        recursiveBST.insert(value);

    end = high_resolution_clock::now();

    double recursiveInsertTime =
        duration<double>(end - start).count();


    start = high_resolution_clock::now();

    for (int value : searchValues)
        recursiveBST.search(value);

    end = high_resolution_clock::now();

    double recursiveSearchTime =
        duration<double>(end - start).count();


    // ---------------- OUTPUT ----------------

    cout << "BINARY SEARCH TREE PERFORMANCE\n";
    cout << "------------------------------\n";

    cout << "Number of elements: " << N << endl;
    cout << "Number of searches: " << SEARCHES << endl;


    cout << "\nInsertion Time\n";

    cout << "Iterative: "
         << iterativeInsertTime
         << " seconds\n";

    cout << "Recursive: "
         << recursiveInsertTime
         << " seconds\n";


    cout << "\nSearch Time\n";

    cout << "Iterative: "
         << iterativeSearchTime
         << " seconds\n";

    cout << "Recursive: "
         << recursiveSearchTime
         << " seconds\n";


    cout << "\nComparison\n";

    if (iterativeInsertTime < recursiveInsertTime)
        cout << "Iterative insertion is faster\n";
    else
        cout << "Recursive insertion is faster\n";


    if (iterativeSearchTime < recursiveSearchTime)
        cout << "Iterative search is faster\n";
    else
        cout << "Recursive search is faster\n";


    return 0;
}