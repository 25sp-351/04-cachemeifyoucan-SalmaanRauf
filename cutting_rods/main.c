#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cache.h"

#define MAX_PIECES 1000

// function to read leng/val pairs from a file
int read_length_value_pairs(const char *filename, int lengths[], int values[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }
    int count = 0;
    while (fscanf(file, "%d, %d", &lengths[count], &values[count]) == 2) {
        count++;
    }
    fclose(file);
    return count;
}

// structure to track solution
typedef struct {
    int used[MAX_PIECES];
    int max_val;
} Solution;

// function to calc max val using caching
Solution max_value_with_cuts(int rod_length, int lengths[], int values[], int count) {
    Solution solution = {0};
    
    if (rod_length == 0) {
        return solution;
    }
    
    int cached_val;
    if (cache_get(rod_length, &cached_val)) {
        solution.max_val = cached_val;
        // can't cache cutting pattern, just value
        // so we need to recalculate the cuts
        
        int remaining = rod_length;
        while (remaining > 0) {
            int best_piece = -1;
            int best_val = 0;
            
            for (int i = 0; i < count; i++) {
                if (remaining >= lengths[i]) {
                    int next_remaining = remaining - lengths[i];
                    int next_val;
                    
                    if (next_remaining == 0) {
                        next_val = 0;
                    } else if (cache_get(next_remaining, &next_val)) {
                        // use cached value
                    } else {
                        // shouldn't happen if cached properly
                        Solution temp = max_value_with_cuts(next_remaining, lengths, values, count);
                        next_val = temp.max_val;
                    }
                    
                    int total_val = values[i] + next_val;
                    if (total_val > best_val) {
                        best_val = total_val;
                        best_piece = i;
                    }
                }
            }
            
            if (best_piece == -1) {
                // no more cuts possible
                break;
            }
            
            solution.used[best_piece]++;
            remaining -= lengths[best_piece];
        }
        
        return solution;
    }
    
    int best_piece = -1;
    for (int i = 0; i < count; i++) {
        if (rod_length >= lengths[i]) {
            Solution temp = max_value_with_cuts(rod_length - lengths[i], lengths, values, count);
            int val = values[i] + temp.max_val;
            
            if (val > solution.max_val) {
                solution.max_val = val;
                best_piece = i;
                
                // copy used array from temp
                memcpy(solution.used, temp.used, sizeof(int) * MAX_PIECES);
            }
        }
    }
    
    if (best_piece != -1) {
        solution.used[best_piece]++;
    }
    
    cache_put(rod_length, solution.max_val);
    return solution;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <length_value_file>\n", argv[0]);
        return 1;
    }
    
    int lengths[MAX_PIECES], values[MAX_PIECES];
    int count = read_length_value_pairs(argv[1], lengths, values);
    if (count < 0) {
        return 1;
    }

    cache_init();

    int rod_length;
    while (scanf("%d", &rod_length) == 1) {
        Solution solution = max_value_with_cuts(rod_length, lengths, values, count);
        
        printf("Cutting list:\n");
        for (int i = 0; i < count; i++) {
            if (solution.used[i] > 0) {
                printf("%d @ %d = %d\n", solution.used[i], lengths[i], solution.used[i] * values[i]);
            }
        }
        
        // calculate remainder
        int remainder = rod_length;
        for (int i = 0; i < count; i++) {
            remainder -= solution.used[i] * lengths[i];
        }
        printf("Remainder: %d\n", remainder);
        printf("Value: %d\n", solution.max_val);
    }

    cache_free();
    return 0;
}