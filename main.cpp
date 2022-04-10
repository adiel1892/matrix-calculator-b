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

Matrix randomMatrix(int rows, int cols){
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
    // Matrix trying33;
    // cin >> trying33;
    // cout << trying33;

    cout << "Welcome to our Matrix world!\n";
    cout << "Enter rows and columns to see what is it a matrix.\n";
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

    Matrix one = randomMatrix(rows, cols);
    Matrix two = randomMatrix(rows, cols);
    cout << "congratulations!! You made your first matrix!\n";
    cout << one;
    cout <<".\n.\n.\n.\n";

    cout << "Let's do cool stuff\n";
    // cout << "We have our first matrix, let's create another one with the same size.\n";
    string i_want = "y";



    bool bools = one > two;
    while(i_want != "n"){

        cout << "Do you want to continue?? yes - any key , no - n\n";
        cin >> i_want;
        if(i_want == "n"){
            cout << "GOODBYE\n";
            break;
         }

        cout << "You can add, sub ,mul 2 matrix with the same size.\n";
        cout << "To add matrix one with two insert 1\n";
        cout << "To sub matrix one with two insert 2\n";
        cout << "To mul matrix one with two insert 3\n";
        cout << "To add 1 to all elements in matrix one insert 4\n";
        cout << "To sub 1 from all elements in matrix one insert 5\n";
        cout << "To check if one > two insert 6\n";
        cout << "To check if one >= two insert 7\n";
        cout << "To check if one < two insert 8\n";
        cout << "To check if one <= two insert 9\n";
        cout << "To check if one == two insert 10\n";
        cout << "To check if one != two insert 11\n";

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
                try{
                    cout << endl << one << endl <<"*" << "\n\n" << two << endl <<"=" << "\n\n" << one * two << endl;
                }catch(exception e){
                    cout << "Can't mul 2 matrix when the cols of the first matrix is not equal to the rows of the second..\n";
                    break;
                }
                
                break;
            case 4:
                cout << "You chose to add 1 to all elements in matrix one!\n";
                cout << endl << one << endl <<"++" << endl <<"=" << "\n\n" << ++one << endl;
                break;
            case 5:
                cout << "You chose to sub 1 from all elements in matrix one!\n";
                cout << endl << one << endl <<"--" << endl <<"=" << "\n\n" << --one << endl;
                break;
            case 6:
                cout << "You chose to check if one > two!\n";
                cout << "One is > two if the sum of the all matrix elements is bigger than the sum of two.\n";
                cout << endl << one << endl <<"<" << "\n\n" << two << endl <<"=" << "\n\n" << bools << endl;
                break;
            case 7:
                cout << "You chose to check if one >= two!\n";
                cout << "One is >= two if the sum of the all matrix elements is equal bigger than the sum of two.\n";
                bools = one >= two;
                cout << endl << one << endl <<">=" << "\n\n" << two << endl <<"=" << "\n\n" << bools << endl;
                break;
            case 8:
                cout << "You chose to check if one < two!\n";
                cout << "One is < two if the sum of the all matrix elements is less than the sum of two.\n";
                bools = one < two;
                cout << endl << one << endl <<"<" << "\n\n" << two << endl <<"=" << "\n\n" << bools << endl;
                break;
            case 9:
                cout << "You chose to check if one <= two!\n";
                cout << "One is <= two if the sum of the all matrix elements is equal less than the sum of two.\n";
                bools = one <= two;
                cout << endl << one << endl <<"<=" << "\n\n" << two << endl <<"=" << "\n\n" << bools << endl;
                break;
            case 10:
                cout << "You chose to check if one == two!\n";
                cout << "One is == two if all the elements are equal and in the same place.\n";
                bools = one == two;
                cout << endl << one << endl <<"==" << "\n\n" << two << endl <<"=" << "\n\n" << bools << endl;
                break;
            case 11:
                cout << "You chose to check if one != two!\n";
                cout << "One is != two if there is at least one element that is not the same.\n";
                bools = one != two;
                cout << endl << one << endl <<"!=" << "\n\n" << two << endl <<"=" << "\n\n" << bools << endl;
                break; 
            default:
                cout << "Please insert invalid case.";
                break;
        }
    }



}