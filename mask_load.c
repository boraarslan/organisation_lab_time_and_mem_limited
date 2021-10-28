#include <immintrin.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main()
{
	struct timeval t_before, t_after, t_diff;

	gettimeofday(&t_before, NULL);

	int i;

	int int_array[8] = {100, 200, 300, 400, 500, 600, 700, 800};

	/* Initialize the mask vector */
	__m256i mask = _mm256_setr_epi32(-20, -72, -48, -9, -100, 3, 5, 8);

	/* Selectively load data into the vector */
	__m256i result = _mm256_maskload_epi32(int_array, mask);

	/* Display the elements of the result vector */
	int *res = (int *)&result;
	printf("%d %d %d %d %d %d %d %d\n",
		   res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);


	gettimeofday(&t_after, NULL);
	timersub(&t_after, &t_before, &t_diff);
	printf("%ld.%06ld s\n",(long int)t_diff.tv_sec, (long int)t_diff.tv_usec);

	return 0;
}