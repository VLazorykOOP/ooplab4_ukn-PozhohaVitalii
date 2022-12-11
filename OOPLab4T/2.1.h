#include <iostream>
#include <fstream>
#include <vector>
//#include <math>
#include <string>

using namespace std;


class VectorInt {
	int* V;
	int size;
	string state;
public:
	VectorInt(){
		V = new[1](int);
		V[0] = 0;
	}
	VectorInt(int size1){
		V = new[size1](int);
		for (int i = 0; i < size; i++) { V[i] = 0; }
	}
	VectorInt(int value, int size1) {
		V = new[size1](int);
		for (int i = 0; i < size; i++) {
			V[i] = value;
		}
	}
	VectorInt(const VectorInt& Other) {
		size = Other.size;
		V = new[size](int);

		for (int i = 0; i < size; i++) {
			V[i] = Other.getV(i);

		}
	}

	int getsize() {
		return size;
	}
	

	int getV(int ind) {
		return V[ind];
		}
	void setV(int ind,int val) {
		V[ind]=val;
	}

	void operator + (const VectorInt & moreOther) {
		int G = !(moreOther.size < this.size) ? this.size : moreOther.size ;
		for (int i = 0; i < G; i++) {
			V[i] = V[i] + moreOther.getV(i);
		}
	}

	int RandInt()
	{
		return int(rand() % 10000 );
	}

	void Init(int n) {
		if (size != n) {
			if (V != nullptr) delete[] V;
			size = n;
			V = new int[n];
		}
		for (int i = 0; i < size; i++) 	V[i] = 0;
	}

	void Init(int n, int b) {
		if (size != n) {
			if (V != nullptr) delete[] V;
			size = n;
			V = new int[n];
		}
		for (int i = 0; i < size; i++) 	V[i] = b;
	}
	
	VectorInt & operator=(const VectorInt& s) {
		if (this == &s) return *this;
		if (size != s.size)
		{
			if (V) delete[] V;
			size = s.size;
			V = new int[size];
			state = "1";
		}
		for (int i = 0; i < size; i++)   V[i] = s.V[i];
		return *this;
	}

	VectorInt & operator=(VectorInt&& s) noexcept
	{
		if (this == &s) return *this;
		size = s.size; state = s.state;
		if (this->V != nullptr) delete[] V;
		V = s.V;
		s.size = 0; s.V = nullptr; s.state = "- 1" ;
		return *this;
	}

	void Input() {
		int in_num = 0;
		do {
			cout << "Input size Vec\n";
			cin >> in_num;
		} while (in_num <= 0);
		if (size != in_num) {
			size = in_num;
			if (V) delete[] V;
			V = new int[size];
		}
		cout << " v : real img  ";
		cin >> *this;
	}

	void Output() {
		if (size != 0) {
			std::cout << "vec = " << *this;
		}
	}

	bool operator!() const   // true : exist v[i] != 0
	{
		for (int i = 0; i < size; i++)
			if (V[i]!= NULL)
				return true;
		return false;
	}

	bool operator~() const  // true : all  v[i] != 0
	{
		for (int i = 0; i < size; i++)
			if (V[i] != NULL)
				return false;
		return true;
	}

	int & operator[](int index)
	{
		if (index >= 0 && index < size) return V[index];
		cout << " Error : operator[] - index out of range \n";
		return state = "index out of the range";
	}
	//postfix ++ operator
	VectorInt& operator++()
	{
		for (int i = 0; i < size; i++) V[i] += 1;
		return *this;
	}

	VectorInt& operator+=(const VectorInt& b)
	{
		int i;
		if (size == b.size) for (i = 0; i < size; i++) V[i] += b.V[i];
		else
		{
			cout << " Warning: vectors of different sizes are used in operation += \n";
			if (size < b.size) {
				int * tmp;
				tmp = new int[b.size];
				for (i = 0; i < size; i++) tmp[i] = V[i] + b.V[i];
				for (; i < b.size; i++) tmp[i] = b.V[i];
				size = b.size;
				if (V != nullptr) delete[] V;
				V = tmp;
			}
			else for (i = 0; i < b.size; i++) V[i] += b.V[i];
		}
		return *this;
	}
	//postfix ++ with an integer
	VectorInt& operator++(int A)
	{
		for (int i = 0; i < size; i++) V[i] += A;
		return *this;
	}

