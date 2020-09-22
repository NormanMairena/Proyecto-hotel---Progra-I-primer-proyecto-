#pragma once
#include<iostream>
#include <sstream>
#include <string>
using namespace std;
class Reservacion
{
private:
	int numreserv;
	int numAdultos;
	int numNinnos;
	int entrada;//hora
	int salida;//hora
	int dias;
	float MontoReservacion;
	bool todoIncluido;
public:
	Reservacion(int, int, int,int,int,int, bool);
	Reservacion();
	~Reservacion();
	//gets
	int getnumreserv();
	int getnumAdultos();
	int getnumNinnos();
	int getdias();
	int getentrada();
	int getsalida();
	float getMontoRes();
	bool gettodoIncluido();
	string tiquete();
	//sets
	void setnumreserv(int);
	void setnumAdultos(int);
	void setnumNinnos(int);
	void setdias(int);
	void setentrada(int);
	void setsalida(int);
	void setmontoRes(float);
	void settodoIncluido(bool);
	float calcularPreciosSintodo();
	float calcularPreciosContodo();
	string tostring();


};


