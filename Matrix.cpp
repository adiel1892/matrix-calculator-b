#include "Matrix.hpp"
using namespace zich;
Matrix::Matrix( vector<double> nums, int rows , int cols){
    if(rows < 1 || cols < 1){
        __throw_invalid_argument("rows and cols must be positive");
    }
    if(nums.size() != (int)(rows * cols)){
        __throw_invalid_argument("invalid matrix");
    }
    unsigned int u_rows = (unsigned int) rows;
    unsigned int u_cols = (unsigned int) cols;
    this->cols = u_cols;
    this->rows = u_rows;
    vector<double> currRow;
    unsigned int count = 0;
    size_t i = 0;
    while(count < (unsigned int)(rows * cols)){
        currRow.push_back(nums.at(i));
        count++;
        i++;
        if(currRow.size() == cols){
            this->mat.push_back(currRow);
            currRow.resize(0);
        }
    }
}

Matrix::~Matrix(){
    
}
Matrix Matrix::operator+(Matrix const& other){
    if(other.cols != this->cols || other.rows != this->rows){
        __throw_invalid_argument("Different matrix size!");
    }
    vector<double> vec;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            vec.push_back((this->mat.at(i).at(j) + other.mat.at(i).at(j)));
            // this->mat.at(i).at(j) = (this->mat.at(i).at(j) + other.mat.at(i).at(j));
        }
    }
    Matrix res(vec , (int)this->rows , (int)this->cols);
    return res;
}
void Matrix::operator+=(Matrix const& other){
    if(other.cols != this->cols || other.rows != this->rows){
        __throw_invalid_argument("Different matrix size!");
    }
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->mat.at(i).at(j) = (this->mat.at(i).at(j) + other.mat.at(i).at(j));
        }
    }
}
Matrix Matrix::operator+(){
    return *this;
}

Matrix Matrix::operator-(Matrix const& other){
    if(other.cols != this->cols || other.rows != this->rows){
        __throw_invalid_argument("Different matrix size!");
    }
    vector<double> vec;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            vec.push_back((this->mat.at(i).at(j) - other.mat.at(i).at(j)));
            // this->mat.at(i).at(j) = (this->mat.at(i).at(j) + other.mat.at(i).at(j));
        }
    }
    Matrix res(vec , (int)this->rows , (int)this->cols);
    return res;
}
void Matrix::operator-=(Matrix const& other){
    if(other.cols != this->cols || other.rows != this->rows){
        __throw_invalid_argument("Different matrix size!");
    }
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->mat.at(i).at(j) = (this->mat.at(i).at(j) - other.mat.at(i).at(j));
        }
    }

}
Matrix Matrix::operator-(){
    // for(size_t i = 0; i < this->rows; i++){
    //     for(size_t j = 0; j < this->cols; j++){
    //         this->mat.at(i).at(j) = (this->mat.at(i).at(j) * -1);
    //     }
    // }
    return *this;
}

Matrix Matrix::operator*(Matrix const& other){
    if(this->cols != other.rows){
        __throw_invalid_argument("can't mult!");
    }
    vector<double> vec;
    double sum = 0;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < other.cols; j++){
            for(size_t k = 0; k < this->cols; k++){
                sum += this->mat.at(i).at(k) * other.mat.at(k).at(j);
                if(k == this->cols - 1){
                    vec.push_back(sum);
                    sum = 0;
                }
            }
        }
    }
    Matrix res(vec , (int)this->rows ,(int)other.cols);
    return res;
}
void Matrix::operator*=(const double &num){
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->mat.at(i).at(j) = (this->mat.at(i).at(j) * num);
        }       
    }
}

bool Matrix::operator>(Matrix const& other){
    if(other.cols != this->cols || other.rows != this->rows){
        __throw_invalid_argument("Different matrix size!");
    }
    int sum_a = 0;
    int sum_b = 0;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            sum_a += this->mat.at(i).at(j);
        }
    }
    for(size_t i = 0; i < other.rows; i++){
        for(size_t j = 0; j < other.cols; j++){
            sum_b += other.mat.at(i).at(j);
        }
    }
    if(sum_a > sum_b){
        return true;
    }
    return false;
}
bool Matrix::operator>=(Matrix const& other){
    if(other.cols != this->cols || other.rows != this->rows){
        __throw_invalid_argument("Different matrix size!");
    }
    int sum_a = 0;
    int sum_b = 0;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            sum_a += this->mat.at(i).at(j);
        }
    }
    for(size_t i = 0; i < other.rows; i++){
        for(size_t j = 0; j < other.cols; j++){
            sum_b += other.mat.at(i).at(j);
        }
    }
    if(sum_a >= sum_b){
        return true;
    }
    return false;
}
bool Matrix::operator<(Matrix const& other){
    if(other.cols != this->cols || other.rows != this->rows){
        __throw_invalid_argument("Different matrix size!");
    }
    int sum_a = 0;
    int sum_b = 0;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            sum_a += this->mat.at(i).at(j);
        }
    }
    for(size_t i = 0; i < other.rows; i++){
        for(size_t j = 0; j < other.cols; j++){
            sum_b += other.mat.at(i).at(j);
        }
    }
    if(sum_a < sum_b){
        return true;
    }
    return false;
}
bool Matrix::operator<=(Matrix const& other){
    if(other.cols != this->cols || other.rows != this->rows){
        __throw_invalid_argument("Different matrix size!");
    }
    int sum_a = 0;
    int sum_b = 0;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            sum_a += this->mat.at(i).at(j);
        }
    }
    for(size_t i = 0; i < other.rows; i++){
        for(size_t j = 0; j < other.cols; j++){
            sum_b += other.mat.at(i).at(j);
        }
    }
    if(sum_a <= sum_b){
        return true;
    }
    return false;
}
bool Matrix::operator==(Matrix const& other){
    if(other.cols != this->cols || other.rows != this->rows){
        __throw_invalid_argument("Different matrix size!");
    }
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            if(this->mat.at(i).at(j) != other.mat.at(i).at(j)){
                return false;
            }
        }
    }
    return true;
}
bool Matrix::operator!=(Matrix const& other){
    if(other.cols != this->cols || other.rows != this->rows){
        __throw_invalid_argument("Different matrix size!");
    }
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            if(this->mat.at(i).at(j) != other.mat.at(i).at(j)){
                return true;
            }
        }
    }
    return false;
}


Matrix& Matrix::operator++(){
    return *this;
}


Matrix& Matrix::operator--(){
    return *this;
}


Matrix zich::operator*(double const &num,Matrix other){
    Matrix a({0,0,0},1,3);
    return a;
}

ostream& zich::operator<<(ostream& out, Matrix const& a){
    // for(size_t i = 0; i < a.getRows(); i++){
    //     out << "[";
    //     for(size_t j = 0; j < a.getCols(); j++){
    //         if(j != a.getCols() - 1){
    //             out << a.getMatrix().at(i).at(j) << " ";
    //         }else{
    //             out << a.getMatrix().at(i).at(j) << "]";
    //         }
    //     }
    //     out << "\n";
    // }
    // out << "bannana";
    return out;

}
// istream& zich::operator<<(istream& in, Matrix const& a){
//     return in;   
// }

