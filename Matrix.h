#ifndef MATRIX
#define MATRIX

#include <vector>

class Matrix {
private:
    vector<vector<int> > mat;
    int row, col;
public:
    Matrix(const int &r, const int &c): row(r), col(c) {
        mat = vector<vector<int> >(row, vector<int>(col, 0));
    }
    Matrix(const Matrix &m) {
        this->row = m.size()[0];
        this->col = m.size()[1];
        mat = vector<vector<int> >(row, vector<int>(col, 0));
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                setEle(r, c, m.getEle(r, c));
            }
        }
    }
    int getEle(const int &r, const int &c) const {
        return mat[r][c];
    }
    void setEle(const int &r, const int &c, const int &val) {
        mat[r][c] = val;
    }
    vector<int> size() const {
        return vector<int>{row, col};
    }
    void resize(const int &r, const int &c) {
        mat = vector<vector<int> >(r, vector<int>(c, 0));
    }
    Matrix &operator = (const Matrix &m) {
        this->row = m.size()[0];
        this->col = m.size()[1];
        resize(row, col);
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                setEle(r, c, m.getEle(r, c));
            }
        }
        // !
        return *this;
    }
    Matrix operator * (const Matrix &mat) {
        vector<int> size = mat.size();
        Matrix ret(this->row, size[1]);
        for (int r1 = 0; r1 < this->row; ++r1) {
            for (int c2 = 0; c2 < size[1]; ++c2) {
                int ele = 0;
                for (int i = 0; i < this->col; ++i) {
                    ele += getEle(r1, i) * mat.getEle(i, c2);
                }
                ret.setEle(r1, c2, ele);
            }
        }
        return ret;
    }
    Matrix operator + (const Matrix &mat) {
        Matrix ret(this->row, this->col);
        for (int r = 0; r < this->row; ++r) {
            for (int c = 0; c < this->col; ++c) {
                ret.setEle(r, c, getEle(r, c) + mat.getEle(r, c));
            }
        }
        return ret;
    }
    Matrix operator - (const Matrix &mat) {
        Matrix ret(this->row, this->col);
        for (int r = 0; r < this->row; ++r) {
            for (int c = 0; c < this->col; ++c) {
                ret.setEle(r, c, getEle(r, c) - mat.getEle(r, c));
            }
        }
        return ret;
    }
};

ostream &operator << (ostream &o, const Matrix &mat) {
    o << "[" << endl;
    vector<int> size = mat.size();
    for (int r = 0; r < size[0]; ++r) {
        o << "  ";
        for (int c = 0; c < size[1]; ++ c) {
            o << mat.getEle(r, c) << " ";
        }
        cout << endl;
    }
    o << "]";
    return o;
}

void crtMat(Matrix &mat, const int &r, const int &c) {
    cout << "Input the matrix's elements:" << endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int tmp;
            cin >> tmp;
            mat.setEle(i, j, tmp);
        }
    }
}

Matrix matPow(const Matrix &mat, int n) {
    int row = mat.size()[0];
    Matrix ret(row, row);
    for (int i = 0; i < row; ++i) {
        ret.setEle(i, i, 1);
    }
    Matrix tmp(mat);
    for (; n; n >>= 1) {
        if (n & 1) {
            ret = ret * tmp;
        }
        tmp = tmp * tmp;
    }
    return ret;
}

#endif
