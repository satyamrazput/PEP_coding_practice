void f1 (void);
void f2 (void);
void main (void);
void f3 (void);
#pragma startup f1 100
#pragma startup f3 105
#pragma exit f2


void main (){
    printf ("I am Main....\n");
}
void f1 (void){
    printf ("I am f1....\n");
}
void f2 (void){
    printf ("I am f2....\n");
}
void f3 (void){
    printf ("I am f3....\n");
}
