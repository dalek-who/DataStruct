#ifndef ORTHMATRIX_H
#define ORTHMATRIX_H
#include <cstdlib>
#include <iostream>


typedef double E;

const int default_size = 20;

//node structure, each element in orthogonal list is nullptr or node
struct Node{
    //i for row, j for column
    int i, j;
    E ele;
    Node *right;
    Node *down;
    //construction function, initialzing nodes once they are declared
    Node(int x = 0, int y = 0, E elem = 0, Node* r= nullptr, Node* d = nullptr)
        :i(x),
	 j(y),
	 ele(elem),
	 right(r),
	 down(d) {};
};

//OrthMatrix class, which is cross-link list
class OrthMatrix{
private:
    Node** Row;
    Node** Column;
    int row, column;
public:
    //*************************************************************************
    //Construction function, initialize every OrthMatrix object to 20 * 20 matrix
    //if size is not given
    //PARAMETERS: r for row, c for column
    OrthMatrix(const int r = default_size, const int c = default_size);
    OrthMatrix(const OrthMatrix& B);

    //*************************************************************************
    //Destruction function, cleans up memory before program exits
    //No PARAMETERS
    ~OrthMatrix();

    //*************************************************************************
    //insert method, insert elements to OrthMatrix object for initialization
    //PARAMETERS: row, column, input data
    void insert(const int , const int , const E&);

    //*************************************************************************
    //assign method, insert elements to OrthMatrix object if the element does not
    //exist, or assign new value to existing element
    //PARAMETERS: row, column, input data
    void assign(const int, const int, const E&);

    //*************************************************************************
    //setZero method, delete zero element, designed for transpose
    //PARAMETERS: row, column
    void setZero(const int, const int);

    void Destroy();
    //*************************************************************************
    //print method, print out a matrix object
    //NO PARAMETERS
    void print() const;

    //**************************************************************************
    //value method, obtain value at row x, column y
    //PARAMETERS: row, column
    //return value: OrthMatrixp[row, column]
    E value(const int, const int) const;

    OrthMatrix& add(const OrthMatrix& B, OrthMatrix& C) const;
    OrthMatrix& sub(const OrthMatrix& B, OrthMatrix& C) const;
    //**************************************************************************
    //multi method, for multiplication
    //PARAMETERS: a OrthMatrix object
    //return value: reference of a new OrthMatrix object
    OrthMatrix& multi(const OrthMatrix& B, OrthMatrix& C) const;

    //**************************************************************************
    //transpose method, for transpose
    //NO PARAMETERS
    //return value: reference of a transposed matrix
    OrthMatrix& transpose();

    //**************************************************************************
    //inverse method, for matrix inverse
    //NO PARAMETERS
    //return an inversed matrix
    OrthMatrix& inverse() ;

    //**************************************************************************
    //two get methods, ignore them
    inline int getRow() const{
	return row;
    }
    inline int getColumn() const{
	return column;
    }

    //**************************************************************************
    //overload operator = for matrix copy to avoid double delete on heap
    //PARAMETERS: a OrthMatrix object
    //return value: reference of a new OrthMatrix as a copy of OrthMatrix B
    OrthMatrix& operator= (const OrthMatrix& B);


};

//r for row
//c for column
OrthMatrix::OrthMatrix(const int r, const int c)
    :row(r),
    column(c)
{
    //One more element to avoid segmentation fault, personal habit, ignore it
    Row = new Node*[r+1];
    Column = new Node*[c+1];

    if(!Row || !Column){
        std::cout << "Construction failed" << std::endl;
        exit(-1);
    }
    for(int i = 0; i < r; ++i){
        Row[i] = new Node;
        Row[i]->right = nullptr;
        Row[i]->j = -1;
    }
    for(int j = 0; j < c; ++j){
        Column[j] = new Node;
        Column[j]->down = nullptr;
        Column[j]->i = -1;
    }
}

OrthMatrix::OrthMatrix(const OrthMatrix &B){
    *this = B;
}

OrthMatrix::~OrthMatrix(){
    Node* temp;
    //Destroy rows first, and then column
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            temp = Row[i]->right;
            while(temp){
		Row[i]->right = temp->right;
		delete temp;
		temp = Row[i]->right;
            }
        }
	delete Row[i];
    }

    for(int j = 0; j < column; ++j)
	delete Column[j];
    delete[] Row;
    delete[] Column;
}

