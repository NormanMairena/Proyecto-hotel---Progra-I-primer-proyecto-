#include "Habitacion.h"

Habitacion::Habitacion(int id, char estado, char clase,int NumCamas,Cliente* C, Reservacion* R) {
	this->identificadorHabitacion = id;
	this->estado = estado;
	this->estandarHabitacion =clase;
	this->NumeroCamas=NumCamas;
	this->C = C;
	this->R = R;
}

Habitacion::Habitacion(){
	this->identificadorHabitacion = 1;
	this->estado = 'L';
	this->estandarHabitacion = 'T';
	this->NumeroCamas = 0;
	C = NULL;
	R = NULL;
}
Habitacion::~Habitacion(){delete C;delete R;}
void Habitacion::ingresarcliente(Cliente* a, Reservacion* b)
{
	this->C = a;
	this->R = b;
}
Cliente* Habitacion::getcliente(){
	return C;
}
Reservacion* Habitacion::getreservacion(){
	return R;
}
int Habitacion::getnumreservacion(){
	return R->getnumreserv();
}
void Habitacion::anularCR()
{
	this->C = NULL;
	this->R = NULL;
}
int Habitacion::getidentificacionHabitacion(){return identificadorHabitacion;}
char Habitacion::getestado(){return estado;}
char Habitacion::getestandarHabitacion(){return estandarHabitacion;}
int Habitacion::getNumeroCamas() { return NumeroCamas; }
void Habitacion::setidentificacionHabitacion(int id){this->identificadorHabitacion = id;}
void Habitacion::setestado(char estado){this->estado = estado;}
void Habitacion::setestandarHabitacion(char x){this->estandarHabitacion = x;}
void Habitacion::setNumeroCamas(int NumeroCamas) { this->NumeroCamas = NumeroCamas; }
char Habitacion::RandomStandar() {
	int opcion;
	
	opcion = 1 + rand() % 3;
	
	switch (opcion) {
	case 1:
		estandarHabitacion = 'P'; break;
	case 2:
		estandarHabitacion = 'S'; break;
	case 3:
		estandarHabitacion = 'T'; break;
	}
	return NULL;
}
int Habitacion::RandomBed() {
	int opcion;
	
	opcion = 1 + rand() % 4;
	switch (opcion) {
	case 1:
		NumeroCamas = 2; break;
	case 2:
		NumeroCamas = 3; break;
	case 3:
		NumeroCamas = 5; break;
	case 4:
		NumeroCamas = 1; break;
	}
	return NULL;
}

string Habitacion::tostring() {
	stringstream x;
	x << "Identificacion de la habitacion: " << getidentificacionHabitacion() << endl
		<< "Estado de la habitacion: " << getestado() << endl
		<< "Clase: " << getestandarHabitacion() << endl
		<< "Numero de camas :" << getNumeroCamas() << endl
		<< "Costo habitacion sin todo incluido : $195  x 1,  $325 x 2, $455 x 3 y $520 x 4 " << endl
		<< "Costo habitacion con todo  incluido: $300 x adulto,  $200 x niño" << endl
		<< "Descuentos sin todo incluido" << endl
		<< "25%  en caso de ser una persona sola" << endl
		<< "20% si es el caso de dos personas" << endl
		<< "15% si son tres personas" << endl
		<< "10% si son más de tres" << endl
		<< "Recargos por clase" << endl << endl << endl
		<< "Primera Clase: 30%" << endl
		<< "Segunda Clase: 20%" << endl
		<< "Tercera Clase: 0%" << endl;
		if (R)
		{
			x << "----informacion de Reservacion---- " << endl
				<< R->tostring() << endl << endl << endl;


			if (estandarHabitacion == 'P') {
			x << "Total a pagar: " << R->getMontoRes() * 1.30<<endl;
			}if (estandarHabitacion == 'S') {
			x << "Total a pagar: " << R->getMontoRes() * 1.20<<endl;
			}if (estandarHabitacion == 'T') {
			x << "Total a pagar: " << R->getMontoRes()<<endl;
			}
		}
		if (C)
		{
			x<<"----Informacion del cliente"<<endl
				<<C->tostring()<<endl<<endl;
		}
		
		
		
	return x.str();
}