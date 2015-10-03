#ifndef MATRIX
#define MATRIX

#include <vector>

template <typename Object>
class Matrix {
private:
    vector<vector<Object> > mat;
    int row, col;
public:
    Matrix(const int &r, const int &c): row(r), col(c) {
        mat = vector<vector<Object> >(row, vector<Object>(col, 0));
    }
    Matrix(const Matrix<Object> &m) {
        row = m.size()[0];
        col = m.size()[1];
        mat = vector<vector<Object> >(row, vector<Object>(col, 0));
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                mat[r][c] = m[r][c];
            }
        }
    }

    vector<int> size() const {
        return vector<int>{row, col};
    }

    void resize(const int &r, const int &c) {
        mat = vector<vector<Object> >(r, vector<Object>(c, 0));
    }

    Matrix<Object> &operator = (const Matrix<Object> &m) {
        row = m.size()[0];
        col = m.size()[1];
        resize(row, col);
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                mat[r][c] = m[r][c];
            }
        }
        return *this;
    }
    Matrix<Object> operator * (const Matrix<Object> &m) {
        vector<int> size = m.size();
        Matrix<Object> ret(row, size[1]);
        for (int r1 = 0; r1 < row; ++r1) {
            for (int c2 = 0; c2 < size[1]; ++c2) {
                Object ele = 0;
                for (int i = 0; i < col; ++i) {
                    ele += mat[r1][i] * m[i][c2];
                }
                ret[r1][c2] = ele;
            }
        }
        return ret;
    }
    Matrix<Object> operator + (const Matrix<Object> &m) {
        Matrix<Object> ret(row, col);
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                ret[r][c] = mat[r][c] + m[r][c];
            }
        }
        return ret;
    }
    Matrix<Object> operator - (const Matrix<Object> &m) {
        Matrix<Object> ret(row, col);
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                ret[r][c] = mat[r][c] - m[r][c];
            }
        }
        return ret;
    }

    vector<Object> &operator [] (const int row) {
        return mat[row];
    }
    
    const vector<Object> &operator [] (const int row) const {
        return mat[row];
    }
};

template <typename Object>
ostream &operator << (ostream &o, const Matrix<Object> &mat) {
    o << "[" << endl;
    vector<int> size = mat.size();
    for (int r = 0; r < size[0]; ++r) {
        o << "  ";
        for (int c = 0; c < size[1]; ++ c) {
            o << mat[r][c] << " ";
        }
        cout << endl;
    }
    o << "]";
    return o;
}

template <typename Object>
void crtMat(Matrix<Object> &mat, const int &r, const int &c) {
    cout << "Input the matrix's elements:" << endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> mat[i][j];
        }
    }
}

template<typename Object>
Matrix<Object> matPow(const Matrix<Object> &mat, int n) {
    int row = mat.size()[0];
    Matrix<Object> ret(row, row);
    for (int i = 0; i < row; ++i) {
        ret[i][i] = 1;
    }
    Matrix<Object> tmp(mat);
    for (; n; n >>= 1) {
        if (n & 1) {
            ret = ret * tmp;
        }
        tmp = tmp * tmp;
    }
    return ret;
}

#endif
