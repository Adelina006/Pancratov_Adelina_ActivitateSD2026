#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//acces secvential pentru ca fiecare nod retine adresa urmatorului nod => sunt apestecate in memorie, nu e ca la vector 
//trebuie sa folositi fisierul masini.txt
//lista = tablou uni dim cu elem de acelasi tip , fara o zona de momeorie contigua , si retin adresa urmatorului nod 
//lista si nod 
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
typedef struct Nod Nod;

//creare structura pentru un nod dintr-o lista simplu inlantuita

struct Nod {
	Masina info;
	 Nod* next;
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
	m1.pret= atof(strtok(NULL, sep));
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

//trebuie sa ii dam adresa primului nod 
void adaugaMasinaInLista( Nod** lista,Masina masinaNoua) {
	//adauga la final in lista primita o noua masina pe care o primim ca parametru
	Nod* nou = malloc(sizeof(Nod));
	nou->info = masinaNoua;
	//facem aici shallow copy ca sa nu facem de 2 ori dezalocare 
	nou->next = NULL;
	//luam un pointer ajutator ca sa nu pierdem lista 
	Nod* aux = *lista;
	if ((*lista) != NULL)
	{
		while (aux->next != NULL) //daca puneam doar aux mergeam pana pe null, nu pana pe ultimul nod 
		{
			aux = aux->next;
		}
		aux->next = nou;
	}
	else
	{
		(*lista) = nou;
	}
}

void afisareListaMasini(Nod* cap) {
	//afiseaza toate elemente de tip masina din lista simplu inlantuita
	//prin apelarea functiei afisareMasina()
	while (cap != NULL) //ca sa trec prin toate 
	{
		afisareMasina(cap->info);
		cap = cap->next;
	}

}

void adaugaLaInceputInLista(/*lista de masini*/ Masina masinaNoua) {
	//adauga la inceputul listei o noua masina pe care o primim ca parametru
}

void* citireListaMasiniDinFisier(const char* numeFisier) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	//ATENTIE - la final inchidem fisierul/stream-ul
	//void* = un pointer la orice (si dam return oricum)
	FILE *file =fopen(numeFisier, "r");
	//mereu initializam pointerii
	Nod* lista = NULL;
	while (!feof(file))
	{
		Masina masinaNoua = citireMasinaDinFisier(file);
		adaugaMasinaInLista(&lista, masinaNoua);
	}
	fclose(file);
	return lista;
}

void dezalocareListaMasini(Nod** lista) {
	//sunt dezalocate toate masinile si lista de elemente
	Nod* head = *lista;
	Nod* next = NULL;
	while (head != NULL)
	{
		next = head->next;
		free(head->info.model);
		free(head->info.numeSofer);
		free(head);
		head = next;
	}
	*lista = NULL;
}

float calculeazaPretMediu(Nod * lista) {
	//calculeaza pretul mediu al masinilor din lista.
	float suma = 0;
	int nrMasini = 0;
	while (lista != NULL)
	{
		suma += lista->info.pret;
		nrMasini++;
		lista = lista->next;
	}
	if (nrMasini != 0)
	{
		return suma / nrMasini;
	}
	else
		return 0;
}

void stergeMasiniDinSeria(/*lista masini*/ char serieCautata) {
	//sterge toate masinile din lista care au seria primita ca parametru.
	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
}

float calculeazaPretulMasinilorUnuiSofer(/*lista masini*/ const char* numeSofer) {
	//calculeaza pretul tuturor masinilor unui sofer.
	return 0;
}

int main() {

	Nod* lista = citireListaMasiniDinFisier("masini.txt");
	afisareListaMasini(lista);
	//dezalocareListaMasini(& lista);
	//afisareListaMasini(lista);
	float pretMediu = calculeazaPretMediu(lista);
	printf("Pret mediu %5.2f", pretMediu);
	dezalocareListaMasini(&lista);
	return 0;
}