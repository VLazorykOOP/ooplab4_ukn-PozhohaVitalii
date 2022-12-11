 // OOPLab4T.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №4. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//


#include <iostream>
#include <vector>

// Ваші файли загловки 
#include "2.1.h"
#include "2.2.h"
//

int main()
{
 
   
    std::cout << " Lab #4  task chain  !\n";
	void mainExample1() {
		int a = 6, b = 23, c = 34;
		VectorInt A(3, 3), B(3, 5), C(3, 1), D(3), F(1);
		D[0] = 7;
		D[1] = 3;
		D[2] = 6;
		F[0] = 1;
		F[1] = 3;
		cout << " Begin data " << endl;
		cout << " a= " << a << " b= " << b << " c " << c << endl;
		cout << " A  \n" << A;
		cout << " B  \n" << B;
		cout << " C  \n" << C;
		cout << " D  \n" << D;

		F = A + B - B * c + C / b + D * a;


		cout << " \n F =   \n" << F;
		cout << " A  \n" << A;
		cout << "++ A  \n" << ++A;
		A++;
		cout << " A ++ \n" << A;
		return 2;
	
	}

    void mainExample2() {
		MatrixInt A(5), B(5), C(5), D(5), F(5);
		VectorInt a(5), b(5), c(5);
		

		A.RandMatrixInt();
		B.RandMatrixInt();
		C.RandMatrixInt();
		D.RandMatrixInt();
		a.RandVectorInt();
		b.RandVectorInt();
		c.RandVectorInt()();

		cout << endl;
		cout << "Matrix A \n" << A;
		cout << "Matrix B \n" << B;
		cout << "Matrix C \n" << C;
		cout << "Matrix D \n" << D;
		cout << endl;
		cout << "Vector a \n" << a;
		cout << "Vector b \n" << b;
		cout << "Vector c \n" << c;

		/// Обчислити вираз : F = A+B*_a-B*_c+C/_b; 
		///                   c = F*a + D*b     
		F = A + B * 5 - B * _c + C / _b;
		cout << "Matrix F \n" << F;
		c = F * a + D * b;
		cout << "Vector c \n" << c;


		return 3;

    }
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту

    int chain = 1;
    if (chain == 1) chain = mainExample1();
    if (chain == 2) chain = mainExample2();
    if (chain == 3) chain = mainExample3();

}