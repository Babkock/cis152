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
        inorder(root->left);
        cout << root->level << " = " << lev << " " << root->description << endl;
        inorder(root->right);
    }
}

int main(void) {
    cout << "hello world" << endl;
    return 0;
}
