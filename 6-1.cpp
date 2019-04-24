//Векторы в трёхмерном пространстве.
#include<iostream>
#include<cmath>

using namespace std;

class Vector 
{
public:
	/**
	 * Конструктор с параметрами.
	 */
	Vector(double X, double Y, double Z) : x(X), y(Y), z(Z)
	{
		//cout << "Constructor is working\n";
	}

	/**
	 * Конструктор по умолчанию.
	 */
	Vector() {} //  "мусор" внутри х,y,z. Тебя это не смущает????

	/**
	 * Деструктор.
	 */
	~Vector()
	{
		//cout << "Destructor is working\n";
	}

	/**
	 * Сложение двух векторов.
	 * Сложение вектора с числом невозможно.///А почему??????????????
	 * @param Vector left
	 * @param Vector right
	 * @return Vector
	 */
	friend Vector operator + (Vector& left, Vector& right)  // а почему не член-класса, почему friend??? Обоснуй!!!!
	{
		return Vector
		(
			left.x + right.x, 
			left.y + right.y, 
			left.z + right.z
		);
	}

	/**
	 * Разность двух векторов.
	 * @param Vector left
	 * @param Vector right
	 * @return Vector
	 */
	friend Vector operator - (Vector& left, Vector& right)
	{
		return Vector
		(
			left.x - right.x, 
			left.y - right.y, 
			left.z - right.z
		);
	}

	/**
	 * Умножение вектора на число.
	 * Число должно быть записано в переменную, т.к. происходит передача по ссылке ///А зачем??????????????
	 * @param Vector left
	 * @param double right
	 * @return Vector
	 */
	friend Vector operator * (Vector& left, double& right)   
	{
		return Vector
		(
			left.x * right, 
			left.y * right, 
			left.z * right
		);
	}

	/**
	 * Скалярное произведение двух векторов.
	 * @param Vector left
	 * @param Vector right
	 * @return double
	 */
	friend double operator * (Vector& left, Vector& right) 
	{
		return left.x * right.x + left.y * right.y + left.z * right.z;
	}

	/**
	 * Векторное произведение двух векторов.
	 * @param Vector left
	 * @param Vector right
	 * @return Vector
	 */
	friend Vector operator & (Vector& left, Vector& right)   // странный выбор значка ))
	{
		return Vector
		(
			left.y * right.z - left.z * right.y, 
			-(left.x * right.z - left.z * right.x), 
			left.x * right.y - left.y * right.x
		);
	}

	/**
	 * Оператор вывода.
	 */
	friend ostream& operator << (ostream &stream, const Vector& i)
	{
		stream << i.x << '\t' << i.y << '\t' << i.z;
		return stream;
	}

	/**
	 * Оператор ввода.
	 */
	friend istream& operator >> (istream& stream, Vector& i) 
	{ 
		stream >> i.x;
		stream >> i.y;
		stream >> i.z;
		return stream;
	}

	/**
	 * Оператор присваивания.
	 */
	const Vector& operator = (const Vector& i) 
	{
		if (this != &i) 
		{
			this->x = i.x;
			this->y = i.y;
			this->z = i.z;
		}
		return *this;
	}
private:
	double x;
	double y;
	double z;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Vector a;
	cout << "Значения координат вектора после вызова конструктора по умолчанию:\t" << a << endl;

	Vector b(57, 10, 36);
	cout << "Значения координат вектора после вызова конструктора с параметрами:\t" << b << endl;

	Vector c(3, 2, 7);
	cout << "Значения координат вектора после вызова конструктора с параметрами:\t" << c << endl;

	double x(3.0);

	cout << "Работа оператора сложения:\t"; 
	cout << b + c;
	cout << endl;

	cout << "Работа оператора вычитания:\t";
	cout << b - c;
	cout << endl;

	cout << "Работа оператора умножения на число:\t";
	cout << b * x;
	cout << endl;

	cout << "Работа оператора скалярного умножения:\t";
	cout << b * c;
	cout << endl;

	cout << "Работа оператора векторного умножения и присваивания:\t";
	a = b & c;
	cout << a;
	cout << endl;

	system("pause");
	return 0;
}
