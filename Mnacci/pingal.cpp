
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
std::vector<long long int> mnacci(long long int m, long long int reps) {
	// mnacci sequence vector
	std::vector<long long int> seq;
	seq.resize(m*reps);

	// initial elements
	for (long long int i = 0; i < m-1; i++)
		seq.push_back(0);
	seq.push_back(1);

	// 2nd m elements
	for (long long int i = 0; i < m; i++)
		seq.push_back(std::pow(2, i));

	// 2m+1 and onwards
	while (seq.size() < m*reps) {
		std::partial_sum(seq.end() - m, seq.end(), seq.end() - m, std::plus<>{});
	}

	return seq;
}


std::vector<std::vector<long long int>> chebyshev1st(long long int n, long long int reps) {
	std::vector<std::vector<long long int>> seq(n, std::vector<long long int>(n*reps, 0));
	seq[0][0] = 1;
	seq[1][0] = 1;
	// fill in the chebyshev coefficients using the recurrence definition
	for (long long int i = 2; i < n; i++) {
		for (long long int j = 0; j < n*reps; j++) {
			seq[i][j] = 2 * seq[i-1][j] - seq[i-2][j];
		}
	}
	return seq;
}


std::vector<long long int> testtheory(long long int n, long long int reps) {
	// initiate 2d vector for chebyshev coefficients
	std::vector<std::vector<long long int>> seq(n, std::vector<long long int>(n*reps, 0));
	seq = chebyshev1st(n, reps);
	// row-wise adjustment on the chebyshev coefficients triangle
	std::vector<std::vector<long long int>> coefs(n, std::vector<long long int>(n*reps, 0));

	// compute mnacci using chebyshev coefficients
	std::vector<long long int> out(n*reps);

	// first column
	seq[0][n] = 1;
	for(long long int i = 0; i < n; i++)
		seq[0][n+i] = std::pow(2, i);
	
	for(long long int i = 1; i < n; i++) {
		for(long long int j = i*n; j < n*reps; i++) {

		}
	}
	
	// add all elements
	for(long long int i = 0; i < n*reps; i++) {
		for(long long int j = 0; j < n; j++) {
			out[i] += std::pow(-1, j+1)*seq[j][i];
		}
	}

	return out;
}