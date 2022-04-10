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
        //default constructor
        // Matrix(){
        //     vector<double> nums = {1,0,0,0,1,0,0,0,1};
        //     this->cols = 3;
        //     this->rows = 3;
        //     vector<double> currRow;
        //     unsigned int count = 0;
        //     size_t i = 0;
        //     while(count < (9)){
        //         currRow.push_back(nums.at(i));
        //         count++;
        //         i++;
        //         if(currRow.size() == 3){
        //             this->mat.push_back(currRow);
        //             currRow.resize(0);
        //         }
        //     }
        // }

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