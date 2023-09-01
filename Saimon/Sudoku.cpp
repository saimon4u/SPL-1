#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define loop(i,n) for (int i = 0; i < n; i++)
using namespace std;
bool isValid(vector<vector<int>> &sudoku,int row,int col,int val){
    /*
    This function checks three place whether there was a value equals to the value we want to add,
    1. in the current row
    2. in the current column
    3. in the 3*3 matrix
    */
    for(int i=0; i<sudoku.size(); i++){
        if(sudoku[row][i]==val || sudoku[i][col]==val)return false;
        if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3]==val)return false;
    }
    return true;
}
bool sudokuSolver(vector<vector<int>> &sudoku){
    int n = sudoku[0].size();
    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            // checking for the empty spot to try adding values to
            if(sudoku[row][col] == 0){
                for(int val = 1; val<=9; val++){
                    // tries to add different values 
                    if(isValid(sudoku, row, col, val)){
                        sudoku[row][col] = val;
                        // after adding a value it passes the board forward and wait for the next value to add
                        if(sudokuSolver(sudoku)){
                            return true;
                        }
                        sudoku[row][col] = 0;
                    }
                }
                // if we can't fine a suitable value then the sudoku can't be solved
                return false;
            }
        }
    }
    return true;
}
int main(){
    vector <vector <int> > sudoku(9,vector<int> (9,0));
    // taking input the sudoku board
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku[i][j];
        }
    }
    // calling for the solution and showing results
    if(sudokuSolver(sudoku)){
        cout<< "Solved one: " << endl;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}