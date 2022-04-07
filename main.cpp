#include "Matrix.cpp"
#include  <cmath>
using namespace zich;

// checking if input of user is valid.
// if valid - string to int.
bool getNum(const string& str,int *stringToInt)
{
    *stringToInt = 0;
    int len = str.length();
    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i] -'0';
        if (i == 0){
            if (val == 0){
                return false;
            }
        }
        if (val < 0 || val > 9){
            return false;
        }
        else{
            *stringToInt += val * pow(10, len - 1);
            len--;

        }
    }
    return true;
}

Matrix randomMatrix(){
    int rows , cols;
    string check_rows , check_cols;
    cout << "Lets start with the rows..\n";
    cin >> check_rows;
    while(!getNum(check_rows , &rows)){
        cout << "Invalid rows :( Please make sure you insert a valid number\n";
        cin >> check_rows;
    }
    cout << "Continue with the cols..\n";
    cin >> check_cols;
    while(!getNum(check_cols , &cols)){
        cout << "Invalid cols :( Please make sure you insert a valid number\n";
        cin >> check_cols;
    }
    int count = 0;
    vector<double> vec;
    while(count < (rows * cols)){
        int insert = 1 + (rand() % 9);
        vec.push_back(insert);
        count++;
    }
    Matrix a(vec , rows, cols);
    return a;
}

int main(){
    cout << "Welcome to our Matrix world!\n";
    cout << "Enter rows and columns to see what is it a matrix.\n";
    Matrix one = randomMatrix();
    cout << "congratulations!! You made your first matrix!\n";
    cout << one;
    cout <<".\n.\n.\n.\n";

    cout << "Let's do cool stuff\n";
    cout << "We have our first matrix, let's create another one with the same size.\n";

    Matrix two = randomMatrix();

    cout << "You can add, sub ,mul 2 matrix.\n";

    cout << "To add matrix one with two insert 1\n";
    cout << "To sub matrix one with two insert 2\n";
    cout << "To mul matrix one with two insert 3\n";
    string user_choice_s;
    int user_choice;
    cin >> user_choice_s;
    getNum(user_choice_s , &user_choice);
    switch(user_choice){
        case 1:
            cout << "You chose to add 2 matrix!\n";
            cout << endl << one << endl <<"+" << "\n\n" << two << endl <<"=" << "\n\n" << one + two << endl;
            break;
        case 2:
            cout << "You chose to sub 2 matrix!\n";
            cout << endl << one << endl <<"-" << "\n\n" << two << endl <<"=" << "\n\n" << one - two << endl;
            break;
        case 3:
            cout << "You chose to mul 2 matrix!\n";
            cout << endl << one << endl <<"*" << "\n\n" << two << endl <<"=" << "\n\n" << one * two << endl;
            break;
    }


}