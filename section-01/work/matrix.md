Initial code:

matrix_t matrix_transpose(matrix_t m) {
    matrix_t mt = create_matrix(m.cols, m.rows); //<- assume this has been implemented

    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            mt.data[j * m.rows + i] = m.data[i * m.cols + j];
        }
    }

    return mt;
}


Modifications:
store m.cols and m.rows as local variables
do i*m.cols operation in the larger loop

also assuming in place transpose (mt has same dimensions as m):
traverse only half the array (upper half of the diagonal, not including diagonal for even less traversals)
store a temp variable
and do two swaps in one iteration

can reduce additional time by using compiler modifiers like const and restrict if really wanting to optimize