#ifndef SUPERKK_MAT3_H
#define SUPERKK_MAT3_H

#include <array>
#include <cmath>

typedef std::array<std::array<double, 3>, 3> mat3;

class Mat3 {
private:
    mat3 mat;

    mat3 matmul(const mat3& other) {
        mat3 result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result[i][j] = 0;
                for (int k = 0; k < 3; ++k) {
                    result[i][j] += mat[i][k] * other[k][j];
                }
            }
        }
        return result;
    }

public:
    Mat3() : mat() {
        set_identity();
    };

    double get(int i, int j) const {
        return mat[i][j];
    }

    void set_identity() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                mat[i][j] = i == j ? 1 : 0;
            }
        }
    }

    void translate(double tx, double ty) {
        mat[0][2] += tx;
        mat[1][2] += ty;
    }

    void scale(double sx, double sy) {
        mat[0][0] *= sx;
        mat[1][1] *= sy;
    }

    void rotate(double angle) {
//        TODO: 性能优化
        double c = cos(angle);
        double s = sin(angle);
        mat3 rot_mat {
            c, -s, 0,
            s,  c, 0,
            0,  0, 1,
        };
        mat = matmul(rot_mat);
    }
};


#endif //SUPERKK_MAT3_H