void OrthMatrix::insert(const int r, const int c, const E& input){
    if(r >= row || c >= column || r < 0 || c < 0)
        return;

    if(!input)
        return;

    Node* temp = new Node;
    Node* search;
    temp->i = r, temp->j = c; temp->ele = input;
    //Row insertion
    if(Row[r]->right == nullptr){
        temp->right = Row[r]->right;
        Row[r]->right = temp;
    }
    else{
        for(search = Row[r]; (search->right) && search->right->j < c;search = search->right)
            ;
        temp->right = search->right;
        search->right = temp;
    }

    //Column insertion
    if(Column[c]->down == nullptr){
        temp->down = Column[c]->down;
        Column[c]->down= temp;
    }
    else{
        for(search = Column[c]; (search->down) && search->down->i < r;search = search->down)
            ;
        temp->down= search->down;
        search->down= temp;
    }
}

//after fully initialization, insert is not recommanded, use assign instead
void OrthMatrix::assign(const int r, const int c, const E& input){
    if(r >= row || c >= column || r < 0 || c < 0)
        return;


    if(input == 0){
	this->setZero(r, c);
	return;
    }

    if(value(r, c) == 0)
        insert(r, c, input);
    else{
        Node* search;
        for(search = Row[r]; search->right && search->right->j < c; search = search->right)
            ;
        search = search->right;
        search->ele = input;
    }
}

void OrthMatrix::setZero(const int ro, const int col){
    Node* pre;
    Node* tempRow;
    Node* tempColumn;

    if(ro < 0 || col < 0 || ro >= row || col >= column)
	return;
    //row
    for(tempRow = Row[ro]; tempRow->right && tempRow->right->j < col; tempRow = tempRow->right)
        ;
    pre = tempRow;
    tempRow = tempRow->right;
    if(tempRow){
        pre->right = tempRow->right;
    }

    //column
    for(tempColumn = Column[col]; tempColumn->down && tempColumn->down->i < ro; tempColumn = tempColumn->down)
        ;
    pre = tempColumn;
    tempColumn = tempColumn->down;
    if(tempColumn){
        pre->down = tempColumn->down;
    }

    //It is fine to delete a nullptr
    delete tempRow;
}

void OrthMatrix::Destroy(){
    Node* temp;
    std::cout << std::endl;
    //Destroy rows first, and then column
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            temp = Row[i]->right;
            while(temp){
		Row[i]->right = temp->right;
		delete temp;
		temp = Row[i]->right;
            }
        }
	delete Row[i];
    }

    for(int j = 0; j < column; ++j)
	delete Column[j];
    delete[] Row;
    delete[] Column;
}

