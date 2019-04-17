//¬екторы в трЄхмерном пространстве
#include<iostream>
#include<cmath>

using namespace std;

class Vector 
{
public:
	Vector(float X, float Y, float Z)
	{
		cout << "Constructor is working\n";
		x = X;
		y = Y;
		z = Z;
	}

	~Vector()
	{
		cout << "Destructor is working\n";
	}

	friend Vector operator + (Vector& left, Vector& right)
	{
		float tmpx = left.x + right.x;
		float tmpy = left.y + right.y;
		float tmpz = left.z + right.z;
		return Vector(tmpx, tmpy, tmpz);
	}

	friend Vector operator - (Vector& left, Vector& right)
	{
		float tmpx = left.x - right.x;
		float tmpy = left.y - right.y;
		float tmpz = left.z - right.z;
		return Vector(tmpx, tmpy, tmpz);
	}

	friend Vector operator * (Vector& left, Vector& right)   //скал€рное произведение
	{
		float tmpx = left.x * right.x;
		float tmpy = left.y * right.y;
		float tmpz = left.z * right.z;
		float tmpexit = tmpx + tmpy + tmpz;
		return Vector(tmpexit, 0, 0);
	}

	friend Vector operator *= (Vector& left, Vector& right)   //векторное произведение
	{
		float tmpx = left.y * right.z - left.z * right.y;
		float tmpy = -(left.x * right.z - left.z * right.x);
		float tmpz = left.x * right.y - left.y * right.x;
		return Vector(tmpx, tmpy, tmpz);
	}

	friend ostream& operator << (ostream &stream, const Vector& i)
	{
		stream << i.x << '\t' << i.y << '\t' << i.z;
		return stream;
	}

	friend istream& operator >> (istream& stream, Vector& i) 
	{ 
		stream >> i.x;
		stream >> i.y;
		stream >> i.z;
		return stream;
	}

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
	float x;
	float y;
	float z;
};

int main()
{
	Vector a(1, 1, 1);
	Vector b(2, 10, 2);
	Vector sum = a + b;
	Vector diff = a - b;
	cout << sum << '\n';
	cout << diff << '\n';

	Vector e(0, 0, 0);
	cin >> e;
	cout << e << '\n';

	Vector scalM = a * b;   //скал€рное умножение
	Vector vectM = a *= b;   //векторное умножение
	cout << scalM << '\n' << vectM << '\n';

	system("pause");
	return 0;
}