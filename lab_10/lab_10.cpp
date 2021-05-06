#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

class TrigonometricForm;

class AlgebraicForm {
private:
	double x = 0;
	double y = 0;
public:
	double SetDoubleNumber() {
		double number = 0;
		bool date_is_not_number = true;
		while (date_is_not_number)
		{
			cin >> number;
			date_is_not_number = cin.fail();
			if (date_is_not_number)
			{
				cout << "Entered is not a number.\n";
				cout << "Enter number again: ";
				cin.clear();
				cin.ignore(32767, '\n');
			}
			else {
				cin.ignore(32767, '\n');
				return number;
			}
		}
	}

	void SetXAndY(){
		cout << "Enter the real part of the complex number: ";
		x = SetDoubleNumber();
		cout << "Enter the imaginary part of the complex number: ";
		y = SetDoubleNumber();
	}

	void ShowComplexNumber(){
		if (x == 0){
			if (y == 0) {
				cout << "Your complex number: " << 0;
			}
			else {
				cout << "Your complex number: " << y << "i";
			}
		}
		else {
			if (y == 0) {
				cout << "Your complex number: " << x;
			}
			else {
				cout << "Your complex number: " << x << "+" << y << "i";
			}
		}
	}

	friend class TrigonometricForm;
};

class TrigonometricForm {
private:
	int module_z = 0;
	double cos = 0;
	double sin = 0;
	double corner = 0;
	static int degree;
public:
	void ConvertsNumber(AlgebraicForm a) {
		this->module_z = sqrt((a.x * a.x) + (a.y * a.y));
		this->cos = a.x / module_z;
		this->sin = a.y / module_z;
		this->corner = acos(cos);
	}

	void ShowComplexNumber() {
		if (module_z == 0) {
			cout << "Your complex number:" << 0;
		}
		else {
			cout << "Your complex number:" << module_z << "(cos " << corner << " + i sin" << corner << ")";
		}
	}

	static int SetDegree() {
		bool date_is_not_number = true;
		cout << "\nEnter the degree to erect:";
		while (date_is_not_number)
		{
			cin >> degree;
			date_is_not_number = cin.fail();
			if (date_is_not_number)
			{
				cout << "Entered is not a number.\n";
				cout << "Enter number again: ";
				cin.clear();
				cin.ignore(32767, '\n');
			}
			else {
				cin.ignore(32767, '\n');
				return degree;
			}
		}

	}

	TrigonometricForm operator ^ (int n) {
		this->module_z = pow(this->module_z, n);
		this->corner = this->corner * n;
		return *this;
	}
};

int TrigonometricForm::degree = 0;

int main()
{
	AlgebraicForm a;
	a.SetXAndY();
	a.ShowComplexNumber();
	TrigonometricForm b;
	b.ConvertsNumber(a);
	int Degree = TrigonometricForm::SetDegree();
	b = b^ Degree;
	b.ShowComplexNumber();
}
