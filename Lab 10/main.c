/* SYSC 2006 Winter 2018 Lab 10 - Unfinished Test Harness. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "recursive_functions.h"
#include "sput.h"


/* Display the values returned by C's pow() function and our
 * recursive power() function. If power() is correct, the two values
 * should be the same, or differ at most by a small amount.
 */

static void test_power_sput(void) {
    //3.5 ^ 0, 3.5 ^ 1, 3.5 ^ 2, 3.5 ^ 3 and 3.5 ^ 4.
    double x = 3.5;
    double error = 1*pow(10,-15);
    char str[] = "power(3.5, k)";
    for (int k = 0; k <= 4; ++k) {
        str[11]='0' + k;
        sput_fail_unless(power(x,k)>=pow(x,k)-error&&power(x,k)<=pow(x,k)+error, str);
        printf("Expected result: %0.2f, actual result: %0.2f\n", pow(x, k), power(x, k));
    }

}


/* Exercise our recursive num_digits() function. 
 * Display the result we expect num_digits() to return, followed by
 * the actual value calculated by the function.
 *
 * Parameter k is the argument that will be passed to num_digits().
 * Parameter expected is the result that a correct implementation of 
 * num_digits() will return.
 */

static void test_num_digits_sput(void) {

    /* Test case: num_digits(5) should return 1. */
    sput_fail_unless(num_digits(5) == 1, "num_digits(n)");
    printf("Expected result: %d, actual result: %d\n", 1, num_digits(5));

    /* Test case: num_digits(9) should return 1. */
    sput_fail_unless(num_digits(9) == 1, "num_digits(n)");
    printf("Expected result: %d, actual result: %d\n", 1, num_digits(9));

    /* Test case: num_digits(10) should return 2. */
    sput_fail_unless(num_digits(10) == 2, "num_digits(n)");
    printf("Expected result: %d, actual result: %d\n", 2, num_digits(10));

    /* Test case: num_digits(99) should return 2. */
    sput_fail_unless(num_digits(99) == 2, "num_digits(n)");
    printf("Expected result: %d, actual result: %d\n", 2, num_digits(99));

    /* Test case: num_digits(100) should return 3. */
    sput_fail_unless(num_digits(100) == 3, "num_digits(n)");
    printf("Expected result: %d, actual result: %d\n", 3, num_digits(100));

    /* Test case: num_digits(999) should return 3. */
    sput_fail_unless(num_digits(999) == 3, "num_digits(n)");
    printf("Expected result: %d, actual result: %d\n", 3, num_digits(99));

    /* Test case: num_digits(1000) should return 4. */
    sput_fail_unless(num_digits(1000) == 4, "num_digits(n)");
    printf("Expected result: %d, actual result: %d\n", 4, num_digits(1000));
}

/*
 * Print then integers in array a in the form: [a[0] a[1] .. a[n-1]].
 */
void print_array(int a[], int n) {
    if (n <= 0)
        return;

    printf("{%d", a[0]);
    for (int i = 1; i < n; i += 1) {
        printf(" %d", a[i]);
    }
    printf("}");
}

/* Exercise our recursive occurrences function. 
 * Display the result we expect occurrences() to return, followed by
 * the actual value calculated by the function.
 *
 * Parameter a is the array that will be passed to occurrences().
 * Parameter n is the number of elements in the array.
 * Parameter target is the value that occurrences() will search for.
 * Parameter expected is the result that a correct implementation of 
 * occurrences() will return.
 */

static void test_occurrences_sput(void) {
    int a[] = {1, 2, 4, 4, 4, 5, 6, 7, 8, 9, 12};
    int n = sizeof(a) / sizeof(n);


/* Test case: occurrences(x, n, 1) should return 1. */
    sput_fail_unless(occurrences(a, n, 1) == 1, "occurrences(a, n, target)");
    printf("Expected result: %d, actual result: %d\n", 1, occurrences(a, n, 1));

/* Test case: occurrences(x, n, 2) should return 1. */
    sput_fail_unless(occurrences(a, n, 2) == 1, "occurrences(a, n, target)");
    printf("Expected result: %d, actual result: %d\n", 1, occurrences(a, n, 2));

/* Test case: occurrences(x, n, 4) should return 3. */
    sput_fail_unless(occurrences(a, n, 4) == 3, "occurrences(a, n, target)");
    printf("Expected result: %d, actual result: %d\n", 3, occurrences(a, n, 4));

/* Test case: occurrences(x, n, 12) should return 1. */
    sput_fail_unless(occurrences(a, n, 12) == 1, "occurrences(a, n, target)");
    printf("Expected result: %d, actual result: %d\n", 1, occurrences(a, n, 12));

/* Test case: occurrences(x, n, 3) should return 0. */
    sput_fail_unless(occurrences(a, n, 3) == 0, "occurrences(a, n, target)");
    printf("Expected result: %d, actual result: %d\n", 0, occurrences(a, n, 3));
}

/* Challenge exercise:
 * Display the values returned by C's pow() function and our
 * recursive power2() function. If power2() is correct, the two values
 * should be the same, or differ at most by a small amount.
 */

static void test_power2_sput(void) {
    //3.5 ^ 0, 3.5 ^ 1, 3.5 ^ 2, 3.5 ^ 3 and 3.5 ^ 4.
    double x = 3.5;
    double error = 1*pow(10,-15);//17.125
    char str[] = "power(3.5, k)";
    for (int k = 0; k <= 4; ++k) {
        str[11]='0' + k;
        sput_fail_unless(power2(x,k)>=pow(x,k)-error&&power2(x,k)<=pow(x,k)+error, str);
        printf("Expected result: %0.2f, actual result: %0.2f\n", pow(x, k), power2(x, k));
    }
}

int main(void) {
    /*printf("SYSC 2006 Winter 2018 Lab 10 Test Harness\n\n");

    test_exercise_1();
    test_exercise_2();
    test_exercise_3();
    test_exercise_4();*/

    printf("Running test harness for SYSC 2006 Winter 2018 Lab 10\n");

    sput_start_testing();

    sput_enter_suite("Exercise 1: power()");
    sput_run_test(test_power_sput);

    sput_enter_suite("Exercise 2: num_digits()");
    sput_run_test(test_num_digits_sput);
    sput_leave_suite();

    sput_enter_suite("Exercise 3: occurrences()");
    sput_run_test(test_occurrences_sput);
    sput_leave_suite();

    sput_enter_suite("Exercise 4: power2()");
    sput_run_test(test_power2_sput);
    sput_leave_suite();

    sput_finish_testing();
    return sput_get_return_value();
}