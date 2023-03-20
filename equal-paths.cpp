#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#include <iostream>
#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int findLength(Node* root, int length){
    if(root==NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return length;
    }
    if(root->left != NULL){
        return findLength(root->left, length + 1);

    }
    else if(root->right != NULL){
        return findLength(root->right, length + 1);

    }

}

bool compareLengths(Node* root, int length, int newlength){
    std::cout << "length: "<<length << std::endl;
    if(root == NULL){
        return true;
    }
    if(root->right == NULL && root->left == NULL){
        if(length == newlength){
            return true; 
        }
        else{
            return false;
        }
    }
    bool rbool = compareLengths(root->right, length, newlength + 1);
    bool lbool = compareLengths(root->left, length, newlength + 1);
    return rbool&&lbool;


}

bool equalPaths(Node * root)
{
    // Add your code below
    // if(root == NULL){
    //     return true;
    // }
    // if(root->left == NULL && root->right != NULL){
    //     return false; 
    // }
    // if(root->left != NULL && root->right == NULL){
    //     return false; 
    // }
    // if(root->left == NULL && root->right == NULL){
    //     return true; 
    // }

    // equalPaths(root->right);
    // equalPaths(root->left);

    // return true;

    // bool lbool = false;
    // bool rbool = false; 

   
    // if(root == NULL){
    //     return true;
    // }
    // if(root->left == NULL && root->right != NULL){
    //    return false;
    // }
    // if(root->left != NULL && root->right == NULL){
    //     return false; 
    // }
    // if(root->left == NULL && root->right == NULL){
    //     return true; 
    // }

    // rbool = equalPaths(root->right);
    // lbool = equalPaths(root->left);

    // if(lbool == rbool){
    //     return true;
    // }
    // else {
    //     return false;
    // }

    int length = findLength(root, 0);
    return compareLengths(root, length, 0);

}



