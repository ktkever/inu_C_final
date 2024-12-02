#include <stdio.h>
#include <string.h>

int main() {
    char words[6][20] = {
        "avocado",
        "apple",
        "tomato",
        "pineapple",
        "pear",
        "banana"
    };

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(strcmp(words[j], words[j+1]) > 0 ){
                char tmp[20];
                strcpy(tmp,words[j]);
                strcpy(words[j],words[j+1]);
                strcpy(words[j+1],tmp); 
            }
        }
    }
    for(int k = 0; k < 6; k++)
        printf("%s\n",words[k]);
}