void OrthMatrix::print() const {
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            std::cout.width(3);
            std::cout << value(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

E OrthMatrix::value(const int ro, const int col) const {
    Node* search;
    for(search = Row[ro]; search->right && search->right->j < col; search = search->right)
        ;
    search = search->right;
    if(search && search->j == col)
        return search->ele;
    else
        return 0;
}

OrthMatrix& OrthMatrix::multi(const OrthMatrix& B, OrthMatrix& C) const{
    if(this->getColumn() != B.getRow())
	return C;

    OrthMatrix returnOrthMatrix(row, B.column);
    int temp = 0;
    for(int i = 0; i < this->row; ++i){
        for(int j = 0; j < this->column; ++j){
            for(int CNum = 0; CNum < this->column; ++CNum){
                temp+= value(i, CNum)*B.value(CNum, j);
            }
            returnOrthMatrix.assign(i, j, temp);
            temp = 0;
        }
    }
    C = returnOrthMatrix;
    return C;
}

//this is a large function, read slowly
OrthMatrix& OrthMatrix::inverse() {
    if(row != column)
	return *this;
    E** expandOrthMatrix = new E*[this->row];
    //initialize expandmatrix;
    for(int i = 0; i < row; ++i){
	expandOrthMatrix[i] = new E[this->column*2];
	for(int j = 0; j < column*2; ++j){
	    if(j < column)
		expandOrthMatrix[i][j] = value(i, j);
	    else
		expandOrthMatrix[i][j] = (i == j-column) ? 1.0 : 0.0;
	}
    }

    //Now calculate inverse matrix, might be complex
    //one step one row, at most row times calculation
    bool rowRecrod[row];
    for(int i = 0; i < row; ++i)
	rowRecrod[i] = false;
    for(int count = 0; count < row; ++count){
	int j;
	for(j = 0; j < row; ++j){
	    //find the first row whose (j, count) element is not zero
	    if(expandOrthMatrix[j][count] != 0 && !rowRecrod[j] ){
		rowRecrod[j] = true;
		E co = expandOrthMatrix[j][count];
		for(int i = 0; i < column*2; ++i){
		    //Normolization
		    expandOrthMatrix[j][i] /= co;
		}
		//each row substruct j row
		for(int i = 0; i < row; ++i){
		    if(i == j)     //skip itself
			continue;
		    double multiple = expandOrthMatrix[i][count]/expandOrthMatrix[j][count];
		    for(int m = 0; m < column*2; ++m)
			expandOrthMatrix[i][m] -= multiple * expandOrthMatrix[j][m];
		}
	    }
	}
    }//calculation is done

    //rearange expandmatrix to find inversed matrix;
    for(int i = 0; i < row; ++i){
	if(expandOrthMatrix[i][i] == 0){
	    //look for non-zero row in the same column
	    for(int find = 0; find < row; ++find){
		if(expandOrthMatrix[find][i] != 0){
		    E* temp = expandOrthMatrix[i];
		    expandOrthMatrix[i] = expandOrthMatrix[find];
		    expandOrthMatrix[find] = temp;
		    break;
		}
	    }
	}
    }

    //check if inversed matrix really exits
    double temp = 0;
    for(int i = 0; i < row; ++i){
	for(int j = 0; j < column; ++j){
	    temp += expandOrthMatrix[i][j];
	}
	if(temp == 0){
	    std::cout << "Inversion not available" << std::endl;
	    for(int i = 0; i < row; ++i){
		delete[] expandOrthMatrix[i];
	    }
	    delete[] expandOrthMatrix;
	    std::cout << "leave matrix uninversed" << std::endl;
	    return *this;

	}
	else
	    temp = 0;
    }

    //copy right part of expandmatrix to return matrix;
    //OrthMatrix* answer = new OrthMatrix(row, row);
    for(int i = 0; i < row; ++i)
	for(int j = column; j < column*2; ++j)
	    this->assign(i, j-column, expandOrthMatrix[i][j]);

    //No STL, so I have to restore memoty used by expandmatrix
    for(int i = 0; i < row; ++i){
	delete[] expandOrthMatrix[i];
    }
    delete[] expandOrthMatrix;
    return *this;
}



//Realloc is not available, so if matrix is not phalanx,
//this method return a new OrthMatrix object as transpose
//old object is reserved
OrthMatrix& OrthMatrix::transpose() {
    if(row == column){
    	for(int i = 0; i < this->getRow(); ++i)
    	    for(int j = 0; j < this->getColumn(); ++j)
    	        this->assign(j, i, this->value(i, j));
	return *this;
    }
    else{
	OrthMatrix* temp = new OrthMatrix(this->getColumn(), this->getRow());
	for(int i = 0; i < getRow(); ++i)
	    for(int j = 0; j < getColumn(); ++j)
		temp->assign(j, i, value(i, j));
	*this = *temp;
	delete temp;
	return *this;
    }

}

OrthMatrix& OrthMatrix::add (const OrthMatrix& B, OrthMatrix& C) const{
    if(row != B.row || column != B.column)
        return C;
    OrthMatrix answer(row, column);
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < column; ++j){
            answer.assign(i, j, value(i, j)+B.value(i, j));
        }
    C = answer;
    return C;
}

OrthMatrix& OrthMatrix::sub (const OrthMatrix& B , OrthMatrix& C) const{
    if(row != B.row || column != B.column)
        return C;

    OrthMatrix answer(row, column);
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < column; ++j){
            answer.assign(i, j, value(i, j)-B.value(i, j));
        }
    C = answer;
    return C;
}


OrthMatrix& OrthMatrix::operator=(const OrthMatrix& B){
    //TODO: MEMORY RESTORE
    if(this == &B)
	return *this;
    Destroy();
    int r = B.getRow();
    int c = B.getColumn();
    Row = new Node*[r+1];
    Column = new Node*[c+1];
    for(int i = 0; i < r; ++i){
	Row[i] = new Node;
	Row[i]->right = nullptr;
	Row[i]->j = -1;
    }
    for(int j = 0; j < c; ++j){
	Column[j] = new Node;
	Column[j]->down = nullptr;
	Column[j]->i = -1;
    }
    if(!Row || !Column){
        std::cout << "Construction failed" << std::endl;
        exit(-1);
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            this->insert(i, j, B.value(i, j));
        }
    }

    row = r;
    column = c;
    return *this;
}
#endif
