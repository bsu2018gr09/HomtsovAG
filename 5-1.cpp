#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

struct color { unsigned char b; unsigned char g; unsigned char r; } c;

const float k(30), l(245), m(109), k1(85), l1(11), m1(169);

int main() 
{
	ifstream input("C:/Study/C++/imgEx.bmp", ios::binary); 
	ofstream output("C:/Study/C++/imgOut.bmp", ios::binary);
	if (!input) { cout << "No file C:/Study/C++/imgEx.bmp. Can't open\n"; exit(1); }
	if (!output) { cout << "  file C:/Study/C++/imgEx.bmp. Can't create\n"; exit(1); }

	char buf[30];
	color c;
	unsigned int w, h;

	input.read((char *)&buf, 18);   
	output.write((char *)&buf, 18);    
	input.read((char *)&w, 4);    
	input.read((char *)&h, 4); 
	w = 256; output.write((char *)&w, 4);    
	h = 256; output.write((char *)&h, 4);    
	input.read((char *)&buf, 28);   
	output.write((char *)&buf, 28);  

	c.r = k;
	c.g = l;
	c.b = m;

	float p1 = (k - k1) / w; float p11 = (k - k1) / w;
	float p2 = (l - l1) / w; float p22 = (l - l1) / w;
	float p3 = (m - m1) / w; float p33 = (m - m1) / w;
	bool flag1(true);
	bool flag2(true);
	bool flag3(true);

	if (p1 > 1 || p1 < -1) flag1 = false;
	if (p2 > 1 || p2 < -1) flag1 = false;
	if (p3 > 1 || p3 < -1) flag1 = false;

	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			output.write((char *)&c, 3);

			if (flag1)
			{
				p1 = p1 + p11;
				if (p1 < -1) --c.r;
				c.r = c.r - floor(p1); 
				p1 -= floor(p1);
			}
			else c.r = c.r - p1;
			
			

			if (flag2)
			{ 
				p2 = p2 + p22;
				if (p2 < -1) --c.g;
				c.g = c.g - floor(p2); 
				p2 -= floor(p2);
			}
			else c.g = c.g - p2;



			if (flag3)
			{ 
				p3 = p3 + p33;
				if (p3 < -1) --c.b;
				c.b = c.b - floor(p3); 
				p3 -= floor(p3);
			}
			else c.b = c.b - p3;
		}
		c.r = k;
		c.g = l;
		c.b = m;
		p1 = (k - k1) / w; 
		p2 = (l - l1) / w; 
		p3 = (m - m1) / w; 
	}

	input.close();
	output.close();
}