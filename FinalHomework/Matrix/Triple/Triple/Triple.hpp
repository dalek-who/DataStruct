#ifndef TRIPLE_H
#define TRIPLE_H

#ifndef ORTHMATRIX_H
#include "OrthMatrix.hpp"
#endif

#include <iostream>
#include <vector>


//structure for matrix
//conaining x, y, and data ele;
struct TriNode{
    int x, y;
    double ele;
};

class TriMatrix{
private:
    TriNode* Table;
    int row;
    int column;
    int NonNil;
    std::vector<int> rpos;
    
public:
    //Construtor which initialize an empty entity
    TriMatrix(int non_size, int r, int c)
	:row(r),
	 column(c),
	 NonNil(non_size)
	{
	    Table = new TriNode[non_size+1];
	    rpos.resize(row+2);
	    rpos[1] = 1;
	}

    //copy function
    TriMatrix(TriMatrix& input)
	:row(input.row),
	 column(input.column),
	 NonNil(input.NonNil)
	{
	    *this = input;
	}

    //Most used Constructor
    TriMatrix(int x, int y, std::vector<std::vector<double>> input)
	:row(x),
	 column(y)
	{
	    NonNil = 0;
	    for(int i = 0; i < x; ++i){
		for(int j = 0; j < y; ++j){
		    if(input[i][j] != 0)
			++NonNil;
		}
	    }
	    Table = new TriNode[NonNil+1];
	    rpos.resize(row+2);
	    int tempPosi = 1;
	    for(int i = 0; i < x; ++i){
		for(int j = 0; j < y; ++j){
		    if(input[i][j] != 0.0){
			Table[tempPosi].ele = input[i][j];
			Table[tempPosi].x = i+1;
			Table[tempPosi].y = j+1;
			++tempPosi;
		    }
		}
	    }
	    setRpos();
	}
    
    ~TriMatrix(){
	delete[] Table;
    }

    //**************************************************************************
    //setRpos method, set rpos array for every instance
    //NO PARAMETERS
    void setRpos();

    //**************************************************************************
    //print method, print out a matrix
    //NO PARAMTERS
    void print() const;

    //**************************************************************************
    //printTable methd, print out the content stored in Table
    //NO PARAMETERS
    void printTable() const;

    //**************************************************************************
    //add method, add matrix B to an instance and store result in matrix answer
    //PARAMTERS: TriMatrix B and answer
    //return value: TriMatrix
    TriMatrix& add(TriMatrix& B, TriMatrix& answer);

    //**************************************************************************
    //substruct method, substruct matrix B from instance and store result in matrix answer
    //PARAMTERS: TriMatrix B and answer
    //return value: TriMatrix
    TriMatrix& sub(TriMatrix& B, TriMatrix& answer);

    //**************************************************************************
    //multi method, multiply matrix B to an instance and store result in matrix answer
    //PARAMTERS: TriMatrix B and answer
    //return value: TriMatrix
    TriMatrix& multi(TriMatrix& B, TriMatrix& answer);

    //**************************************************************************
    //inverse method, inverse an instance and store result
    //in an OrthMatrixp instance B
    //PARAMETERS: OrthMatrix B
    //return value: B if iversed and *this if inversable
    OrthMatrix& inverse(OrthMatrix& B ) const;

    //**************************************************************************
    //fastTranspose method, fast transpose a matrix
    //NO PARAMETERS
    //return value: transposed matrix
    TriMatrix& fastTranspose() ;

    //overload operator= for copy
    TriMatrix& operator=(TriMatrix& B);
 
};

//No need to call this method directly
void TriMatrix::setRpos(){
    std::vector<int> num(row+2);
    for(int i = 1; i <= row; ++i)
	num[i] = 0;
    for(int i = 1; i <= row; ++i){
	++num[Table[i].x];
    }
    
    rpos[Table[1].x] = 1;
    for(int i = Table[1].x+1; i <= row; ++i)
	rpos[i] = rpos[i-1] + num[i-1];

}

