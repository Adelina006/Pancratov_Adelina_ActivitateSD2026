#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pilot {
		int id;
		float greutate;
		char* echipa;
		int nrMedalii; 
	};
typedef struct Pilot Pilot;
typedef struct Nod Nod;
struct Nod
{
	Pilot pilot;
	Nod* next;
};

typedef struct HashTable HashTable;
struct HashTable {
	int dim;
	Nod** tabela;
};


Pilot CitirePilotdinFisier(FILE* file)
{
	char buffer[60];
	char del[3] = ",\n";
	Pilot p;
	fgets(buffer, 60, file);
	p.id = atoi(strtok(buffer, del));
	p.greutate = atof(strtok(NULL, del));
	char* aux = strtok(NULL, del);
	p.echipa = malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy(p.echipa, aux);
	p.nrMedalii = atoi(strtok(NULL, del));

	return p;
}

 void afisarePilot(Pilot p)
{
	printf("\nId: %d\n", p.id);
	printf("\nGreutate: %5.2f\n", p.greutate);
	printf("\nEchipa: %s\n", p.echipa);
	printf("\nNr medalii :  %d\n", p.nrMedalii);
}

 HashTable initializare(int dim)
 {
	 HashTable ht;
	 ht.dim = dim;
	 ht.tabela = (Nod**)malloc(sizeof(Nod*) * dim);
	 for (int i = 0; i < dim; i++)
	 {
		 ht.tabela[i] = NULL;
	 }

	 return ht;
 }

 int calculeazaHashCheie(const char* echipa, int dim)
 {
	 int suma = 0;
	 for (int i = 0; i < strlen(echipa); i++)
	 {
		 suma += echipa[i];
	 }
	 if (dim != 0)
	 {
		 return suma % dim;
	 }
	 else
	 {
		 return 0;
	 }
 }

 void afisareLista(Nod* cap)
 {
	 if(cap != 0)
	 while (cap)
	 {
		 afisarePilot(cap->pilot);
		 cap = cap->next;
	 }
 }


 void afisareHash(HashTable ht)
 {
	 if (ht.dim != 0)
	 {
		 for (int i = 0; i < ht.dim; i++)
		 {
			 if (ht.tabela[i] != NULL)
			 {
				 printf("\nMasinile de pe poz %d sunt\n", i);
				 afisareLista(ht.tabela[i]);
			 }
		 }
	 }
 }

 void adaugareInListaFinal(Nod** cap, Pilot pi)
 {
	 Nod* nou = malloc(sizeof(Nod));
	 nou->pilot = pi;
	 nou->next = NULL;
	 if ((*cap) == NULL)
	 {
		 (*cap) = nou;
	 }
	 else
	 {
		 Nod* p = (*cap);
		 while (p->next != NULL)
		 {
			 p = p->next;
		 }
		 p->next = nou;
	 }
 }

 void adaugarePilotInHash(HashTable ht, Pilot p)
 {
	 int poz= calculeazaHashCheie(p.echipa, ht.dim);
	 adaugareInListaFinal(&(ht.tabela[poz]), p);
 }

 HashTable citireDinFisier(int dim, const char* fisier)
 {
	 FILE* file = fopen(fisier, "r");
	 HashTable ht = initializare(dim);
	 while (!feof(file))
	 {
		 adaugarePilotInHash(ht, CitirePilotdinFisier(file));
	 }

	 return ht;
 }

 void dezalocareLista(Nod** cap)
 {
	
	 while ((*cap))
	 {
		 Nod* p = (*cap);
		 if (p->pilot.echipa != NULL)
		 {
			 free(p->pilot.echipa);
		 }
		 (*cap) = (*cap)->next;
		 free(p);

	 }
 }

 void dezalocareHash(HashTable* ht)
 {
	 for (int i = 0; i < ht->dim; i++)
	 {
		 dezalocareLista(&(ht->tabela[i]));
	 }
	 ht->dim = 0;
	 free(ht->tabela);
	 ht->tabela = NULL;
 }

 int main()
 {
	 HashTable ht = citireDinFisier(7, "piloti.txt");
	 afisareHash(ht);
	 dezalocareHash(&ht);
	 return 0;
 }