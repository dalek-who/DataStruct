#include "OrthMatrix.hpp"
#include <cstring>

using namespace std;

void printUsage() {
    cout << "Usage: " << endl;
    cout << "-a addtion" << endl;
    cout << "-s substruction" << endl;
    cout << "-i inversion" << endl;
    cout << "-m multiplication" << endl;
    cout << "-t transpose" << endl;    
}

int main(int argc, char* argv[]){
    if(argc != 2){
	printUsage();
	return 0;
    }
    else{
	if(strcmp(argv[1], "-a") == 0){
	    cout << "input size of the first matrix(split row and column with whitespace)"<< endl;
	    int row, column;
	    double data;
	    cin >> row >> column;
	    if(row <= 0 || column <= 0){
		cout << "invalid size\n";
		return -1;
	    }
	    
	    OrthMatrix m1(row, column);
	    OrthMatrix answer(row, column);
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    m1.insert(i, j, data);
		}
	    }
	    cout << "Your first matrix is: \n";
	    m1.print();
	    cout << endl;
	    
	    cout << "input size of the second matrix(split row and column with whitespace)"<< endl;
	    cin >> row >> column;
	    OrthMatrix m2(row, column);
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    m2.insert(i, j, data);
		}
	    }
	    cout << "Your second matrix is: \n";
	    m2.print();
	    cout << endl;
	    m1.add(m2, answer);
	    cout << "answer is: \n";
	    answer.print();
	    cout << endl;
	}
	else if(strcmp(argv[1], "-s") == 0){
	    cout << "input size of the first matrix(split row and column with whitespace)"<< endl;
	    int row, column;
	    double data;
	    cin >> row >> column;
	    if(row <= 0 || column <= 0){
		cout << "invalid size\n";
		return -1;
	    }
	    
	    OrthMatrix m3(row, column);
	    OrthMatrix answer(row, column);
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    m3.insert(i, j, data);
		}
	    }
	    cout << "Your first matrix is: \n";
	    m3.print();
	    cout << endl;
	    
	    cout << "input size of the second matrix(split row and column with whitespace)"<< endl;
	    cin >> row >> column;
	    OrthMatrix m4(row, column);
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    m4.insert(i, j, data);
		}
	    }
	    cout << "Your second matrix is: \n";
	    m4.print();
	    cout << endl;
	    m3.sub(m4, answer);
	    cout << "answer is: \n";
	    answer.print();
	    cout << endl;
	}
	else if(strcmp(argv[1], "-m") == 0){
	    cout << "input size of the first matrix(split row and column with whitespace)"<< endl;
	    int row, column;
	    double data;
	    cin >> row >> column;
	    if(row <= 0 || column <= 0){
		cout << "invalid size\n";
		return -1;
	    }
	    
	    OrthMatrix m5(row, column);
	    OrthMatrix answer(row, column);
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    m5.insert(i, j, data);
		}
	    }
	    cout << "Your first matrix is: \n";
	    m5.print();
	    cout << endl;
	    
	    cout << "input size of the second matrix(split row and column with whitespace)"<< endl;
	    cin >> row >> column;
	    OrthMatrix m6(row, column);
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    m6.insert(i, j, data);
		}
	    }
	    cout << "Your second matrix is: \n";
	    m6.print();
	    cout << endl;
	    m5.multi(m6, answer);
	    cout << "answer is: \n";
	    answer.print();
	    cout << endl;
	}
	else if(strcmp(argv[1], "-t") == 0){
	    cout << "input size of the first matrix(split row and column with whitespace)"<< endl;
	    int row, column;
	    double data;
	    cin >> row >> column;
	    if(row <= 0 || column <= 0){
		cout << "invalid size\n";
		return -1;
	    }
	    
	    OrthMatrix m7(row, column);
	    OrthMatrix answer(row, column);
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    m7.insert(i, j, data);
		}
	    }
	    cout << "Your first matrix is: \n";
	    m7.print();
	    cout << "After transpose" << endl;
	    m7.transpose().print();
	    cout << endl;
	}
	else if(strcmp(argv[1], "-i") == 0){
	    cout << "input size of the first matrix(split row and column with whitespace)"<< endl;
	    int row, column;
	    double data;
	    cin >> row >> column;
	    if(row <= 0 || column <= 0){
		cout << "invalid size\n";
		return -1;
	    }
	    
	    OrthMatrix m8(row, column);
	    OrthMatrix answer(row, column);
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    m8.insert(i, j, data);
		}
	    }
	    cout << "Your first matrix is: \n";
	    m8.print();
	    cout << "After inversion" << endl;
	    m8.inverse().print();
	    cout << endl;
	}
    }
}
