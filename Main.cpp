#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include "Hotel.h"
#include "Control.h"
#include "Habitacion.h"
#include <time.h>

using namespace std;

int main() {
	
	Hotel* u = new Hotel();
	Control* c = new Control(u);
	c->menu();
	cin.get();
	cin.get();
	delete u;
	delete c;
	return 0;
}