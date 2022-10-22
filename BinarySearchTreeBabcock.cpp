/*****************************************
 * Name: Binary Search Tree Assignment
 * Author: Tanner Babcock
 * Created: October 22, 2022
 * Course: CIS 152 - Data Structures
 * Version: 1.0
 * OS: Void GNU/Linux
 * IDE: Emacs
 * Copyright : This is my own original work based
 * on specifications issued by our instructor.
 * Academic Honesty: I attest that this is my original
 * work. I have not used unauthorized source code,
 * either modified or unmodified. I have not given
 * other fellow student(s) access to my program.
******************************************/
#include <iostream>
#include <string>
using namespace std;

typedef struct node_t {
    string name;
    int position;
    struct node_t *left;
    struct node_t *right;
} node;

node *newNode(int pos, string name) {
    return new (node){ .name = name, .position = pos, .left = NULL, .right = NULL };
}

node *search(node *root, int pos) {
    if (!root || root->position == pos)
        return root;

    if (root->position < pos)
        return search(root->right, pos);
    return search(root->left, pos);
}

node *search(node *root, string name) {
    if (!root || root->name == name)
        return root;

    return search(root->right, name);
}

node *insert(node *root, int pos, string name) {
    if (!root)
        return newNode(1, name);

    /* recur down the tree */
    if (pos < root->position)
        root->left = insert(root->left, pos, name);
    else if (pos > root->position)
        root->right = insert(root->right, pos, name);
    return root;
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->position << ". " << root->name << endl;
        inorder(root->right);
    }
}

int main(void) {
    node *boysNameTree = newNode(1, "Noah");
    boysNameTree->right = newNode(2, "Liam");
    inorder(boysNameTree);

    delete boysNameTree;
    return 0;
}
