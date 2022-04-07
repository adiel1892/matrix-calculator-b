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
        Matrix(vector<double>, const int,const int);

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
        friend Matrix operator*(double const &num,Matrix const& other);

        //boolean
        bool operator<(Matrix const& other);
        bool operator<=(Matrix const& other);
        bool operator>(Matrix const& other);
        bool operator>=(Matrix const& other);
        bool operator==(Matrix const& other);
        bool operator!=(Matrix const& other);

        friend ostream& operator<<(ostream& out,Matrix const &a);
        // friend istream& operator>>(ostream& in,Matrix const &a);

        bool same_size(Matrix const& other)const;
    };
}