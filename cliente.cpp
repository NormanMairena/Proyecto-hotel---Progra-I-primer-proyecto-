#include "cliente.h"

Cliente::Cliente(string id, char x,string num, string numcuent, string nom)
{
	this->identificacion_Cliente = id;
	this->metodo_Pago = x;
	this->numeroTelefono = num;
	this->numeroCuenta = numcuent;
	this->nombre=nom;

}

Cliente::Cliente()
{
	identificacion_Cliente = "indef";
	metodo_Pago = 'C';
	numeroTelefono = "indef";
	numeroCuenta = "indef";
	nombre="indefinido";
}

Cliente::~Cliente(){}

string Cliente::getidentificacion_Cliente()
{
	return identificacion_Cliente;
}

string Cliente::getnumerotelefono()
{
	return numeroTelefono;
}

string Cliente::getnumeroCuenta()
{
	return numeroCuenta;
}

char Cliente::getmetodo_Pago()
{
	return metodo_Pago;
}

string Cliente::getnombre()
{
	return nombre;


}

void Cliente::setidentificacion_Cliente(string id)
{
	this->identificacion_Cliente = id;
}

void Cliente::setnumeroTelefono(string num)
{
	this->numeroTelefono = num;
}

void Cliente::setnumeroCuenta(string numcuenta)
{
	this->numeroCuenta = numcuenta;
}

void Cliente::setmetodo_Pago(char p)
{
	if (p == 'e' || p == 'c')
		this->metodo_Pago = p;
}

void Cliente::setnombre(string x)
{
	this->nombre=x;

}



string Cliente::tostring()
{
	stringstream x;
	x<<"Identificacion del cliente: "<<identificacion_Cliente<<endl
		<<"Numero de telefono :"<<numeroTelefono<<endl
		<<"Numero de cuenta: "<<numeroCuenta<<endl
		<<"Nombre :"<<nombre<<endl<<endl;
	return x.str();

}