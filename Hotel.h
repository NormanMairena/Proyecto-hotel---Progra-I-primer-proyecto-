#pragma once
#include <time.h>
#include<iostream>
#include<sstream>
#include<string>
#include"Habitacion.h"
using namespace std;
class Hotel {
private:
	Habitacion*** Cuartos;
	/*Habitacion* ptrHab;*/
public:
	Hotel();
	string tostring();
	~Hotel();
	void inicializarIdentificacion();
	string inicializarEstado();

	
	void agregarHabitacion();
	Habitacion* gethabitacion(int,int);
	string opcion1_1();
	string opcion1_2(char);
	string opcion1_3(int);
	string opcion2_0(int);
	Habitacion* opcion3_0(int);
	string opcion4_2(int);
	string opcion5_complemento1(string);
	string opcion5_complemento2(int);
	string opcion6();
	string opcion7_0(int);
	string opcion8();
	string stringdereservaciones(string);
	string opcion4_1(int);
	
	


};


