#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* getNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = getNewNode(data);
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* remove(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    else if (data < root->data) {
        root->left = remove(root->left, data);
    }
    else if (data > root->data) {
        root->right = remove(root->right, data);
    }
    else {
        // case 1: no child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        // case 2: one child
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }
    return root;
}

void printMenu()
{

    cout << "Binary Search Tree Program" << endl;
    cout << "--------------------------" << endl;
    cout << "1. �������� �������" << endl;
    cout << "2. �������� �������" << endl;
    cout << "3. ������� ������" << endl;
    cout << "4. �����" << endl;
    cout << "--------------------------" << endl;

}

void printTreeMenu()
{

    cout << "������� ������� ������ ������:" << endl;
    cout << "1. ������ ������� (pre-order)" << endl;
    cout << "2. ����������� ������� (in-order)" << endl;
    cout << "3. �������� ������� (post-order)" << endl;
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}





void printTree(Node* root) {

    int choice;
    printTreeMenu();
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "������ �������: ";
        preOrder(root);
        cout << endl;
        break;
    case 2:
        cout << "����������� �������: ";
        inOrder(root);
        cout << endl;
        break;
    case 3:
        cout << "�������� �������: ";
        postOrder(root);
        cout << endl;
        break;
    default:
        cout << "������� ����" << endl;
    }
}

int main() {

    Node* root = NULL;
    int choice, data;

    while (true) {
        printMenu();
        cout << "��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������ �������� ��������: ";
            cin >> data;
            root = insert(root, data);
            break;
        case 2:
            cout << "������ �������� ��������: ";
            cin >> data;
            root = remove(root, data);
            break;
        case 3:
            printTree(root);
            break;
        case 4:
            exit(0);
        default:
            cout << "������� ����. ��������� �� ���." << endl;
        }
    }

    return 0;
}