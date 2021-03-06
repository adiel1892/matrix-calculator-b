#include "Matrix.hpp"
using namespace zich;

//constructor
Matrix::Matrix( const vector<double> &nums,int rows ,int cols){
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
Matrix  Matrix::operator*(double const& num){
    vector<double> vec;
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            vec.push_back(this->mat.at(i).at(j) * num);
        }
    }
    Matrix res(vec,this->rows ,this->cols);
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
Matrix& Matrix::operator*=(Matrix const& other){
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
    *this = res;
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

double Matrix::sumMatrix(Matrix const& other){
    double sum = 0;
    for(size_t i = 0; i < other.rows; i++){
        for(size_t j = 0; j < other.cols; j++){
            sum += other.mat.at(i).at(j);
        }
    }
    return sum;
}
bool Matrix::operator>(Matrix const& other)const{
    if(!same_size(other)){
        __throw_invalid_argument("Different matrix size!");
    }
    double sum_a = sumMatrix(*this);
    double sum_b = sumMatrix(other);
    return sum_a > sum_b;
}
bool Matrix::operator>=(Matrix const& other)const{
    if(!same_size(other)){
        __throw_invalid_argument("Different matrix size!");
    }
    double sum_a = sumMatrix(*this);
    double sum_b = sumMatrix(other);
    return sum_a >= sum_b;
}
bool Matrix::operator<(Matrix const& other)const{
    if(!same_size(other)){
        __throw_invalid_argument("Different matrix size!");
    }
    double sum_a = sumMatrix(*this);
    double sum_b = sumMatrix(other);
    return sum_a < sum_b;
}
bool Matrix::operator<=(Matrix const& other)const{
    if(!same_size(other)){
        __throw_invalid_argument("Different matrix size!");
    }
    double sum_a = sumMatrix(*this);
    double sum_b = sumMatrix(other);
    return sum_a <= sum_b;
}
bool Matrix::operator==(Matrix const& other)const{
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
bool Matrix::operator!=(Matrix const& other)const{
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
        if(i != a.rows - 1){
            out << "\n";
        }
        
    }
    return out;
}

// got help from a friend
istream& zich::operator>>(istream& in , Matrix & a){
    vector<double> vec;
    int row = 0;
    int rowLength = 0;
    int counter = 0;
    double number = 0;
    bool b = false;
    bool first = false;
    string tempNum;
    unsigned char temp = (unsigned char) in.get();
    while (temp != '\n') {
        if(!b && temp != '['){
            throw invalid_argument("wrong input for matrix");
        }
        if(temp == '['){
            temp = (unsigned char) in.get();
            if(temp < '0' || temp > '9'){
                throw invalid_argument("wrong input for matrix");
            }
        }
        if(temp == ' '){
            number = stod(tempNum);
            vec.push_back(number);
            tempNum = "";
            counter++;
        }
        if(temp == ']') {
            number = stod(tempNum);
            vec.push_back(number);
            tempNum = "";
            row++;
            counter++;
            if (first && rowLength != counter) {
                throw invalid_argument("wrong input for matrix");
            }
            if (!first) {
                rowLength = counter;
                first = true;
            }
            counter = 0;
            temp = (unsigned char) in.get();
            if (temp == '\n') {
                break;
            }
            temp = (unsigned char) in.get();
        }
        b = true;
        tempNum += (char) temp;
        temp = (unsigned char) in.get();
    }
    Matrix res(vec , row , rowLength);
    a = res;
    return in;
}

