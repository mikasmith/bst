#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "bst.h"


struct bst_node{
    char *key;
    bst left;
    bst right; 
};

bst bst_new(){
    return NULL;
}

bst bst_insert(bst b, char *str){
    if(b->key==NULL){
        b->key = emalloc(sizeof *b);
        b->key = str;
    }else if(str < b->key){
        b->left = bst_insert(b->left, str);
    }else if(str > b->key){
        b->right = bst_insert(b->right, str);
    }

    return b;
    
}

int bst_search(bst b, char *key){
    if(b->key==NULL){
        return 0;
    }else if(key==b->key){
        return 1;
    }else if(b->key < key){
        return bst_search(b->left, key);
    }else{
        return bst_search(b->right, key);
    }
}


void bst_inorder(bst b, void f(char *s)){
    if(b!=NULL){
        bst_inorder(b->left, f);
        f(b->key);
        bst_inorder(b->right, f);
    }

}

void bst_preorder(bst b, void f(char *s)){
    if(b!=NULL){
        f(b->key);
        bst_preorder(b->left, f);
        bst_preorder(b->right, f);
    }

}
