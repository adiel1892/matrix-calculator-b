#include "Matrix.hpp"
using namespace zich;
//constructor
Matrix::Matrix( vector<double> nums, int rows , int cols){
    if(rows < 1 || cols < 1){
        __throw_invalid_argument("rows and cols must be positive");
    }
    if(nums.size() != (int)(rows * cols)){
        __throw_invalid_argument("invalid matrix");
    }
    this->cols = cols;
    this->rows = rows;
    vector<double> currRow;
    unsigned int count = 0;
    size_t i = 0;
    while(count < (rows * cols)){
        currRow.push_back(nums.at(i));
        count++;
        i++;
        if(currRow.size() == cols){
            this->mat.push_back(currRow);
            currRow.resize(0);
        }
    }
}

//destructor
Matrix::~Matrix(){
    
}

bool Matrix::same_size(Matrix const& other)const{
    return (other.cols == this->cols && this->rows == other.rows);
}


//plus
Matrix Matrix::operator+(Matrix const& other){
    if(!same_size(other)){
        __throw_invalid_argument("Different matrix size!");
    }
    vector<double> vec;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            vec.push_back((this->mat.at(i).at(j) + other.mat.at(i).at(j)));
        }
    }
    Matrix res(vec ,this->rows ,this->cols);
    return res;
}
Matrix& Matrix::operator+=(Matrix const& other){
    if(!same_size(other)){
        __throw_invalid_argument("Different matrix size!");
    }
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->mat.at(i).at(j) = (this->mat.at(i).at(j) + other.mat.at(i).at(j));
        }
    }
    return *this;
}
Matrix Matrix::operator+(){
    vector<double>vec;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            vec.push_back(this->mat.at(i).at(j));
        }
    }
    Matrix res(vec,this->rows ,this->cols);
    return res;
}

Matrix& Matrix::operator++(){
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->mat.at(i).at(j)++;
        }
    }
    return *this;
}
Matrix Matrix::operator++(int){
    vector<double>vec;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            vec.push_back(this->mat.at(i).at(j));
            this->mat.at(i).at(j)++;
        }
    }
    Matrix res(vec,this->rows ,this->cols);
    return res;
}

//subtract
Matrix Matrix::operator-(Matrix const& other){
    if(!same_size(other)){
        __throw_invalid_argument("Different matrix size!");
    }
    vector<double> vec;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            vec.push_back((this->mat.at(i).at(j) - other.mat.at(i).at(j)));
        }
    }
    Matrix res(vec ,this->rows ,this->cols);
    return res;
}
Matrix& Matrix::operator-=(Matrix const& other){
    if(!same_size(other)){
        __throw_invalid_argument("Different matrix size!");
    }
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->mat.at(i).at(j) = (this->mat.at(i).at(j) - other.mat.at(i).at(j));
        }
    }
    return *this;

}
Matrix Matrix::operator-(){
    vector<double>vec;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            if(this->mat.at(i).at(j) != 0){
                vec.push_back(this->mat.at(i).at(j) * -1);
            }else{
                vec.push_back(this->mat.at(i).at(j));
            }
        }
    }
    Matrix res(vec,this->rows ,this->cols);
    return res;
}

Matrix& Matrix::operator--(){
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->mat.at(i).at(j)--;
        }
    }
    return *this;
}

Matrix Matrix::operator--(int){
    vector<double>vec;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            vec.push_back(this->mat.at(i).at(j));
            this->mat.at(i).at(j)--;
        }
    }
    Matrix res(vec,this->rows ,this->cols);
    return res;
}
//multiplication
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
    Matrix res(vec ,this->rows ,other.cols);
    return res;
}

Matrix& Matrix::operator*=(const double &num){
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->mat.at(i).at(j) = (this->mat.at(i).at(j) * num);
        }       
    }
    return *this;
}

Matrix zich::operator*(double const &num,Matrix const& other){
    vector<double> vec;
    for(size_t i = 0; i < other.rows; i++){
        for(size_t j = 0; j < other.cols; j++){
            vec.push_back(other.getMatrix().at(i).at(j) * num);
        }
    }
    Matrix res(vec,other.rows ,other.cols);
    return res;
}

//boolean
bool Matrix::operator>(Matrix const& other){
    if(!same_size(other)){
        __throw_invalid_argument("Different matrix size!");
    }
    double sum_a = 0;
    double sum_b = 0;
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
    return sum_a > sum_b;
}
bool Matrix::operator>=(Matrix const& other){
    if(!same_size(other)){
        __throw_invalid_argument("Different matrix size!");
    }
    double sum_a = 0;
    double sum_b = 0;
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
    return sum_a >= sum_b;
}
bool Matrix::operator<(Matrix const& other){
    if(!same_size(other)){
        __throw_invalid_argument("Different matrix size!");
    }
    double sum_a = 0;
    double sum_b = 0;
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
    return sum_a < sum_b;
}
bool Matrix::operator<=(Matrix const& other){
    if(!same_size(other)){
        __throw_invalid_argument("Different matrix size!");
    }
    double sum_a = 0;
    double sum_b = 0;
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
    return sum_a <= sum_b;
}
bool Matrix::operator==(Matrix const& other){
    if(!same_size(other)){
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
    if(!same_size(other)){
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

//cout
ostream& zich::operator<<(ostream& out, Matrix const& a){
    for(size_t i = 0; i < a.getRows(); i++){
        out << "[";
        for(size_t j = 0; j < a.getCols(); j++){
            if(j != a.getCols() - 1){
                out << a.getMatrix().at(i).at(j) << " ";
            }else{
                out << a.getMatrix().at(i).at(j) << "]";
            }
        }
        out << "\n";
    }
    return out;
}
// istream& zich::operator<<(istream& in, Matrix const& a){
//     return in;   
// }

