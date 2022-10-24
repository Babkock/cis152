/******************************************
 * Name: Binary Search Tree Assignment
 * Author: Tanner Babcock
 * Created: October 23, 2022
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
*******************************************/
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
        return newNode(pos, name);

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
	int x = 1;
    node *boysNameTree = newNode(x++, "Noah");
    boysNameTree->right = newNode(x++, "Liam");
	boysNameTree = insert(boysNameTree, x++, "Mason");
	boysNameTree = insert(boysNameTree, x++, "Jacob");
	boysNameTree = insert(boysNameTree, x++, "William");
	boysNameTree = insert(boysNameTree, x++, "Ethan");
	boysNameTree = insert(boysNameTree, x++, "James");
	boysNameTree = insert(boysNameTree, x++, "Alexander");
	boysNameTree = insert(boysNameTree, x++, "Michael");
	boysNameTree = insert(boysNameTree, x++, "Benjamin");
    inorder(boysNameTree);
	x = 1;
	node *girlsNameTree = newNode(x++, "Emma");
	girlsNameTree->right = newNode(x++, "Olivia");
	girlsNameTree = insert(girlsNameTree, x++, "Sophia");
	girlsNameTree = insert(girlsNameTree, x++, "Ava");
	girlsNameTree = insert(girlsNameTree, x++, "Isabella");
	girlsNameTree = insert(girlsNameTree, x++, "Mia");
	girlsNameTree = insert(girlsNameTree, x++, "Abigail");
	girlsNameTree = insert(girlsNameTree, x++, "Emily");
	girlsNameTree = insert(girlsNameTree, x++, "Charlotte");
	girlsNameTree = insert(girlsNameTree, x++, "Harper");
	inorder(girlsNameTree);

	node *result;
	cout << "Searching for name John" << endl;
	cout << "John " << (((result = search(boysNameTree, "John")) != NULL) ? "found " : "not found ") << ((result != NULL) ? result->position : 0) << endl;
	cout << "Searching for name Ethan" << endl;
	cout << "Ethan " << (((result = search(boysNameTree, "Ethan")) != NULL) ? "found " : "not found ") << ((result != NULL) ? result->position : 0) << endl;
	cout << "Searching for name Tanner" << endl;
	cout << "Tanner " << (((result = search(boysNameTree, "Tanner")) != NULL) ? "found " : "not found ") << ((result != NULL) ? result->position : 0) << endl;
	cout << "Searching Girls List for name Emily" << endl;
	cout << "Emily " << (((result = search(girlsNameTree, "Emily")) != NULL) ? "found " : "not found ") << ((result != NULL) ? result->position : 0) << endl;

    delete boysNameTree;
	delete girlsNameTree;
    return 0;
}