	VectorInt& operator+=(const int& b)
	{
		if (size > 0) {
			for (int i = 0; i < size; i++) V[i] += b;
		}
		return *this;
	}

	VectorInt& operator+=(const double& b)
	{
		if (size > 0) {
			for (int i = 0; i < size; i++) V[i] += b;
		}
		return *this;
	}

	VectorInt& operator+=(const long& b)
	{
		if (num > 0) {
			for (int i = 0; i < size; i++) v[i] += b;
		}
		return *this;
	}
	/*
	VectorInt operator+(const VectorInt& b)
	{
		VectorInt tmp(*this);
		tmp += b;
		return tmp;
	}
	*/
	VectorInt operator+(const int& b)
	{
		VectorInt tmp(*this);
		tmp += b;
		return tmp;
	}

	VectorInt operator+(const double& b)
	{
		VectorInt tmp(*this);
		tmp += b;
		return tmp;
	}

	VectorInt operator+(const long& b)
	{
		VectorInt tmp(*this);
		tmp += b;
		return tmp;
	}

	VectorInt& operator-=(const VectorInt& b)
	{
		int i;
		if (size == b.size) for (i = 0; i < size; i++) V[i] += b.V[i];
		else {
			cout << " Warning: vectors of different sizes are used in operation -= \n";
			if (size < b.size) {
				int* tmp;
				tmp = new int[b.size];
				for (i = 0; i < size; i++) tmp[i] = V[i] - b.V[i];
				for (; i < b.size; i++) tmp[i] = -b.V[i];
				size = b.size;
				if (V != nullptr) delete[] V;
				V = tmp;
			}
			else 	for (i = 0; i < b.size; i++) V[i] -= b.V[i];
		}
		return *this;
	}

	VectorInt& operator-=(const int& b)
	{
		if (size > 0) {
			for (int i = 0; i < size; i++) V[i] -= b;
		}
		return *this;
	}

	VectorInt & operator-=(const double& b)
	{
		if (size > 0) {
			for (int i = 0; i < size; i++) V[i] -= b;
		}
		return *this;
	}

	VectorInt& operator-=(const long& b)
	{
		if (size > 0) {
			for (int i = 0; i < size; i++) V[i] -= b;
		}
		return *this;
	}

	VectorInt operator-(const VectorInt& b)
	{
		VectorInt tmp(*this);
		tmp -= b;
		return tmp;
	}

	VectorInt operator-(const int& b)
	{
		VectorInt tmp(*this);
		tmp -= b;
		return tmp;
	}

	VectorInt operator-(const double& b)
	{
		VectorInt tmp(*this);
		tmp -= b;
		return tmp;
	}

	VectorInt operator-(const long& b)
	{
		VectorInt tmp(*this);
		tmp -= b;
		return tmp;
	}

	int operator*=(const VectorInt& b)  //  r= a0*b0+a1*b1+...+an-1*bn-1
	{
		 int ret = 0;
		if (size != b.size) { std::cout << " Error : vectors of different sizes are used in operation *= \n"; return ret; }
		for (int i = 0; i < size; i++) ret += V[i] * b.V[i];
		return ret;
	}

	VectorInt & operator%=(const  VectorInt& b)  // (a0*b0, a1*b1,...,an-1*bn-1)
	{
		if (size != b.size) { std::cout << " Error : vectors of different sizes are used in operation %= \n"; return *this; }
		for (int i = 0; i < size; i++) V[i] *= b.V[i];
		return *this;
	}

