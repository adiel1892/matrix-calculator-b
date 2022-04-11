#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;
namespace zich{

    class Matrix{
        private:
            vector<vector<double>> mat;
            int rows;
            int cols;

        public:
        //constructor
        Matrix(const vector<double> &nums, const int rows ,const int cols);
        //default constructor
        Matrix();

        //destructor
        ~Matrix();

        //getters
        vector<vector<double>> getMatrix() const{return this->mat;}
        int getRows() const{return this->rows;}
        int getCols() const{return this->cols;}

        //plus
        Matrix operator+(Matrix const& other);
        Matrix& operator+=(Matrix const& other);
        Matrix operator+();
        Matrix& operator++(); //++Matrix
        Matrix operator++(int); //Matrix++



        //subtract
        Matrix operator-(Matrix const& other);
        Matrix& operator-=(Matrix const& other);
        Matrix operator-();
        Matrix& operator--();
        Matrix operator--(int);

        //multiplication
        Matrix operator*(Matrix const& other);
        Matrix operator*(double const& num);
        Matrix& operator*=(double const& num);
        Matrix& operator*=(Matrix const& other);
        friend Matrix operator*(double const &num,Matrix const& other);

        //boolean
        bool operator<(Matrix const& other)const;
        bool operator<=(Matrix const& other)const;
        bool operator>(Matrix const& other)const;
        bool operator>=(Matrix const& other)const;
        bool operator==(Matrix const& other)const;
        bool operator!=(Matrix const& other)const;

        friend ostream& operator<<(ostream& out,Matrix const &a);
        friend istream& operator>>(istream& in,Matrix &a);

        bool same_size(Matrix const& other)const;
        bool getNum(const string& str,int *stringToInt);
        Matrix randomMatrix(int rows, int cols);
    };
};