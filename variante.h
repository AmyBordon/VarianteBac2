
#pragma once
#include "iostream"
using namespace std;
#include "fstream"
#include "string"

//varianta 1
struct ReperCartezian {
	int x, y;
};

void mijlocSegment(ReperCartezian A, ReperCartezian B) {

	ReperCartezian C;
	C.x = (A.x + B.x);
	C.y = (A.y + B.y);
}

//varianta 2

struct Fractie {
	int a, b;
};

void acelasiNumitor(Fractie f1, Fractie f2) {

	int a = f1.b, b = f2.b;
	f1.a *= b;
	f1.b *= b;
	f2.a *= a;
	f2.b *= a;
}

int cmmdc(int a, int b) {
	int m;
	if (a < b)
		m = a;
	else
		m = b;

	for (int i = a; i >= 1; i--)
		if (a % i == 0 && b % i == 0)
			return i;

}

Fractie ireductibila(Fractie f) {

	int c = cmmdc(f.a, f.b);
	f.a /= c;
	f.b = c;
	return f;
}

Fractie suma(Fractie f1, Fractie f2) {

	acelasiNumitor(f1, f2);
	Fractie f;
	f.a = f1.a + f2.a;
	f.b = f1.b;
	ireductibila(f);
	return f;
}