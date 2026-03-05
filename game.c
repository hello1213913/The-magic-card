#include<stdio.h>
#include<string.h>
void exc(int [], int[], int[]);

void print_func(int [], int[], int[]);
int main(){
    int col_1[] = {1,2,3,4,5,6,7}, col_2[] = {8,9,10,11,12,13,14}, col_3[] = {15,16,17,18,19,20,21}, which, how_many_times=1;

    while(how_many_times != 4){
        
        print_func(col_1, col_2, col_3);
        printf("\nWhich is the column of your choosen number : ");
        scanf("%d", &which);


        switch(which){
            case 1 : exc(col_2, col_1, col_3); 
                    break;
            case 2 : exc(col_1, col_2, col_3);
                    break;
            case 3 : exc(col_1, col_3, col_2);
                    break;   
        }
        how_many_times ++;


    }
    //Because the switch swaps arrays, the final card will ALWAYS be 
    // in the middle of whichever column was chosen LAST. 
    if (which == 1) {
        printf("\nYour desired and thought number is : %d\n", col_1[3]);
    } else if (which == 2) {
        printf("\nYour desired and thought number is : %d\n", col_2[3]);
    } else if (which == 3) {
        printf("\nYour desired and thought number is : %d\n", col_3[3]);
    }


    printf("\nThank YOu\nHope the answer is right.\nIf it is not right you might have inputed wrong column no.\nBy labi..");
   
    return 0;

    
}

void print_func(int c1[], int c2[], int c3[]){
    int i;
    printf("\nC:1\tC:2\tC:3\n");
    for(i=0; i<7; i++){
        printf("%d\t%d\t%d", c1[i], c2[i], c3[i]);
        printf("\n");
    }
} 
void exc(int c1[], int c2[], int c3[]){
    int k1[21], i;
    int index = 0;

    // STEP 1: GATHERING (Stacking the columns)
    // We simply copy the columns one after another into the big deck.
    // Note: main() passes the chosen column as c2, so it ends up in the middle.
    
    // Copy first column (top pile)
    for(i=0; i<7; i++){
        k1[index++] = c1[i];
    }
    // Copy second column (chosen pile - middle)
    for(i=0; i<7; i++){
        k1[index++] = c2[i];
    }
    // Copy third column (bottom pile)
    for(i=0; i<7; i++){
        k1[index++] = c3[i];
    }

    // STEP 2: DEALING (Redistributing row by row)
    // We deal card 0 to col1, card 1 to col2, card 2 to col3, card 3 to col1...
    for(i=0; i<7; i++){
        c1[i] = k1[i * 3];     // positions 0, 3, 6...
        c2[i] = k1[(i * 3) + 1]; // positions 1, 4, 7...
        c3[i] = k1[(i * 3) + 2]; // positions 2, 5, 8...
    }
}
