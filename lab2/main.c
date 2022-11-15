#include "mylifeissad.h"
int main(int argc, char** argv) {
    srand(time(NULL));

    //if the number of params provided ain't cool
    if(argc != 4) {
	printf("Invalid amount of arguments\n");
	return EXIT_FAILURE;
    }
    int  min = atoi(argv[1]), max = atoi(argv[2]), required = atoi(argv[3]);

    //bound checking
    if(required > max - min + 1) {
	printf("You required more numbers than the range itself! Tsk tsk!\n");
	return EXIT_FAILURE;
    }
    //invalid input
    if (max < min) {
	printf("Max value is smaller than min, illegal mah friend\n");
        return EXIT_FAILURE;
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

    // int a = 0;
    // for (int i = 0; i < required; ++i){
    //     for (int j = i + 1; j < required; ++j){
    //         if (arr[i] > arr[j]){
    //             a = arr[i];
    //             arr[i] = arr[j];
    //             arr[j] = a;
    //         }
    //     }
    // }

    for (int i = 0; i < required; ++i) {
        printf("%d) %d\n", i+1, arr[i]);
    }
}
