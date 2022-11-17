#include "mylifeissad.h"
int main(int argc, char** argv) {
    srand(time(NULL));

    int min = 0, max = 0, required = 0;
    //if the number of params provided ain't cool
    if(argc != 4) {
	
	printf("Invalid amount of arguments\nInput a min, a max and how many numbers you want separated by a space:\n");
	scanf("%d %d %d", &min, &max, &required);
    } else { min = atoi(argv[1]); max = atoi(argv[2]); required = atoi(argv[3]);}


    //invalid input
    if (max < min) {
	printf("Required: %d\n", required);
	printf("Max is smaller than min? Cmon man!\nGet me a legit max-min pair\n");
	printf("Min number:\n");
	scanf("%d", &min);
	printf("Max number:\n");
	scanf("%d", &max);
    }
    
    //bound checking
    if (required > max - min + 1) {
	printf("You required more numbers than the range itself! Tsk tsk!\nThe maximum you can get is %d numbers. How many do you want?\n", max - min + 1);
	scanf("%d", &required);
    }

    int arr[required];

    //flags array to mark which number had been used
    int used[max - min + 1];

    //mark all as false
    for(int i = 0; i <= max - min; ++i) used[i] = 0;

    for (int i = 0; i < required; ++i) {
        int generated = getRand(min, max);
        
        //while the number is used, generate a new one
        while(used[generated - min]) {    
            generated = getRand(min, max);
        } 

        arr[i] = generated;

        //mark the number as used
        used[generated - min] = 1;
    }

    // UNCOMMENT TO SORT ARRAY BEFORE PRINTING

    int a = 0;
    for (int i = 0; i < required; ++i){
        for (int j = i + 1; j < required; ++j){
            if (arr[i] > arr[j]){
                a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }

    for (int i = 0; i < required; ++i) {
        printf("%d) %d\n", i+1, arr[i]);
    }
}
