#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void group(const char *str,const char *fmt,char **target) {
    char *tmp = *target;
    int str_len = strlen(str);
    int fmt_len = strlen(fmt);
    
    int i,j;
    int diff = 0;
    for(i = 0;i < fmt_len;i++) {
        for(j = 0;j < str_len;j++) {
            if((fmt[i] - 'A' >=0) && (fmt[i] - 'A' < 26) && (str[j] - 'A' >= 0) && (str[j] - 'A' < 26)) {
                *tmp++ = str[j];
            }
            else if((fmt[i] - 'a' >= 0) && (fmt[i] - 'a' < 26) && (str[j] - 'a' >= 0) && (str[j] - 'a' < 26)) {
                *tmp++ = str[j];
            }
            else if((fmt[i] - '0' >= 0) && (fmt[i] - '0' <= 9) && (str[j] - '0' >= 0) && (str[j] - '0' < 9)) {
                *tmp++ = str[j];
            } 
            else if((fmt[i] < '0' || (fmt[i] > '9' && fmt[i] < 'A') || (fmt[i] > 'Z' && fmt[i] < 'a') || fmt[i] > 'z') && (str[j] < '0' || (str[j] > '9' && str[j] < 'A') || (str[j] > 'Z' && str[j] < 'a') || str[j] > 'z')) {
                *tmp++ = str[j]; 
            }
        }
    }
    *tmp = '\0';
    return;
}

int main(int argc,char **argv) {
    
    char *dest = (char*)malloc(sizeof(char) * 1000);

    group(argv[1],argv[2],&dest);
    printf("%s\n",dest);
    return 0;
}

