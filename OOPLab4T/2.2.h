#include "2.1.h"
#include <iostream>

using namespace std;

class MatrixInt 
{
private:
	VectorInt* IntArray; // масив
	unsigned int n, size; // розміри матриці
	unsigned char codeError; // код помилки
	static int num_matrix; // кількість матриць (загально доступнк) 

public:
	MatrixInt (){
		IntArray = nullptr; n = size = codeError = 0;
		num_matrix++;
	}
	MatrixInt(unsigned int isize) {
		n = isize;
		num_matrix++;
		IntArray = new VectorInt[n];
		for (int i = 0; i < n; i++) {
			IntArray[i].Init(n, 0);
			IntArray[i].setV(i, 1);
		}
	}
	MatrixInt(unsigned int isize, unsigned int isize1) {
		n = isize;
		size = isize1;
		num_matrix++;
		IntArray = new VectorInt[n];
		for (int i = 0; i < n; i++) {
			IntArray[i].Init(isize1, 0);		
		}
	}
	MatrixInt(unsigned int isize, unsigned int isize1, int ivalue) {
		n = isize;
		size = isize1;
		num_matrix++;
		IntArray = new VectorInt[n];
		for (int i = 0; i < n; i++) {
			IntArray[i].Init(isize1, ivalue);
		}
	}
	MatrixInt(const MatrixInt & Other){
		size = Other.size;
		n = Other.n;
		num_matrix++;
		codeError = Other.codeError;
		IntArray = new VectorInt[n];
		for (int i = 0; i < n; i++) {
			IntArray[i].Init(size, 0);			
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < size; j++) {
				IntArray[i].setV(j, Other.IntArray[i].getV(j);
			}
		}
	}


	MatrixInt& operator=(const MatrixInt& s)
	{
		if (this != &s) {
			int i;
			if (n != s.n || size != s.size) {
				n = s.n; size = s.size;
				if (IntArray != nullptr) {
					delete[] IntArray;
				}
				IntArray = new VectorInt[n];
				for (i = 0; i < n; i++) IntArray[i].Init(size, 0);
			}
			for (i = 0; i < n; i++)
				for (int j = 0; j < size; j++)  IntArray[i][j] = s.IntArray[i][j];

		}
		return *this;
	}

	MatrixInt& operator=(MatrixInt&& s) noexcept
	{
		n = s.n; size = s.size;
		IntArray = s.IntArray;
		s.IntArray = nullptr;
		s.n = 0; s.size = 0;
		return *this;
	}

	void Input()
	{
	}

	void Output()
	{
	}

	bool operator!() const
	{
		return false;
	}

	bool operator~() const
	{
		return false;
	}

	VectorInt& operator[](int index)
	{
		if (index >= 0 && index < n) return IntArray[index];
		cout << " Error : operator[] - index index out of range \n";
		return IntArray[0];
	}

	MatrixInt& operator+=(const MatrixInt& s)
	{
		if (s.n == n) for (int i = 0; i < n; i++) IntArray[i] += s.IntArray[i];
		else {
			cout << "Error: matrices of different dimensions \n";
			cout << "The += operation was not performed. \n";
		}
		return *this;
	}

	MatrixInt& operator+=(const int& b)
	{
		for (int i = 0; i < n; i++) IntArray[i] += b;
		return *this;
	}

	MatrixInt& operator+=(const double& b)
	{
		for (int i = 0; i < n; i++) IntArray[i] += b;
		return *this;
	}

	MatrixInt operator+(const MatrixInt& b)
	{
		MatrixInt mat(*this);
		mat += b;
		return mat;
	}

	MatrixInt operator+(const int& b)
	{
		MatrixInt mat(*this);
		mat += b;
		return mat;
	}

	MatrixInt operator+(const double& b)
	{
		MatrixInt mat(*this);
		mat += b;
		return mat;
	}

	MatrixInt& operator-=(const MatrixInt& s)
	{
		if (s.n == n) for (int i = 0; i < n; i++) IntArray[i] -= s.IntArray[i];
		else {
			cout << "Error: matrices of different dimensions \n";
			cout << "The += operation was not performed. \n";
		}
		return *this;
	}

	MatrixInt& operator-=(const int& b)
	{
		for (int i = 0; i < n; i++) IntArray[i] -= b;
		return *this;
	}

	MatrixInt& operator-=(const double& b)
	{
		for (int i = 0; i < n; i++) IntArray[i] -= b;
		return *this;
	}

	MatrixInt operator-(const MatrixInt& b)
	{
		MatrixInt mat(*this);
		mat -= b;
		return mat;
	}

	MatrixInt operator-(const int& b)
	{
		MatrixInt mat(*this);
		mat -= b;
		return mat;
	}

	MatrixInt operator-(const double& b)
	{
		MatrixInt mat(*this);
		mat -= b;
		return mat;
	}

	MatrixInt& operator*=(const int& b)
	{
		for (int i = 0; i < n; i++) IntArray[i] *= b;
		return *this;
	}

	MatrixInt& operator*=(const double& b)
	{
		for (int i = 0; i < n; i++) IntArray[i] *= b;
		return *this;
	}

	MatrixInt operator*(const MatrixInt& b)
	{
		if (n == b.size && size == b.size) {
			MatrixInt ret(size, n);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < size; j++)
				{
					ret[i][j] = 0;
					for (int l = 0; l < size; l++) ret[i][j] += IntArray[i][l] * b.IntArray[l][j];
				}
			return ret;
		}
		else {
			cout << "Error: matrices of different dimensions \n";
			cout << "The *  operation was not performed. \n";
			return *this;
		}
	}

	VectorInt operator*(const VectorInt& b)
	{
		VectorInt ret(n);
		if (n == (b.getsize())) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < size; j++)
				{
					ret[i] += IntArray[i][j] * b.V[j];
				}
		}
		else {
			cout << "Error: matrix and vector different dimensions \n";
			cout << "The *  operation was not performed. \n";
		}
		return ret;
	}

	MatrixInt operator*(const int& b)
	{
		MatrixInt mat(*this);
		mat *= b;
		return mat;
	}



	MatrixInt& operator/=(const int& b)
	{
		if (b==0)
		{
			std::cout << " Error Matrix opreation /= b \n";
		}
		else for (int i = 0; i < n; i++) IntArray[i] /= b;
		return *this;
	}



	MatrixInt operator/(const int& b)
	{
		MatrixInt mat(*this);
		mat *= b;
		return mat;
	}



	void RandMatrixInt()
	{
		for (int i = 0; i < n; i++) IntArray[i].RandVectorInt();
	}

	istream& operator>>(istream& is, MatrixInt& s)
	{
		for (int i = 0; i < s.n; i++) is >> s.IntArray[i];
		return is;
	}

	ostream& operator<<(ostream& os, MatrixInt& s)
	{
		for (int i = 0; i < s.n; i++) os << s.IntArray[i];  // << endl;
		return os;
	}



	~MatrixInt (){
	
	}
};
