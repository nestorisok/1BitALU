#include <iostream>
#include <bitset>
using namespace std;
//



int AND_gate(int a, int b);
int OR_gate(int a, int b);

int full_adder(int a, int b, int cin, int& cout);
int mux_2x1(int x1, int x2, int sel);
int mux_4x1(int x1, int x2, int x3, int x4, string sel);
int ALU_1bit(int a, int b, int B_inv, int cin, string op, int& cout);




int main()
{
	int a = 0;
	int b = 0;

	int cinINP = 0;
	int Binv = 0;
	string opCode = "00";

	int res;
	int coutINP = 0;

	// AND results
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "\t\t AND results \t\t" << endl; 
	cout << "\ta\tb\tcin\tBinv\top\tresult\tcout" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 8; i++)
	{
		a = (i >> 2) & 1;	// gets the left-most bit
		b = (i >> 1) & 1;	// gets the 2nd bit
		cinINP = (i >> 0) & 1; // gets the right-most bit
		Binv = 0;
		opCode = "00"; // AND

		res = ALU_1bit(a, b, Binv, cinINP, opCode, coutINP);

		cout << "\t" << a << "\t" << b << "\t" << cinINP << "\t" << Binv << "\t" << opCode << "\t" << res << "\t" << coutINP << endl;
	}

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "\t\t OR results \t\t" << endl;
	cout << "\ta\tb\tcin\tBinv\top\tresult\tcout" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 8; i++)
	{
		a = (i >> 2) & 1;	// gets the left-most bit, since in code a = 
		b = (i >> 1) & 1;	// gets the 2nd bit
		cinINP = (i >> 0) & 1; // gets the right-most bit
		Binv = 0;
		opCode = "01"; // OR

		res = ALU_1bit(a, b, Binv, cinINP, opCode, coutINP);

		cout << "\t" << a << "\t" << b << "\t" << cinINP << "\t" << Binv << "\t" << opCode << "\t" << res << "\t" << coutINP << endl;
	}

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "\t\t ADD results \t\t" << endl;
	cout << "\ta\tb\tcin\tBinv\top\tresult\tcout" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 8; i++)
	{
		a = (i >> 2) & 1;	// gets the left-most bit, since in code a = 
		b = (i >> 1) & 1;	// gets the 2nd bit
		cinINP = (i >> 0) & 1; // gets the right-most bit
		Binv = 0;
		opCode = "10"; // ADD

		res = ALU_1bit(a, b, Binv, cinINP, opCode, coutINP);

		cout << "\t" << a << "\t" << b << "\t" << cinINP << "\t" << Binv << "\t" << opCode << "\t" << res << "\t" << coutINP << endl;
	}

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "\t\t SUB results \t\t" << endl;
	cout << "\ta\tb\tcin\tBinv\top\tresult\tcout" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 8; i++)
	{
		a = (i >> 2) & 1;	// gets the left-most bit, since in code a = 
		b = (i >> 1) & 1;	// gets the 2nd bit
		cinINP = (i >> 0) & 1; // gets the right-most bit
		Binv = 1;
		opCode = "10"; // ADD/SUB in this case
		
		res = ALU_1bit(a, b, Binv, cinINP, opCode, coutINP);

		cout << "\t" << a << "\t" << b << "\t" << cinINP << "\t" << Binv << "\t" << opCode << "\t" << res << "\t" << coutINP << endl;
	}

	//for (int j = 0; j < 3; j++)
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		a = (i >> 2) & 1;	// gets the left-most bit, since in code a = 
	//		b = (i >> 1) & 1;	// gets the 2nd bit
	//		cinINP = (i >> 0) & 1; // gets the right-most bit
	//		Binv = 0;
	//		opCode = bitset<2>(j).to_string(); // ADD/SUB in this case

	//		res = ALU_1bit(a, b, Binv, cinINP, opCode, coutINP);

	//		cout << "\t" << a << "\t" << b << "\t" << cinINP << "\t" << Binv << "\t" << opCode << "\t" << res << "\t" << coutINP << endl;
	//	}
	//}

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

int ALU_1bit(int a, int b, int B_inv, int cin, string op, int& cout)
{
	switch (atoi(op.c_str()))
	{
	case 00: // AND
		return (a & b);
		break;

	case 01: // OR
		return (a | b);
		break;

	case 10: // ADD

		// if B_inv = 0 and b = 1, b = 1 or if b = 0, b = 0; 
		// if B_inv = 1 and b = 1, b = 0, or if b = 0, b = 1
		b = (B_inv ^ b); 
		
		cout = (a & b) | (cin & (a ^ b));
		return (a ^ b ^ cin);
		break;


	}

}
