/**
 * @file matrix_io.h
 * @brief declarations relate to matrix I/O.
 */
#ifndef _MATRIX_INCLUDE_MATRIX_DETAILS_MATRIX_IO_H_
#define _MATRIX_INCLUDE_MATRIX_DETAILS_MATRIX_IO_H_

#include "matrix.h"
#include <memory>

namespace matrix {

/**
 * @brief Write a number of matrix into binary file in order.
 * @param [in] Mat: a vector matrices to be written.
 * @param [in] fname: the binary file name (relative/absolute path).
 */
void write_matrices_to_binary(vector<std::shared_ptr<const Matrix>> &Mat,
                              const char *fname);

/**
 * @brief Read a number of matrix into binary file in order.
 * @param [in] Mat: a vector matrices to be written.
 * @param [in] fname: the binary file name (relative/absolute path).
 */
void read_matrices_from_binary(vector<std::shared_ptr<Matrix>> &Mat,
                               const char *fname);

/**
 * @brief Read matrix/matrices from binary file and create a vector of matrices.
 * @param [in] fname: binary file name.
 * @return std::vector<std::shared_ptr<Matrix>>: a vector of matrices.
 */
std::vector<std::shared_ptr<Matrix>>
read_matrices_from_binary(const char *fname);

/**
 * @brief Read matrix/matrices from binary file and create a vector of matrices.
 * @param [in] fname: binary file name.
 * @return std::vector<std::shared_ptr<Matrix>>: a vector of matrices.
 */
std::vector<std::shared_ptr<Matrix>> read_matrices_from_binary(string &fname);

/**
 * @brief Write a vector of matrices into a txt file.
 * @details The matrices are write in order. For each matrix, the format is the
 * following. The first line constaints the number of row and columns of the
 * matrix. This line is garranted to be the format
 * `printf("Dimension,%zu,%zu\n", row, col) and it is used to indicate the
 * separation of different matrices. The following multiples lines contains all
 * the matrix elements. Each matrix elements are comma-separated. The matrix
 * elements are written in column-wise order.
 *
 * @param [in] Mat: The set of input matrices to be written.
 * @param [in] fname: The name of the output txt file.
 * @param [in] num_per_line: number of matrix elements per line.
 */
void write_matrices_to_txt(vector<std::shared_ptr<Matrix>> &Mat,
                           const string &fname, size_t num_per_line = 5);

/**
 * @brief Read a vector of matrices from a txt file generated from
 * matrix::write_matrices_to_txt().
 *
 * @param [in] fname: the name (relative or absolute path) of the matrix txt
 * file.
 * @return std::vector<std::shared_ptr<Matrix>>: a vector of matrices.
 * @see matrix::write_matrices_to_txt()
 */
std::vector<std::shared_ptr<Matrix>> read_matrices_from_txt(const string &fname);

} // namespace matrix

#endif // _MATRIX_SRC_MATRIX_IO_H_