void TriMatrix::print() const{
    int tempPosi = 1;
    for(int i = 1; i <= row; ++i){
        for(int j = 1; j <= column; ++j){
	    std::cout.width(3);
            if(tempPosi <= NonNil && Table[tempPosi].x == i && Table[tempPosi].y == j){
                std::cout << Table[tempPosi].ele << ' ';
                ++tempPosi;
            }
            else{
                std::cout << 0 << ' ';
            }
        }
        std::cout << std::endl;
    }
}

void TriMatrix::printTable() const{
    for(int i = 1; i <= NonNil; ++i)
        std::cout << Table[i].x << " " << Table[i].y <<" " << Table[i].ele << std::endl;
}

//example code in textbook is a little complicated, I use extra sapce to simplify this procedure
TriMatrix& TriMatrix::multi(TriMatrix& B, TriMatrix& answer){
    if(column != B.row)
	return *this;

    std::vector<double> ctemp(B.column+1);

    answer.row = this->row;
    answer.column = B.column;
    answer.NonNil = 0;

    if(!this->NonNil || !B.NonNil)
	return *this;

    //code in textbook uses only two vectors, but I use a matrix,
    //extra space is used, but code becomes more readable
    std::vector<std::vector<double> >
	tempMatrix(this->row+1, std::vector<double>(B.column+1));

    for(int i = 1; i <= this->NonNil; ++i){
	for(int j = 1; j <= B.NonNil; ++j){
	    if(Table[i].y == B.Table[j].x)
		tempMatrix[Table[i].x][B.Table[j].y]
		    +=  Table[i].ele * B.Table[j].ele;
	}
    }

    answer.NonNil = 0;
    for(int i = 1; i <= row; ++i)
	for(int j = 1; j <= B.column; ++j){
	    if(tempMatrix[i][j]){
		answer.Table[++answer.NonNil].ele = tempMatrix[i][j];
		answer.Table[answer.NonNil].x = i;
		answer.Table[answer.NonNil].y = j;
	    }
	}
    return answer;
}

//used OrthMatrixp::inverse instead writing a new one
OrthMatrix& TriMatrix::inverse(OrthMatrix& output) const{
    for(int i = 1; i <= NonNil; ++i)
	output.assign(Table[i].x-1, Table[i].y-1, Table[i].ele);
    return output.inverse();
}

//Idea is simple, code is slightly obscure
TriMatrix& TriMatrix::fastTranspose() {
    TriMatrix* answer = new TriMatrix(NonNil, column, row);
    //array to record number of elements in corresponding column
    std::vector<int> num(column+1);
    //array recording elements' column position
    std::vector<int> cpos(column+1);

    for(int i = 1; i <= column; ++i)
        num[i] = 0;
    for(int i = 1; i <= NonNil; ++i)
        ++num[Table[i].y];

    //
    cpos[1] = 1;
    for(int i = 2; i <= column; ++i)
        cpos[i] = cpos[i-1] + num[i-1];
    //Preparation is done, Now is for transpose
    int col;
    int insertPosi;
    for(int i = 1; i <= NonNil; ++i){
        col = Table[i].y;
        insertPosi = cpos[col];
        answer->Table[insertPosi].x = Table[i].y;
        answer->Table[insertPosi].y = Table[i].x;
        answer->Table[insertPosi].ele = Table[i].ele;
        ++cpos[col];
    }
    for(int i = 1; i <= NonNil; ++i){
	Table[i].x = answer->Table[i].x;
	Table[i].y = answer->Table[i].y;
	Table[i].ele = answer->Table[i].ele;
    }
    this->row = answer->row;
    this->column = answer->column;
    delete answer;
    return *this;
}

TriMatrix& TriMatrix::operator=(TriMatrix& B){
    if(row != B.row || column != B.column)
        return *this;
    if(this == &B)
	return *this;
	
    delete[] Table;
    rpos.resize(B.NonNil);
    Table = new TriNode[B.NonNil+1];
    NonNil = B.NonNil;

    std::cout << "Copying ..." << std::endl;
    for(int i = 1; i <= B.NonNil; ++i){
        Table[i].ele = B.Table[i].ele;
        Table[i].x = B.Table[i].x;
        Table[i].y = B.Table[i].y;
	rpos[i] = B.rpos[i];
    }
    return *this;
}

