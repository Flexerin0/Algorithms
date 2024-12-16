#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (!root) {
        return new Node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

bool search(Node* root, int value) {
    if (!root) {
        return false;
    }

    if (value == root->value) {
        return true;
    }
    else if (value < root->value) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

Node* findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

Node* remove(Node* root, int value) {
    if (!root) {
        return nullptr;
    }

    if (value < root->value) {
        root->left = remove(root->left, value);
    }
    else if (value > root->value) {
        root->right = remove(root->right, value);
    }
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* minNode = findMin(root->right);
            root->value = minNode->value;
            root->right = remove(root->right, minNode->value);
        }
    }

    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

void testBST() {
    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Все элементы дерева: ";
    inorder(root);

    cout << "\n\nПоиск элементов:";
    cout << "\nПоиск 40: ";
    if (search(root, 40)) {
        cout << "найдено";
    }
    else {
        cout << "не найдено";
    }
    cout << "\nПоиск 90: ";
    if (search(root, 90)) {
        cout << "найдено";
    }
    else {
        cout << "не найдено";
    }

    cout << "\n\nУдаление 50:";
    root = remove(root, 50);
    cout << "\nДерево после удаления 50: ";
    inorder(root);

    cout << "\n\nУдаление 30:";
    root = remove(root, 30);
    cout << "\nДерево после удаления 30: ";
    inorder(root);

    cout << "\n\n";
}

int main() {
    setlocale(LC_ALL, "ru");

    testBST();

    return 0;
}
