#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
 
typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
void zhaixiangjiao(){
    printf("Monkey reach the banana\n");
}
void xiaxiangzi(){
    printf("Monkey climb down from the box\n");
}
void work(char c){
    printf("Monkey go to %c\n", c);
}
void pushbox(){
    printf("Monkey push the box to C\n");
}
void climbbox(){
    printf("Monkey climb onto the box\n");
}
int main() {
    int mongkey, box, onbox; // banana is in 0
    // scanf("monkey(-1 or 0 or 1): %d\n box(-1 or 0 or 1): %d\n moonbox(-1 or 1): %d", &mongkey, &box, &onbox);
    scanf("monkey(-1 or 0 or 1): %d", &mongkey);
    getchar();
    scanf("box(-1 or 0 or 1): %d", &box);
    getchar();
    scanf("monbox(-1 or 1): %d", &onbox);
    if(onbox == 1){
        if(mongkey == 0 and box == 0){
            zhaixiangjiao();
            return 0;
        }
        else {
            xiaxiangzi();
        }
    }
    if (mongkey != box){
        char c;
        switch (box){
            case -1:
                c = 'A';
                break;
            case 0:
                c = 'C';
                break;
            case 1:
                c = 'B';
                break;
        }
        work(c);
    }
    if(box != 0){
        pushbox();
    }
    climbbox();
    zhaixiangjiao();
    return 0;
}