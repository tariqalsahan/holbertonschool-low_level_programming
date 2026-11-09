#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void build_dataset(void)
{
    unsigned int state;
    int i;

    state = SEED_VALUE;

    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
    int i;
    int v;

    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
    unsigned long sum;
    int i;

    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];

    return sum;
}

/**
 * to_seconds - converts a clock tick interval to seconds
 * @start: clock value taken before the measured region
 * @end: clock value taken after the measured region
 *
 * Return: elapsed time in seconds
 */
static double to_seconds(clock_t start, clock_t end)
{
    return ((double)(end - start) / (double)CLOCKS_PER_SEC);
}

/**
 * main - times each phase of the program and the whole run
 *
 * Boundaries: each phase is timed around its single function call only.
 * TOTAL starts before build_dataset() and ends after reduce_checksum(),
 * so it covers all three phases (and the small gaps between them).
 * Printing is outside every measured region.
 *
 * Return: 0
 */
int main(void)
{
    unsigned long checksum;
    clock_t total_start, total_end;
    clock_t build_start, build_end;
    clock_t process_start, process_end;
    clock_t reduce_start, reduce_end;

    total_start = clock();

    build_start = clock();
    build_dataset();
    build_end = clock();

    process_start = clock();
    process_dataset();
    process_end = clock();

    reduce_start = clock();
    checksum = reduce_checksum();
    reduce_end = clock();

    total_end = clock();

    if (checksum == 0ul)
        printf("impossible\n");

    printf("TOTAL seconds: %.6f\n", to_seconds(total_start, total_end));
    printf("BUILD_DATA seconds: %.6f\n", to_seconds(build_start, build_end));
    printf("PROCESS seconds: %.6f\n",
           to_seconds(process_start, process_end));
    printf("REDUCE seconds: %.6f\n", to_seconds(reduce_start, reduce_end));

    return (0);
}
