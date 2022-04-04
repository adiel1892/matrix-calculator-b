#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;


TEST_CASE("initiallize Matrix"){
    vector<double> vec = {1,2,3,4,5,6,7,8,9};
    Matrix a(vec, 3, 3);
    CHECK(a.getMatrix().at(0).at(0) == 1);
    CHECK(a.getMatrix().at(0).at(1) == 2);
    CHECK(a.getMatrix().at(0).at(2) == 3);
    CHECK(a.getMatrix().at(1).at(0) == 4);
    CHECK(a.getMatrix().at(1).at(1) == 5);
    CHECK(a.getMatrix().at(1).at(2) == 6);
    CHECK(a.getMatrix().at(2).at(0) == 7);
    CHECK(a.getMatrix().at(2).at(1) == 8);
    CHECK(a.getMatrix().at(2).at(2) == 9);
    CHECK(a.getCols() == 3);
    CHECK(a.getRows() == 3);


}

TEST_CASE("+ - *"){
    vector<double> vec1 = {1,2,3,4,5,6,7,8,9};
    Matrix a(vec1, 3, 3);
    Matrix b(vec1, 3, 3);
    Matrix c = a + b;
    // ------- checking + -------
    CHECK(c.getMatrix().at(0).at(0) == 2);
    CHECK(c.getMatrix().at(0).at(1) == 4);
    CHECK(c.getMatrix().at(0).at(2) == 6);
    CHECK(c.getMatrix().at(1).at(0) == 8);
    CHECK(c.getMatrix().at(1).at(1) == 10);
    CHECK(c.getMatrix().at(1).at(2) == 12);
    CHECK(c.getMatrix().at(2).at(0) == 14);
    CHECK(c.getMatrix().at(2).at(1) == 16);
    CHECK(c.getMatrix().at(2).at(2) == 18);
    CHECK(a.getMatrix().at(0).at(0) == 1);
    CHECK(a.getMatrix().at(0).at(1) == 2);
    CHECK(a.getMatrix().at(0).at(2) == 3);
    CHECK(a.getMatrix().at(1).at(0) == 4);
    CHECK(a.getMatrix().at(1).at(1) == 5);
    CHECK(a.getMatrix().at(1).at(2) == 6);
    CHECK(a.getMatrix().at(2).at(0) == 7);
    CHECK(a.getMatrix().at(2).at(1) == 8);
    CHECK(a.getMatrix().at(2).at(2) == 9);
        // ------- checking - -------
    Matrix d = a - b;
    CHECK(d.getMatrix().at(0).at(0) == 0);
    CHECK(d.getMatrix().at(0).at(1) == 0);
    CHECK(d.getMatrix().at(0).at(2) == 0);
    CHECK(d.getMatrix().at(1).at(0) == 0);
    CHECK(d.getMatrix().at(1).at(1) == 0);
    CHECK(d.getMatrix().at(1).at(2) == 0);
    CHECK(d.getMatrix().at(2).at(0) == 0);
    CHECK(d.getMatrix().at(2).at(1) == 0);
    CHECK(d.getMatrix().at(2).at(2) == 0);
    vector<double> vec2 = {1,2,3,4};
    Matrix e(vec2 , 2 , 2);
    CHECK_THROWS(a + e);
    CHECK_THROWS(a - e);
        // ------- checking += -------
    a += b;
    CHECK(a.getMatrix().at(0).at(0) == 2);
    CHECK(a.getMatrix().at(0).at(1) == 4);
    CHECK(a.getMatrix().at(0).at(2) == 6);
    CHECK(a.getMatrix().at(1).at(0) == 8);
    CHECK(a.getMatrix().at(1).at(1) == 10);
    CHECK(a.getMatrix().at(1).at(2) == 12);
    CHECK(a.getMatrix().at(2).at(0) == 14);
    CHECK(a.getMatrix().at(2).at(1) == 16);
    CHECK(a.getMatrix().at(2).at(2) == 18);
        // ------- checking -= -------
    a -= b;
    CHECK(a.getMatrix().at(0).at(0) == 1);
    CHECK(a.getMatrix().at(0).at(1) == 2);
    CHECK(a.getMatrix().at(0).at(2) == 3);
    CHECK(a.getMatrix().at(1).at(0) == 4);
    CHECK(a.getMatrix().at(1).at(1) == 5);
    CHECK(a.getMatrix().at(1).at(2) == 6);
    CHECK(a.getMatrix().at(2).at(0) == 7);
    CHECK(a.getMatrix().at(2).at(1) == 8);
    CHECK(a.getMatrix().at(2).at(2) == 9);
    CHECK_THROWS(a += e);
    CHECK_THROWS(a +- e);
        // ------- checking * -------
    Matrix f = a * b;
    CHECK(f.getMatrix().at(0).at(0) == 30);
    CHECK(f.getMatrix().at(0).at(1) == 36);
    CHECK(f.getMatrix().at(0).at(2) == 42);
    CHECK(f.getMatrix().at(1).at(0) == 66);
    CHECK(f.getMatrix().at(1).at(1) == 81);
    CHECK(f.getMatrix().at(1).at(2) == 96);
    CHECK(f.getMatrix().at(2).at(0) == 102);
    CHECK(f.getMatrix().at(2).at(1) == 126);
    CHECK(f.getMatrix().at(2).at(2) == 150);
    vector<double> vec3 = {1,2,3,4,5,6};
    Matrix g(vec3 , 2 , 3);
    Matrix h = e * g;
    cout << "check1";
    CHECK(h.getRows() == e.getRows());
    CHECK(h.getCols() == g.getCols());
    CHECK(h.getMatrix().at(0).at(0) == 9);
    CHECK(h.getMatrix().at(0).at(1) == 12);
    CHECK(h.getMatrix().at(0).at(2) == 15);
    CHECK(h.getMatrix().at(1).at(0) == 19);
    CHECK(h.getMatrix().at(1).at(1) == 26);
    CHECK(h.getMatrix().at(1).at(2) == 33);

            // ------- checking * num -------
    a *= 3;
    CHECK(a.getMatrix().at(0).at(0) == 3);
    CHECK(a.getMatrix().at(0).at(1) == 6);
    CHECK(a.getMatrix().at(0).at(2) == 9);
    CHECK(a.getMatrix().at(1).at(0) == 12);
    CHECK(a.getMatrix().at(1).at(1) == 15);
    CHECK(a.getMatrix().at(1).at(2) == 18);
    CHECK(a.getMatrix().at(2).at(0) == 21);
    CHECK(a.getMatrix().at(2).at(1) == 24);
    CHECK(a.getMatrix().at(2).at(2) == 27);

}


TEST_CASE("bool"){
    vector<double> vec1 = {1,2,3,4,5,6,7,8,9};
    vector<double> vec2 = {1,2,3,4,5,6,7,8,8};
    Matrix a(vec1, 3, 3);
    Matrix b(vec2, 3, 3);
    Matrix c(vec1, 3, 3);
    bool bigger1 = a > b;
    bool not_bigger = b > a;
    bool ans1 = true;
    bool ans2 = false;
    CHECK(bigger1 == ans1);
    CHECK(not_bigger == ans2);
    // bool equal = a == c;
    bool equal_bigger = a >= c;
    bool not_equal_bigger = b >= a;
    // CHECK(equal == ans1);
    CHECK(equal_bigger == ans1);
    CHECK(not_equal_bigger == ans2);
    bool less_equal = c <= a;
    bool less = b < a;
    CHECK(less_equal == ans1);
    CHECK(less == ans1);


}