//addition
TriMatrix& TriMatrix::add(TriMatrix& B, TriMatrix& answer){
    if(row != B.row || column != B.column)
        return *this;

    answer.NonNil = 0;
    int Awalk = 1, Bwalk = 1, answerWalk = 1;

    while(1){
        if(Awalk <= NonNil && Bwalk <= B.NonNil && Table[Awalk].x == B.Table[Bwalk].x && Table[Awalk].y == B.Table[Bwalk].y){
            double temp = Table[Awalk].ele + B.Table[Bwalk].ele;
            if(temp){
                answer.Table[answerWalk].ele = temp;
                answer.Table[answerWalk].x = Table[Awalk].x;
                answer.Table[answerWalk].y = Table[Awalk].y;
                ++answerWalk;
                ++Awalk;
                ++Bwalk;
                ++answer.NonNil;
            }
            else{
                ++Awalk;
                ++Bwalk;
            }
        }
        else if(Awalk <= NonNil){
            if(Table[Awalk].x < B.Table[Bwalk].x || (Table[Awalk].x == B.Table[Bwalk].x && Table[Awalk].y < B.Table[Bwalk].y)){
                answer.Table[answerWalk].ele = Table[Awalk].ele;
                answer.Table[answerWalk].x = Table[Awalk].x;
                answer.Table[answerWalk].y = Table[Awalk].y;
                ++answerWalk;
                ++Awalk;
                ++answer.NonNil;
            }
        }
        else if(Bwalk <= B.NonNil){
            answer.Table[answerWalk].ele = B.Table[Bwalk].ele;
            answer.Table[answerWalk].x = B.Table[Bwalk].x;
            answer.Table[answerWalk].y = B.Table[Bwalk].y;
            ++answerWalk;
            ++Bwalk;
            ++answer.NonNil;
        }
        else{
	    break;
	}
        
    }
    //    answer->setRpos();
    return answer;
}


//substruction
TriMatrix& TriMatrix::sub(TriMatrix& B, TriMatrix& answer){
    if(row != B.row || column != B.column)
        return *this;

    int Awalk = 1, Bwalk = 1, answerWalk = 1;
    answer.NonNil = 0;

    while(1){
        if(Awalk <= NonNil && Bwalk <= B.NonNil && Table[Awalk].x == B.Table[Bwalk].x &&Table[Awalk].y == B.Table[Bwalk].y){
            double temp = Table[Awalk].ele - B.Table[Bwalk].ele;
            if(temp){
                answer.Table[answerWalk].ele = temp;
                answer.Table[answerWalk].x = Table[Awalk].x;
                answer.Table[answerWalk].y = Table[Awalk].y;
                ++answerWalk;
                ++Awalk;
                ++Bwalk;
                ++answer.NonNil;
            }
            else{
                ++Awalk;
                ++Bwalk;
            }
        }
        else if(Awalk <= NonNil){
            if((Table[Awalk].x < B.Table[Bwalk].x) || (Table[Awalk].x == B.Table[Bwalk].x && Table[Awalk].y < B.Table[Bwalk].y)){
                answer.Table[answerWalk].ele = Table[Awalk].ele;
                answer.Table[answerWalk].x = Table[Awalk].x;
                answer.Table[answerWalk].y = Table[Awalk].y;
                ++answerWalk;
                ++Awalk;
                ++answer.NonNil;
            }
        }
        else if(Bwalk <= B.NonNil){
            answer.Table[answerWalk].ele = -B.Table[Bwalk].ele;
            answer.Table[answerWalk].x = B.Table[Bwalk].x;
            answer.Table[answerWalk].y = B.Table[Bwalk].y;
            ++answerWalk;
            ++Bwalk;
            ++answer.NonNil;
        }
        else
            break;
    }
    //    answer.setRpos();
    return answer;
}
#endif
