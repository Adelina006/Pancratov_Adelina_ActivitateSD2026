#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

void afisareMasina(Masina masina) {
	//afiseaza toate atributele unei masini
	printf("\nid: %d ", masina.id);
	printf("\nnrUsi: %d ", masina.nrUsi);
	printf("\npret: %f ", masina.pret);
	printf("\nmodel: %s ", masina.model);
	printf("\nnumeSofer: %s", masina.numeSofer);
	printf("\nserie: %c \n", masina.serie);

}

void afisareVectorMasini(Masina* masini, int nrMasini) {
	//afiseaza toate elemente de tip masina din vector
	//prin apelarea functiei afisareMasina()

	for (int i = 0; i < nrMasini; i++)
	{
		afisareMasina(masini[i]);
	}
}

void adaugaMasinaInVector(Masina** masini, int * nrMasini, Masina masinaNoua) {
	//adauga in vectorul primit o noua masina pe care o primim ca parametru
	//ATENTIE - se modifica numarul de masini din vector;
	//nu avem referinta in C

	(*nrMasini)++;
	Masina* aux = malloc(sizeof(Masina) * (*nrMasini));
	//typedef = de acum peste tot unde e ,,Masina" o sa fie inlocuit cu structura Masina 
	for (int i = 0; i < (*nrMasini) - 1; i++)
	{
		//putem sa ne folosim de shallow copy pentru ca oricum stergem vectorul dupa
		aux[i] = (*masini)[i]; //shallow copy
		//deref+deplasare+deref+
		//op de index are prioritatea mai mare

	}
	aux[(*nrMasini) - 1] = masinaNoua; //shallow copy
	free(*masini);//avem grija sa nu stergem si elem din interior 
	*masini = aux;

}

Masina citireMasinaFisier(FILE* file) {
	//functia citeste o masina dintr-un strceam deja deschis
	//masina citita este returnata;
	char linie[50];
	fgets(linie, 50, file);
	char delimitator[3] = ",\n";
	Masina masina;
	masina.id = atoi(strtok(linie, delimitator));
	masina.nrUsi = atoi(strtok(NULL, delimitator)); //punem null deoarece strtok isi salveaza unde ramane
	masina.pret = atof(strtok(NULL, delimitator));
	char* modelAux = strtok(NULL, delimitator);
	masina.model = malloc((strlen(modelAux) + 1) * sizeof(char));
	strcpy(masina.model, modelAux);
	//stergem cu free doar elementele pe care le am alocat cu malloc

	char* numeSofer = strtok(NULL, delimitator);
	masina.numeSofer = malloc((strlen(numeSofer) + 1) * sizeof(char));
	strcpy(masina.numeSofer, numeSofer);

	char* serie = strtok(NULL, delimitator);
	masina.serie = serie[0];
	return masina;
}

Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaFisier()
	//numarul de masini este determinat prin numarul de citiri din fisier
	//ATENTIE - la final inchidem fisierul/stream-ul
}

void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
	//este dezalocat intreg vectorul de masini
}

int main() {
	FILE* file = fopen("masini.txt", "r");
	Masina masina = citireMasinaFisier(file);
	afisareMasina(masina);
	return 0;
}