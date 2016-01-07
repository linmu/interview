#include <stdio.h>
#include <stdlib.h>

void find_path(int step,int count,int n,char *path) {
        if(step == n) {
            int i;
            for(i = 0;i < count;i++) {
                if(path[i] != '0') {
                    printf("%c ",path[i]);
               } else {
                    break;
                }
            }
            printf("\n");
            return;
        }

        if(step < n) {
            *(path + count) = '1';
            find_path(step + 1,count + 1,n,path);
        }
        
        if(n - step >= 2) {
            *(path + count) = '2';
            find_path(step + 2,count + 1,n,path);
        }
}

int main(int argc,char **argv) {
    int length = atoi(argv[1]);
    char path[1000] = {'0'};
    find_path(0,0,length,path);
    return 0;
}
