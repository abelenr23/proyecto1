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
		
	void insertar(int v){
		nodo *n=new nodo;
		n->marca=v;
		n->ant=n->prox=NULL;
		if(prim==NULL){
			prim=n;
			med=n;
			ult=n;
		}else if(prim==ult or espadas%2!=1){
			ult->prox=n;
			n->ant=ult;
			ult=n;
		}else{
			ult->prox=n;
			n->ant=ult;
			med=med->prox;
			ult=n;
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
		}else if(espadas==2 or espadas%2==1){
			ult=ult->ant;
			ult->prox=NULL;
			delete aux;
		}else{
			ult=ult->ant;
			ult->prox=NULL;
			med=med->ant;
			delete aux;
		}
		espadas--;
	}
	
	void reordenar(){
		nodo *aux=ult;
		if(espadas==1){
		}else if(espadas%2!=1){
			ult=med;
			aux->prox=prim;
			prim->ant=aux;
			prim=med->prox;
			med=aux;
			ult->prox=NULL;
			prim->ant=NULL;			
		}else{
			ult=med;
			aux->prox=prim;
			prim->ant=aux;
			prim=med->prox;
			med=aux->ant;
			ult->prox=NULL;
			prim->ant=NULL;
		}
	}
		
	void mostrar(){
		nodo *aux=prim;
		cout<<espadas<<endl;
		while(aux){
			cout<<aux->marca<<" ";
			aux=aux->prox;
		}
	}
};

int main(){
	string ins;
	int n, i, espada;
	lista coleccion;
	i=0;
	cin>>n;
	if(n<=1000000)
	{
		while(i<n){
			cin>>ins;
			if(ins=="insertar"){
				cin>>espada;
				coleccion.insertar(espada);
			}else if(ins=="tomar"){
				coleccion.tomar();
			}else if(ins=="reordenar"){
				coleccion.reordenar();
			}
			i++;
		}
		coleccion.mostrar();
	}
};
