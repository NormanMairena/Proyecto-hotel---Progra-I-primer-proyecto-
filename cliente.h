#pragma once
#include<iostream>
#include <sstream>
#include <string>
using namespace std;
class Cliente {
private:
	//Atributos clase Cliente
	string identificacion_Cliente;
	char metodo_Pago;
	string numeroTelefono;
	string numeroCuenta;
	string nombre;
public:
	//Constructor
	Cliente(string, char, string, string, string);
	Cliente();
	//Destrucutor
	~Cliente();
	//Metodos set y get
	string getidentificacion_Cliente();
	string getnumerotelefono();
	string getnumeroCuenta();
	char getmetodo_Pago();
	string getnombre();//
	void setidentificacion_Cliente(string);
	void setnumeroTelefono(string);
	void setnumeroCuenta(string);
	void setmetodo_Pago(char);
	void setnombre(string);//
	//tostring
	string tostring();

};

