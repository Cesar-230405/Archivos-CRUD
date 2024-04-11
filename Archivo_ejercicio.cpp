#include<iostream>
using namespace std;
const char *Nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void Leer();
void Crear();
void Borrar();
void Actualizar();
main(){
	Leer();
	Crear();
	Borrar();
	Actualizar();
	system("pause");
}
void Leer(){
	system("cls");
	FILE* archivo = fopen(Nombre_archivo, "rb");
	if(!archivo){
		archivo = fopen(Nombre_archivo, "w+b");
	}
	Estudiante estudiante;
	int id=0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"______________________________________"<<endl;
	cout<<"ID"<<"|"<<"Codigo"<<"|"<<"        Nombres        "<<"|"<<"        Apellidos        "<<"|"<<"        Telefono        "<<endl;
	do{	
	    cout<<id<<"   |  "<<estudiante.codigo<<"   |   "<<estudiante.nombres<<"   |   "<<estudiante.apellidos<<"    |    "<<estudiante.telefono<<endl;
	    fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
}
void Crear(){
	FILE* archivo = fopen(Nombre_archivo, "a+b");
	char res;
	Estudiante estudiante;
	do{
		fflush(stdin);
		
		cout<<"Ingrese Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese los nombres: ";
		cin.getline(estudiante.nombres, 50);
		
		cout<<"Ingrese los apellidos: ";
		cin.getline(estudiante.apellidos, 50);
		
		cout<<"Ingrese el telefono: ";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Desea ingresar otro estudiante (S/N): ";
		cin>>res;
		system("cls");
	}while(res == 's'||res =='S');
	fclose(archivo);
	Leer();
}
void Actualizar(){
	
	FILE* archivo = fopen(Nombre_archivo, "r+b");
	Estudiante estudiante;
	int id=0;
	cout<<"Ingrese el ID que desea actualizar: ";
	cin>>id;
	    fseek(archivo,id * sizeof(Estudiante), SEEK_SET);
		fflush(stdin);
		
		cout<<"Ingrese Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese los nombres: ";
		cin.getline(estudiante.nombres, 50);
		
		cout<<"Ingrese los apellidos: ";
		cin.getline(estudiante.apellidos, 50);
		
		cout<<"Ingrese el telefono: ";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		system("cls");
	
	fclose(archivo);
	Leer();
}
void Borrar(){
	const char *Nombre_archivo_temp = "archivo_temp.dat";
	FILE* archivo_temp = fopen(Nombre_archivo_temp, "w+b");
	FILE* archivo = fopen(Nombre_archivo, "rb");
	Estudiante estudiante;
	int id=0, id_n=0;
	cout<<"Ingrese el ID a eliminar: ";
	cin>>id;
	while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
		if(id_n != id){
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
		}
		id_n++;
	}
	fclose(archivo);
	fclose(archivo_temp);
	
	archivo_temp = fopen(Nombre_archivo_temp, "rb");
	archivo = fopen(Nombre_archivo, "w+b");
	
	while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	}
	fclose(archivo);
	fclose(archivo_temp);
	Leer();
}