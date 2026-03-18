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

//creare structura pentru un nod dintr-o lista dublu inlantuita
typedef struct Nod Nod;
//creare structura pentru Lista Dubla 
struct Nod {
	Masina info;
	Nod* next;
	Nod* prev;
};
typedef struct ListaDubla ListaDubla;

struct ListaDubla
{
	Nod* prim;
	Nod* ultim;
};

Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

void afisareListaMasini(ListaDubla lista) { //putem sa trimitem prin pointer ca sa ocupe doar cat un pointer, nu 2
	//afiseaza toate elemente de tip masina din lista dublu inlantuita
	//prin apelarea functiei afisareMasina()
	Nod* p = lista.prim;
	while (p)
	{
		afisareMasina(p->info);
		p = p->next;
	}


}

void afisareInversaListaMasini(ListaDubla lista) { //putem sa trimitem prin pointer ca sa ocupe doar cat un pointer, nu 2
	//afiseaza toate elemente de tip masina din lista dublu inlantuita
	//prin apelarea functiei afisareMasina()
	Nod* p = lista.ultim;
	while (p)
	{
		afisareMasina(p->info);
		p = p->prev;
	}


}

void adaugaMasinaInLista(ListaDubla * ld , Masina masinaNoua) { 
	//adauga la final in lista primita o noua masina pe care o primim ca parametru

	Nod* nou = malloc(sizeof(Nod));
	nou->info = masinaNoua;
	nou->next = NULL;
	nou->prev = ld->ultim;
	if (ld->ultim  != NULL)
	{
		ld->ultim->next = nou;//daca exista lista 
		
	}
	else
	{
		ld->prim = nou;
	}
	ld->ultim = nou;
}

void adaugaLaInceputInLista(ListaDubla * ld, Masina masinaNoua) {
	//adauga la inceputul listei dublu inlantuite o noua masina pe care o primim ca parametru

	Nod* nou = malloc(sizeof(Nod));
	nou->info = masinaNoua;
	nou->next = ld->prim;
	nou->prev = NULL;
	if (ld->prim)
	{
		ld->prim->prev = nou;//daca exista lista 

	}
	else
	{
		ld->ultim = nou;
	}
	ld->prim = nou;

}

ListaDubla citireLDMasiniDinFisier(const char* numeFisier) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	//ATENTIE - la final inchidem fisierul/stream-ul

	FILE* f = fopen(numeFisier, "r");
	if (f)
	{
		ListaDubla ld;
		ld.prim = ld.ultim = NULL;
		while (!feof(f))
		{
			adaugaMasinaInLista(&ld, citireMasinaDinFisier(f));
		}
		fclose(f);
		return ld;
	}
	
   //aici se face o copie din functia citire in main a obiectului

}

void dezalocareLDMasini(ListaDubla *ld) {
	//sunt dezalocate toate masinile si lista dublu inlantuita de elemente
	while (ld->prim && ld->prim->next)
	{
		free(ld->prim->info.numeSofer);
		free(ld->prim->info.model);
		ld->prim = ld->prim->next;
		free(ld->prim->prev);

	}
	if (ld->prim)
	{

		free(ld->prim->info.numeSofer);
		free(ld->prim->info.model);
	free(ld->prim);
	}

	ld->prim = ld->ultim = NULL;
}

float calculeazaPretMediu(ListaDubla lista) {
	//calculeaza pretul mediu al masinilor din lista.
	if (lista.prim != NULL && lista.ultim != NULL) {
		Nod* p = lista.prim;
		float suma = 0;
		int k = 0;
		while (p)
		{
			suma += p->info.pret;
			k++;
			p = p->next;
		}
		return suma / k;
	}
	else
		return 0;

}

void stergeMasinaDupaID(ListaDubla *ld, int id) {
	//sterge masina cu id-ul primit.
	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
	if (ld->prim && ld->prim->info.id == id)
	{
		free(ld->prim->info.model);
		free(ld->prim->info.numeSofer);
		ld->prim = ld->prim->next;
		if (ld->prim)
		{
			free(ld->prim->prev);
		}
		else
		{
			free(ld->ultim);
			ld->ultim = NULL;
		}
		return ;
	}
	Nod* p = ld->prim;
	while (p && p->info.id != id)
	{
		p = p->next;
	}
	if (p)
	{
		if (p->prev)
		{
			p->prev->next = p->next;

		}
		if (p->next)
		{
			p->next->prev = p->prev;
		}
		else
		{
			p->prev->next = NULL;
			ld->ultim = p->prev;
		}
		free(p->info.model);
		free(p->info.numeSofer);
		free(p);
	}

}

char* getNumeSoferMasinaScumpa(ListaDubla ld) {
	//cauta masina cea mai scumpa si 
	//returneaza numele soferului acestei maasini.
	{
		if (ld.prim == NULL && ld.ultim == NULL) return NULL;
		float max = ld.prim->info.pret;
		ld.prim = ld.prim->next;
		char numeSoferMaxim[100]; //poti sa faci cu un pointer care duce la nume si doar la sfarsit aloci memorie 
		strcpy(numeSoferMaxim, ld.prim->info.numeSofer);
		while (ld.prim) {
			if (ld.prim->info.pret > max) {
				max = ld.prim->info.pret;
				strcpy(numeSoferMaxim, ld.prim->info.numeSofer);
			}
			ld.prim = ld.prim->next;
		}
		return numeSoferMaxim;
	}

	return NULL;
}

int main() {

	ListaDubla lista;
	lista.prim = NULL;
	lista.ultim = NULL;
	ListaDubla ld = citireLDMasiniDinFisier("masini.txt");
	afisareListaMasini(ld);
	float suma = calculeazaPretMediu(ld);
	printf("\n %f", suma);

	stergeMasinaDupaID(&ld, 6);
	printf("Masini dupa stergere");
	afisareListaMasini(ld);
	return 0;
}