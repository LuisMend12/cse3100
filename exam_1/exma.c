// #include <stdio.h>

// int main() {
    
//     int *p = malloc(sizeof(int));
//     if (p == NULL) {
//         perror("Memory allocation error.\n");
//         return -1 ;
//     }

//     if ((unsigned long)&p > (unsigned long)p ) printf("Hello");
//     free(p);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>


// int main() {
//     int *p;
//     printf("%p\n", p);
//     printf("%d\n", *p);
//     return 0;
// }


// #include <stdio.h>

// int main() {
//     int a[] = {1};

//     int *p = a;

//     *p++;
    
//     printf("%d\n", a[0]);


//     return 0;
// }



// #include <stdio.h>

// int main() {
//     int a[] = {1};

//     int *p = a;

//     int r = (unsigned long) p  == (unsigned long) &p;

    
//     printf("%d\n", a[0]);


//     return 0;
// }




// #include <stdio.h>

// int main() {
//     int a[] = {1, 2, 3};

//     char *p = a;

//     printf("%d\n", p[0] + p[1] + p[2]);


//     return 0;
// }




// #include <stdio.h>

// int main() {
//     int t[10];

//     char *p = (char *) t + 8;
//     char *q = (char *) (t + 8);
//     printf("%ld\n", q- p);


//     return 0;
// }





// #include <stdio.h>

// int main() {
    
//     int a[10], *p = a, i;

//     for (i=0; i<10; i++) *++p = i;

//     for (i=0; i<10; i++) 
//         printf("%d ", a[i]);

//     printf("\n");
    
    

//     return 0;
// }



#include <stdio.h>




void reverse(int a[], int n) {
    int i;
    for (i = 0; i<n; i++){
        int temp;
        temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
}


int main(){
    int a[3] = {0, 23, 12};
    int p = 3;



    reverse(a, p);

    printf("%d\n", a[1]);
    
    printf("%d\n", p);
}


