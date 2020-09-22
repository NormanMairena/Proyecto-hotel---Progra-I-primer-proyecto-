#pragma once
#include<iostream>
#include <sstream>
#include "Reservacion.h"
#include "cliente.h"
#include "time.h"
using namespace std;

class Habitacion{
private:
	int identificadorHabitacion;
	char estado;
	char estandarHabitacion;
	int NumeroCamas;
	Cliente* C;
	Reservacion* R;
public:
	Habitacion(int, char, char,int,Cliente*,Reservacion*);
	Habitacion();
	~Habitacion();

	//metodo especial
	void ingresarcliente(Cliente*, Reservacion*);
	Cliente* getcliente();
	Reservacion* getreservacion();
	int getnumreservacion();
	void anularCR();


	//gets
	int getidentificacionHabitacion();
	char getestado();
	char getestandarHabitacion();
	int getNumeroCamas();
	
	//sets
	void setidentificacionHabitacion(int);
	void setestado(char);
	void setestandarHabitacion(char);
	void setNumeroCamas(int);
	
	
	char RandomStandar();
	int RandomBed();

	//tostring
	string tostring();

};
