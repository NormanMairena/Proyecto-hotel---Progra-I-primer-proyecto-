#include "Reservacion.h"
//precios sin Todo Incluido
static int P1NTI = 150;
static int P2NTI = 250;
static int P3NTI = 350;
static int P4NTI = 400;

//Precios todo incluido
static int PrecioMayor = 300;
static int PrecioMenosr = 200;

Reservacion::Reservacion(int numreserv,int adultos, int ninnos, int entrada, int salida, int dias,bool todoinc){ 
	this->numAdultos = adultos;
	this->numNinnos = ninnos;
	this->entrada = entrada;
	this->numreserv = numreserv;
	this->todoIncluido = todoinc;
	this->salida = salida;
	this->dias = dias;
	this->MontoReservacion = 0;
	if (todoIncluido)
	{
		calcularPreciosContodo();
	}
	else
	{
		calcularPreciosSintodo();
	}
	
}
Reservacion::Reservacion(){
	numAdultos = 0;
	numNinnos = 0;
	entrada = 1;
	salida = 2;
	MontoReservacion = 0;
	todoIncluido = false;
	numreserv = 1;
	dias = 1;
}
Reservacion::~Reservacion(){}
int Reservacion::getnumreserv(){return numreserv;}
int Reservacion::getnumAdultos(){return numAdultos;}
int Reservacion::getnumNinnos(){return numNinnos;}
int Reservacion::getdias()
{
	return dias;
}
int Reservacion::getentrada()
{
	return entrada;
}
int Reservacion::getsalida()
{
	return salida;
}
float Reservacion::getMontoRes(){return MontoReservacion;}
bool Reservacion::gettodoIncluido(){return todoIncluido;}
string Reservacion::tiquete()
{
	stringstream s;
	if (todoIncluido)
	{
		s << "Precio diario de adultos: " << "( 300 x " << getnumAdultos() << " adulto)------" <<300*getnumAdultos() <<endl;
		s << "Precio diario de ninnos: " << "( 200 x " << getnumNinnos() << " ninno)------" <<200*getnumAdultos()<<endl ;
		s << "precio diario:--- " << (300 * numAdultos) + (200 * numNinnos) << endl << endl;
		s << "Numero de dias:--- " << getdias() << endl;
		s << "Total:---" << calcularPreciosContodo();

	}
	else
	{
		s << "Personas---" << numNinnos + numAdultos << endl;
		s << "cantidad de dias---" << getdias() << endl;
		s << "Total---" << calcularPreciosSintodo() << endl;
	}
	


	return s.str();
}
void Reservacion::setnumreserv(int x)
{
	this->numreserv;
}
void Reservacion::setnumAdultos(int num){this->numAdultos = num;}
void Reservacion::setnumNinnos(int num){
	if (numAdultos >= 1)
		this->numNinnos = num;
}
void Reservacion::setdias(int x)
{
	this->dias = x;
}
void Reservacion::setentrada(int x)
{
	this->entrada = x;
}
void Reservacion::setsalida(int x)
{
	this->salida = x;
}
void Reservacion::setmontoRes(float monto){this->MontoReservacion = monto;}
void Reservacion::settodoIncluido(bool test){this->todoIncluido = test;}
string Reservacion::tostring() {
	stringstream x;
	x << "Numero de reservacion :" << numreserv << endl
		<< "Numero de niños: " << numNinnos << endl
		<< "Numero DE adultos: " << numAdultos << endl
		<<"Dias de estancia" <<dias<< endl;
	if (todoIncluido)
	{
		x << "Monto de la reservacion: " << calcularPreciosContodo()<<endl;

	}
	else
	{
		x<<"Monto de la reservacion: " << calcularPreciosSintodo()<<endl;
	}

	return x.str();
}
float Reservacion::calcularPreciosSintodo() {
	
	int cantidadPersonas =numAdultos+numNinnos;
	if (!todoIncluido) {
		if (cantidadPersonas == 1) {
			MontoReservacion=dias* P1NTI;
			if (entrada >= 18)
				MontoReservacion = MontoReservacion - MontoReservacion * 0.25;

		}
		else if (cantidadPersonas == 2) {
			MontoReservacion=dias* P2NTI;
			if(entrada>=18)
				MontoReservacion = MontoReservacion - MontoReservacion * 0.20;
		}
		else if (cantidadPersonas == 3) {
			MontoReservacion=dias* P3NTI;
			if(entrada>=18)
				MontoReservacion = MontoReservacion - MontoReservacion * 0.15;
			
		}
		else if (cantidadPersonas==4) {
			MontoReservacion=dias* P4NTI;
			if (entrada>18)
				MontoReservacion = MontoReservacion - MontoReservacion * 0.10; 
		}

	}
	
	return MontoReservacion;

}

float Reservacion::calcularPreciosContodo()
{
	
	if (todoIncluido)
	{
		MontoReservacion = (numAdultos * PrecioMayor) + (numNinnos * PrecioMenosr);
	}


	return MontoReservacion;
}
