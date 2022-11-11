/*****************************************
 * Name: Binary Search Decision Tree
 * Author: Tanner Babcock
 * Created: October 27, 2022
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

typedef struct decision_t {
    string description;
    int level;
    struct decision_t *left;
    struct decision_t *right;
} decision;

decision *newDecision(string des, int lev) {
    return new (decision){ .description = des, .level = lev, .left = NULL, .right = NULL};
}

decision *newLeftDecision(decision *root, string des, int lev) {
    return new (decision){ .description = des, .level = lev, .left = root, .right = NULL};
}

decision *newRightDecision(decision *root, string des, int lev) {
    return new (decision){ .description = des, .level = lev, .left = NULL, .right = root};
}

decision *searchRight(decision *root, string des) {
    if (!root || root->description == des)
        return root;

    return searchRight(root->right, des);
}

decision *searchLeft(decision *root, string des) {
    if (!root || root->description == des)
        return root;

    return searchLeft(root->left, des);
}

decision *insert(decision *root, string des, int lev = 1) {
    if (!root)
        return newDecision(des, lev);

    if (lev < root->level)
        root->left = insert(root->left, des, lev-1);
    else if (lev > root->level)
        root->right = insert(root->right, des, lev+1);
    return root;
}

void inorder(decision *root, int lev = 1) {
    if (root != NULL) {
        inorder(root->left, lev+1);
        cout << root->level << " = " << lev << " " << root->description << endl;
        inorder(root->right, lev+1);
    }
}

int main(void) {
    int x = 1;
    decision *tree1 = newDecision("Do the first thing", x++);
    tree1->right = newDecision("Do the second thing", x++);
    tree1->left = newDecision("Do another thing", x);
    tree1 = insert(tree1, "Do the third thing", x++);
    tree1 = insert(tree1, "Do a different third thing", x);
    cout << "Printing first tree" << endl;
    inorder(tree1, 1);
    x = 1;
    decision *tree2 = newDecision("Are you hungry?", x++);
    tree2->right = newDecision("Yes: Do you have money?", x++);
    tree2->left = newDecision("No: Do you want to see your friends?", x);
    tree2->right->right = newDecision("Yes: Go out to eat!", x++);
    tree2->right->left = newDecision("No: Eat at home! If you're not a second class citizen", x);
    tree2->left->right = newDecision("Yes: Are your friends busy?", x);
    tree2->left->left = newDecision("No: Hang out by yourself", x);
    cout << "Printing second tree" << endl;
    inorder(tree2, 1);

    delete tree1;
    delete tree2;
    return 0;
}
