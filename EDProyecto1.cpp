#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class nodo{
	public:
	int marca;
	nodo *prox;
	nodo *ant;	
};

class lista{
	private:
	nodo *prim, *med, *ult;
	int espadas;
	
	public:
	lista(){
		espadas=0;
		prim=NULL;
		med=NULL;
		ult=NULL;
	}
	
	void eliminarLista(){
		nodo *aux=NULL;
		while(prim!=NULL){
			aux=prim;
			prim=prim->prox;
			delete aux;
		}
		med=NULL;
		ult=NULL;
		espadas=0;
	}
	
	void insertar(int v){
		nodo *n=new nodo;
		n->marca=v;
		n->ant=n->prox=NULL;
		if(prim==NULL){
			prim=n;
			med=n;
			ult=n;
		}else if(prim==ult){
			prim->prox=n;
			n->ant=prim;
			ult=n;
		}else{
			if(espadas%2!=1){
				ult->prox=n;
				n->ant=ult;
				ult=n;
			}else{
				ult->prox=n;
				n->ant=ult;
				med=med->prox;
				ult=n;
			}
		}
		espadas++;
	}
	
	void tomar(){
		nodo *aux=ult;
		if(prim==ult){
			prim=NULL;
			med=NULL;
			ult=NULL;
			delete aux;
		}else{
			ult=ult->ant;
			ult->prox=NULL;
			delete aux;
		}
		espadas--;
	}
		
	void mostrar(){
		cout<<"primero "<<prim->marca<<endl;
		cout<<"medio "<<med->marca<<endl;
		cout<<"ultimo "<<ult->marca<<endl;
	}
};

int main(){
	string ins;
	int espada, toma;
	espada=-1;
	toma =0;
	lista coleccion;
	do{
		cin>>ins;
		if(ins=="insertar"){
			cin>>espada;
			coleccion.insertar(espada);
		}else if(ins=="tomar"){
			coleccion.tomar();
			toma=toma+1;
		}else if(ins!="insertar" and ins!="tomar" and ins!="terminado"){
			cout<<"escribir bien"<<endl;
		}
	}while(ins!="terminado");
	if(espada!=-1 or toma>1){
		coleccion.mostrar();
	}
	coleccion.eliminarLista();
};










