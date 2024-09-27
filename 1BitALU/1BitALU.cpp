#include <iostream>

using namespace std;


int AND_gate(int a, int b);
int OR_gate(int a, int b);

int full_adder(int a, int b, int cin, int& cout);
int mux_2x1(int x1, int x2, int sel);
int mux_4x1(int x1, int x2, int x3, int x4, string sel);
int ALU_1bit(int a, int b, int B_inv, int cin, string op, int& cout);


int XOR_gate(int a, int b);



int main()
{
	int a = 0;
	int b = 1;

	int c = 0;
	int d = 0;


	int cinINP = 1;
	int coutINP;
	cout << "\na = " << a << "\nb = " << b << endl;
	cout << "AND Result: " << AND_gate(a, b) << endl;

	cout << "\na = " << a << "\nb = " << b << endl;
	cout << "OR Result: " << OR_gate(a, b) << endl;


	cout << "\na = " << a << "\nb = " << b << "\ncin = " << cinINP << endl;
	cout << "ADD Result: " << full_adder(a, b, cinINP, coutINP) << endl;
	cout << "cout = " << coutINP << endl;

	cout << "Mux 4x1 = " << mux_4x1(a, b, c, d, "10") << endl;

	return 0;
}

int AND_gate(int a, int b)
{

	return (a & b);
}


int OR_gate(int a, int b)
{
	
	return (a | b);
}

int full_adder(int a, int b, int cin, int& cout)
{
	////XOR_gate(a, b); // initial XOR
	//int sum = XOR_gate(XOR_gate(a, b), cin); // sum
	////AND_gate(a, b); // initial AND
	////AND_gate(XOR_gate(a, b), cin);
	//cout = OR_gate(AND_gate(XOR_gate(a, b), cin), AND_gate(a, b));

	int sum = (a ^ b ^ cin);
	cout = (a & b) | (cin & (a ^ b));


	return sum;
}

int mux_2x1(int x1, int x2, int sel)
{
	
	return ((sel == 0) ? x1 : x2); // If sel == 0, return x1, if sel != 0 return x2

}

int mux_4x1(int x1, int x2, int x3, int x4, string sel)
{
	switch (atoi(sel.c_str()))
	{
	case 00:
		return x1;
		break;

	case 01:
		return x2;
		break;

	case 10:
		return x3;
		break;

	case 11:
		return x4;
		break;



	}

}



int XOR_gate(int a, int b)
{

	return (a ^ b);
}