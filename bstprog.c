#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "bst.h"

void print_key(char *s){
    printf("%s\n", s);
}

int main(void) {
    char word[256];
    char op;
    bst b=bst_new();


    while(2==scanf(" %c %255s", &op, word)){
        if('+'==op){
            b = bst_insert(b, word);
        }else if('?'==op){
            printf("%d %s\n", bst_search(b, word), word);
        }
    }

    bst_preorder(b, print_key);
    bst_inorder(b, print_key);


    /*bst_free(b);*/
    


    

    /*
      htable h=NULL;
      char word[256];
      if(argc>0){
      h = htable_new(atoi(argv[1]));
      }else{
      fprintf(stderr,"Please input a capacity.");
      }

      while(getword(word, sizeof word, stdin) != EOF){
      htable_insert(h, word);
      }

        
      htable_print(h, stdout);
      htable_free(h);
    */
    

    
    return EXIT_SUCCESS;
}
