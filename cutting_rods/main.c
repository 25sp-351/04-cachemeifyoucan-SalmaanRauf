//sorry for overzealous commenting, this is just how i code when learning new langauge. will reduce as we go on.

//FOCUS: KISS, readable code, should flow well and easy to understand without too many comments.

#include <stdio.h>
#include <stdlib.h>

// 2. read input lengths/vals, stores in arrays

int read_input(int lengths[], int values[]) {
    int count = 0;
    printf("Enter lengths and values, following this format: '<length>, <value>'");
    //The two %d are to expect integers, sep by commas. EOF = end of user input
    while (scanf("%d, %d", &lengths[count], &values[count]) != EOF) {
        count ++;
    }
    return count;
}

//3 recursively calc max value that you can get from cutting rod
int max_value(int rod_length, int lengths[], int values[], int count, int used[]) {
    // base case
    if (rod_length == 0) {
        return 0; 
    }
    int max_val = 0;
    int best_piece = -1;

    // This is our for loop from beginning to end, we use i++ like in c++ for iter
    for (int i = 0; i < count; i++) {
        // checking if our current piece can fit in rod
        if (rod_length >= lengths[i]) {
            // temp array to store usage for this branch
            int temp_used[100] = {0}; 
            for (int j = 0; j < count; j++) {
                temp_used[j] = used[j]; // copy the current state of "used"
            }

            // recursively try cutting rod with this piece, cal val
            int val = values[i] + max_value(rod_length - lengths[i], lengths, values, count, temp_used);

            // IF the value is better, update max_val and the piece
            if (val > max_val) {
                max_val = val;
                best_piece = i; // save which piece gave the best result

                // copy the temp array back to the main "used" array
                for (int j = 0; j < count; j++) {
                    used[j] = temp_used[j];
                }
            }
        }
    }

    // if we found a best piece, increment its usage
    if (best_piece != -1) {
        used[best_piece]++;
    }

    return max_val; // return the best value for this rod length
}


// 1 putting it all together
int main(int argc, char *argv[]) {
    // first check if user gave us the args we want as ip
    if (argc != 2) {
        printf("Please follow formatting instructions mentioned above.");
        return 1; // exit code
    }

    // converting the rod length str to int using atoi
    int rod_length = atoi(argv[1]);

    // arrays to stores lengs and vals. arrays require set size, just to be safe i put 1000.
    // complexity wise they should be smaller but complexity is not the focus here
    int lengths[1000], values[1000];
    int used[1000] = {0}; // NEW CODE: Array to track how many pieces of each length are used

    // now we use the functions we made earlier
    int count = read_input(lengths, values);

    // getting the total value of the rod by calling max val function
    int total_val = max_value(rod_length, lengths, values, count, used);

    printf("Cutting list:\n");
    for (int i = 0; i < count; i++) {
        if (used[i] > 0) { 
                //only printing info if we used it
            printf("%d @ %d = %d\n", used[i], lengths[i], used[i] * values[i]);
        }
    }

    //calculate remainder by subtracting used pieces
    int remainder = rod_length;
    for (int i = 0; i < count; i++) {
        remainder -= used[i] * lengths[i];
    }
    printf("Remainder: %d\n", remainder);

    // print the final total value of the rod
    printf("Value: %d\n", total_val);

    return 0; // exiting
}
