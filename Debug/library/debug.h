/**
 * @file debug.h
 * @details
 * @version 0.1
 * @date 2011-11-30
 * @author Emerson Rocha Luiz
 * @copyright
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 */

#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Return current excecution time of program
 * @see benchmarkStack()
 * @see benchmarkEnd()
 *
 * @return clock_t
 */
clock_t benchmarkStart(void) {
    return clock();
}

/**
 * @param stack Array of stack
 * @param label
 * @return 
 */
clock_t benchmarkStack(int *stack, char label[]) {
    //...
}

/**
 * Print time diferente, in second, since benchmarkStart was called
 * @example
 *          clock_t start;
 *          start = tdbProfileStart();
 *          //Your code...
 *          tdbProfileEnd(start);
 *
 * @todo Make it return the value, instead of print the falue. Still witout
 *       precision when try to return it.
 *
 * @param stack Array of stack
 * @param label
 * @return 
 */
clock_t benchmarkEnd(int *stack, char label[]) {
    clock_t end, total_time;
    end = clock() - start;
    printf("%.6f\n", (double) ((end + 0.0) / CLOCKS_PER_SEC)); //Print
    total_time = (double) ((end + 0.0) / CLOCKS_PER_SEC);
    return total_time;
}

/**
 * 
 * @param stack
 * @return void
 */
void benchmarkReset(int *stack) {
    stack = NULL;
}

//int logInitialize(*)


#endif // DEBUG_H_INCLUDED
