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
            unsigned int rows;
            unsigned int cols;

        public:
        //constructor
        Matrix(vector<double>, const int,const int);

        //destructor
        ~Matrix();

        //getters
        vector<vector<double>> getMatrix() const{return this->mat;}
        unsigned int getRows() const{return this->rows;}
        unsigned int getCols() const{return this->cols;}

        //plus
        Matrix operator+(Matrix const& other);
        void operator+=(Matrix const& other);
        Matrix operator+();
        Matrix& operator++();



        //subtract
        Matrix operator-(Matrix const& other);
        void operator-=(Matrix const& other);
        Matrix operator-();
        Matrix& operator--();

        //multiplication
        Matrix operator*(Matrix const& other);
        Matrix operator*(double const& num);
        void operator*=(double const& num);
        friend Matrix operator*(double const &num,Matrix other);

        //boolean
        bool operator<(Matrix const& other);
        bool operator<=(Matrix const& other);
        bool operator>(Matrix const& other);
        bool operator>=(Matrix const& other);
        bool operator==(Matrix const& other);
        bool operator!=(Matrix const& other);




        
        friend ostream& operator<<(ostream& out,Matrix const &a);
        // friend istream& operator>>(ostream& in,Matrix const a);
    };
}