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
	Vector() { x = 0; y = 0; z = 0; } // что это за колхоз??????????

	/**
	 * Деструктор.
	 */
	~Vector()
	{
		//cout << "Destructor is working\n";
	}

	/**
	 * Сложение двух векторов.
	 * Сложение вектора с числом невозможно.
	 * @param Vector left
	 * @param Vector right
	 * @return Vector
	 */
	friend Vector operator + (const Vector& left, const Vector& right)  //хотелось бы услышать обоснование тго, что это не член класса, а дружественная функция!!!
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
	friend Vector operator - (const Vector& left, const Vector& right) //хотелось бы услышать обоснование тго, что это не член класса, а дружественная функция!!!
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
	 * @param Vector left
	 * @param double right
	 * @return Vector
	 */
	friend Vector operator * (const Vector& left, const double right)   //хотелось бы услышать обоснование тго, что это не член класса, а дружественная функция!!!
	{
		return Vector
		(
			left.x * right, 
			left.y * right, 
			left.z * right
		);
	}

	/**
	 * Умножение числа на вектор.
	 * @param double left
	 * @param Vector right
	 * @return Vector
	 */
	friend Vector operator * (const double left, const Vector& right)//хотелось бы услышать обоснование того, что это не член класса, а дружественная функция!!!
	{
		return Vector
		(
			left * right.x, 
			left * right.y,
			left * right.z
		);
	}

	/**
	 * Скалярное произведение двух векторов.
	 * @param Vector left
	 * @param Vector right
	 * @return double
	 */
	friend double operator * (const Vector& left, const Vector& right) 
	{
		return left.x * right.x + left.y * right.y + left.z * right.z;
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

	/**
	 * Векторное произведение двух векторов.
	 * @param Vector left
	 * @param Vector right
	 * @return Vector
	 */
	friend Vector vectorProduct(const Vector& left, const Vector& right)
	{
		return Vector
		(
			left.y * right.z - left.z * right.y,
			-(left.x * right.z - left.z * right.x),
			left.x * right.y - left.y * right.x
		);
	}

	/**
	 * Смешанное произведение трёх векторов.
	 * @param Vector a
	 * @param Vector b
	 * @param Vector c
	 * @return double
	 */
	friend double mixedProduct(const Vector& a, const Vector& b, const Vector& c)
	{
		return (Vector(a.y * b.z - a.z * b.y, -(a.x * b.z - a.z * b.x), a.x * b.y - a.y * b.x) * c);
	}

	/**
	 * Нахождение длины вектора.
	 * @param Vector i
	 * @return double
	 */
	friend double vectorLength(const Vector& i)
	{
		return sqrt(i.x * i.x + i.y * i.y + i.z * i.z);
	}

	/**
	 * Угол между векторами.
	 * Скалярное произведение векторов = произведение их длин * косинус угла между ними,
	   отсюда и итоговая ф-ла.
	 * Угол измеряется в радианах.
	 * @param Vector left
	 * @param Vector right
	 * @return Vector
	 */
	friend double vectorAngle(const Vector& left, const Vector& right)
	{
		return acos((left * right) / (vectorLength(left) * vectorLength(right)));
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

	Vector c(3, 7, 0);
	cout << "Значения координат вектора после вызова конструктора с параметрами:\t" << c << endl;

	cout << "Работа оператора сложения:\t"; 
	cout << b + c;
	cout << endl;

	cout << "Работа оператора вычитания:\t";
	cout << b - c;
	cout << endl;

	cout << "Работа оператора умножения вектора на число:\t";
	cout << b * 3;
	cout << endl;

	cout << "Работа оператора умножения числа на вектор:\t";
	cout << 3 * b;
	cout << endl;

	cout << "Работа оператора скалярного умножения:\t";
	cout << b * c;
	cout << endl;

	cout << "Работа метода векторного умножения и оператора присваивания:\t";
	a = vectorProduct(b, c);
	cout << a;
	cout << endl;

	cout << "Работа метода смешанного умножения:\t";
	Vector d(1, 1, 1);
	cout << mixedProduct(b, c, d);
	cout << endl;

	cout << "Работа метода нахождения длины:\t";
	cout << vectorLength(c);
	cout << endl;

	cout << "Работа метода нахождения угла между векторами:\t";
	cout << vectorAngle(b, c);
	cout << endl;

	system("pause");
	return 0;
}
