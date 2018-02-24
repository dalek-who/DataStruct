#include "Triple.hpp"
#include <cstring>
#include <vector>

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
	    std::vector<std::vector<double>> input1(row, std::vector<double> (column));
	    int count = 0;
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    input1[i][j] = data;
		    count = (data) ? count+1 : count;
		}
	    }
	    TriMatrix m1(row, column, input1);
	    cout << "Your first matrix is: \n";
	    m1.print();
	    cout << endl;
	    
	    cout << "input size of the second matrix(split row and column with whitespace)"<< endl;
	    cin >> row >> column;
	    std::vector<std::vector<double>> input2(row, std::vector<double> (column));
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    input2[i][j] = data;
		    count = (data) ? count+1 : count;
		}
	    }
	    TriMatrix m2(row, column, input2);
	    cout << "Your second matrix is: \n";
	    m2.print();
	    cout << endl;
	    TriMatrix answer(count, row, column);
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
	    std::vector<std::vector<double>> input1(row, std::vector<double> (column));
	    int count = 0;
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    input1[i][j] = data;
		    count = (data) ? count+1 : count;
		}
	    }
	    TriMatrix m1(row, column, input1);
	    cout << "Your first matrix is: \n";
	    m1.print();
	    cout << endl;
	    
	    cout << "input size of the second matrix(split row and column with whitespace)"<< endl;
	    cin >> row >> column;
	    std::vector<std::vector<double>> input2(row, std::vector<double> (column));
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    input2[i][j] = data;
		    count = (data) ? count+1 : count;
		}
	    }
	    TriMatrix m2(row, column, input2);
	    cout << "Your second matrix is: \n";
	    m2.print();
	    cout << endl;
	    TriMatrix answer(count, row, column);
	    m1.sub(m2, answer);
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
	    std::vector<std::vector<double>> input1(row, std::vector<double> (column));
	    int count = 0;
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    input1[i][j] = data;
		    count = (data) ? count+1 : count;
		}
	    }
	    TriMatrix m1(row, column, input1);
	    cout << "Your first matrix is: \n";
	    m1.print();
	    cout << endl;
	    
	    cout << "input size of the second matrix(split row and column with whitespace)"<< endl;
	    cin >> row >> column;
	    std::vector<std::vector<double>> input2(row, std::vector<double> (column));
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    input2[i][j] = data;
		    count = (data) ? count+1 : count;
		}
	    }
	    TriMatrix m2(row, column, input2);
	    cout << "Your second matrix is: \n";
	    m2.print();
	    cout << endl;
	    TriMatrix answer(count, row, column);
	    m1.multi(m2, answer);
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
	    std::vector<std::vector<double>> input1(row, std::vector<double> (column));
	    int count = 0;
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    input1[i][j] = data;
		    count = (data) ? count+1 : count;
		}
	    }
	    TriMatrix m1(row, column, input1);
	    cout << "Your first matrix is: \n";
	    m1.print();
	    cout << endl;
	    
	    m1.fastTranspose().print();
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
	    std::vector<std::vector<double>> input1(row, std::vector<double> (column));
	    int count = 0;
	    for(int i = 0; i < row; i++){
		cout << "input data in row sequence" << std::endl;
		for(int j = 0; j < column; j++){
		    cin >> data;
		    input1[i][j] = data;
		    count = (data) ? count+1 : count;
		}
	    }
	    TriMatrix m1(row, column, input1);
	    OrthMatrix answer(row, column);
	    cout << "Your first matrix is: \n";
	    m1.print();
	    cout << endl;
	    cout << "Answer is: \n";
	    m1.inverse(answer).print();
	}
    }
}