	VectorInt& operator*=(const int& b) {
		for (int i = 0; i < size; i++) v[i] *= b;
		return *this;
	}

	VectorInt& operator*=(const double& b) {
		for (int i = 0; i < size; i++) V[i] *= b;
		return *this;
	}

	VectorInt& operator*=(const long& b) {
		for (int i = 0; i < size; i++) V[i] *= b;
		return *this;
	}

	int operator*(const VectorInt& b)  //  r= a0*b0+a1*b1+...+an-1*bn-1
	{
		//	ComplexVector rez(*this);
		return *this * b;
	}

	VectorInt operator%(const VectorInt& b)  // (a0*b0, a1*b1,...,an-1*bn-1)
	{
		VectorInt rez(*this);
		rez *= b;
		return rez;
	}

	VectorInt operator*(const int & b) {
		VectorInt rez(*this);
		rez *= b;
		return rez;
	}

	VectorInt operator*(const double& b) {
		VectorInt rez(*this);
		rez *= b;
		return rez;
	}

	VectorInt operator*(const long& b) {
		VectorInt rez(*this);
		rez *= b;
		return rez;
	}

	VectorInt & operator/=(const VectorInt& b)  // (a0/b0, a1/b1,...,an-1/bn-1)
	{
		if (size != b.size || ~b) {
			std::cout << " Error: vectors of different sizes are used or b is zer0 opreation %= \n";
			return *this;
		}
		for (int i = 0; i < size; i++) V[i] *= b.V[i];
		return *this;
	}

	VectorInt & operator/=(const int & b)
	{
		if (b == 0)
		{
			std::cout << " Error Vector opreation /= b \n";
		}
		else for (int i = 0; i < size; i++) V[i] /= b;
		return *this;
	}

	VectorInt & operator/=(const double& b) {
		if (b == 0)
		{
			std::cout << " Error Vector opreation /= b \n";
		}
		else for (int i = 0; i < size; i++) V[i] /= b;
		return *this;
	}

	VectorInt & operator/=(const long& b) {
		if (b==0)
		{
			std::cout << " Error Vector opreation /= b \n";
		}
		else for (int i = 0; i < size; i++) V[i] /= b;
		return *this;
	}

	VectorInt operator/(const VectorInt& b)  // (a0/b0, a1/b1,...,an-1/bn-1)
	{
		VectorInt rez(*this);
		rez /= b;
		return rez;
	}

	VectorInt operator/(const int& b) {
		VectorInt rez(*this);
		rez /= b;
		return rez;
	}

	VectorInt operator/(const double& b) {
		VectorInt rez(*this);
		rez /= b;
		return rez;
	}

	VectorInt operator/(const long& b) {
		VectorInt rez(*this);
		rez /= b;
		return rez;
	}

	bool operator||(const VectorInt& b)
	{
		if (this->size > 0 || b.size > 0) return true;
		return false;
	}

	bool operator==(const VectorInt& s)
	{
		bool ret = true;
		if (size != s.size) return false;
		for (int i = 0; i < size && ret; i++) if ( V[i] != s.V[i]) ret = false;
		return ret;
	}

	bool operator!=(const VectorInt& s)
	{
		return !(*this == s);
	}

	void RandVectorInt()
	{
		for (int i = 0; i < size; i++) V[i] = RandInt();
	}
	/*
	ostream& operator<<(ostream& os, VectorInt& s) {
		for (int i = 0; i < s.size; i++)
			os << s.V[i] << '\t';
		os << endl;
		return os;
	}*/

	VectorInt& operator--(VectorInt& s)
	{
		s -= 1.0;
		return s;
	}
	//postfix -- with an integer
	VectorInt& operator--(VectorInt& s, int A)
	{
		s -= A ;
		return s;
	}

	bool operator&&(const VectorInt& a, const VectorInt& b)
	{
		if (a.size > 0 && b.size > 0) return true;
		return false;

	}



	~VectorInt() {
		delete[] V;
	}
};


