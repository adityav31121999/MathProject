
// file for mnacci functions and chebyshev functions
#include "Mnacci.h"

/**
 * \brief Computes the M-nacci sequence.
 * 		This function computes the M-nacci sequence with the given parameters.
 * 		The sequence is computed as follows:
 * 			1. The first m-1 elements are 0.
 * 			2. The mth element is 1.
 * 			3. The 2nd m elements are 2^i.
 * 			4. The 2m+1th element onwards are the sum of the last m elements.
 * @param m The number of elements in each group of the M-nacci sequence.
 * @param reps The number of groups in the M-nacci sequence.
 * @return The M-nacci sequence of length m*reps
 */
static std::vector<long long int> mnacci(long long int m, long long int reps) {
	// mnacci sequence vector
	std::vector<long long int> seq(m * reps, 0);
	seq[m - 1] = 1;

	// m and onwards
	for (long long int i = m; i < m * reps; i++) {
		for (long long int j = 0; j < m; j++)
			seq[i] += seq[i - j - 1];
	}

	return seq;
}


/**
 * \brief Computes the first kind of Chebyshev polynomials.
 * 		This function computes the first kind of Chebyshev polynomials with the given parameters.
 * 		The sequence is computed as follows:
 * 			1. The first element is 1.
 * 			2. The second element is 1.
 * 			3. From the third element onwards, the element is 2 times the previous element
 * 				minus the element two positions before.
 * @param n The number of elements in each group of the Chebyshev sequence.
 * @param reps The number of groups in the Chebyshev sequence.
 * @return The first kind of Chebyshev sequence of length n*reps
 */
std::vector<std::vector<long long int>> chebyshev1st(long long int n, long long int reps) {
	// chebyshev sequence vector
	std::vector<std::vector<long long int>> seq(n, std::vector<long long int>(n*reps, 0));
	// initial elements
	seq[0][0] = 1;
	seq[1][0] = 1;

	// fill in the chebyshev coefficients using the recurrence definition
	for (long long int i = 2; i < n; i++) {
		for (long long int j = 0; j < n*reps; j++) {
			// the element is 2 times the previous element minus the element two positions before
			seq[i][j] = 2 * seq[i-1][j] - seq[i-2][j];
		}
	}

	return seq;
}


/**
 * \brief Computes the M-nacci sequence using Chebyshev polynomials.
 * 		This function computes the M-nacci sequence of length n*reps using the
 * 		Chebyshev polynomials of the first kind. The sequence is computed as
 * 		follows:
 *   		1. The first m-1 elements are 0.
 *   		2. The mth element is 1.
 *   		3. The 2mth element onwards are the sum of the last m elements.
 *   		4. The sequence is computed using the Chebyshev polynomials of the first kind.
 * @param n The number of elements in each group of the M-nacci sequence.
 * @param reps The number of groups in the M-nacci sequence.
 * @return The M-nacci sequence of length n*reps
 */
std::vector<long long int> testtheory(long long int n, long long int reps) {
	// initiate 2d vector for chebyshev coefficients
	std::vector<std::vector<long long int>> seq(n, std::vector<long long int>(n*reps, 0));
	seq = chebyshev1st(n, reps);
	// row-wise adjustment on the chebyshev coefficients triangle
	std::vector<std::vector<long long int>> coefs(n, std::vector<long long int>(n*reps, 0));

	// compute mnacci using chebyshev coefficients
	std::vector<long long int> out(n*reps);
	
	// row-wise adjustment of coefficient triangle
	for(long long int i = 0; i < n; i++) {
		// loop over the elements of the i-th group
		for(long long int j = i*n; j < n*reps; j++) {
			// the element is the sum of the last m elements
			coefs[i][j] = std::accumulate(seq[i].begin() + j - n, seq[i].begin() + j, 0);
		}
	}

	// add all elements
	for(long long int i = 0; i < n*reps; i++) {
		// loop over the elements of the i-th group
		for(long long int j = 0; j < n; j++) {
			out[i] += std::pow(-1, j+1)*seq[j][i];
		}
	}

	return out;
}
