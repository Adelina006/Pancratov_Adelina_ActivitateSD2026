//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
////sau va creati un alt fisier cu alte date
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;  
//};
//typedef struct StructuraMasina Masina;
//
////creare structura pentru un nod dintr-o lista dublu inlantuita
//typedef struct Nod Nod;
////creare structura pentru Lista Dubla 
//struct Nod {
//	Masina info;
//	Nod* next;
//	Nod* prev;
//};
//typedef struct ListaDubla ListaDubla;
//
//struct ListaDubla
//{
//	Nod* prim;
//	Nod* ultim;
//	int nrNoduri;
//};
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//void afisareListaMasinaDeLaIncepu(ListaDubla lista)
//{
//	Nod* p = lista.prim;
//	while (p)
//	{
//		afisareMasina(p->info);
//		p = p->next;
//	}
//
//}
//
//void afisareListaMasinaDeLaFinal(ListaDubla lista)
//{
//	Nod* p = lista.ultim;
//	while (p)
//	{
//		afisareMasina(p->info);
//		p = p->prev;
//	}
//}
//
//void adaugareLaFinal(ListaDubla* lista, Masina masina)
//{
//	Nod* nou = malloc(sizeof(Nod));
//	nou->info = masina;
//	nou->next = NULL;
//	nou->prev = lista->ultim; 
//	if (lista->ultim != NULL)
//	{
//		lista->ultim->next = nou;
//	}
//	else
//	{
//		lista->prim = nou;
//	}
//	lista->ultim = nou;
//	lista->nrNoduri++;
//}
//
//void adaugareLaInceput(ListaDubla* lista, Masina masina)
//{
//	Nod* nou = malloc(sizeof(Nod));
//	nou->info = masina;
//	nou->next = lista->prim;
//	nou->prev = NULL;
//	if (lista->prim != NULL)
//	{
//		lista->prim->prev = nou;
//	}
//	else
//	{
//		lista->ultim = nou;
//
//	}
//	lista->prim = nou;
//	lista->nrNoduri++;
//}
//
//ListaDubla citireListaDublaDInFisier(const char* numeFisier)
//{
//	FILE* file = fopen(numeFisier, "r");
//	ListaDubla lista;
//	lista.prim = NULL;
//	lista.ultim = NULL;
//	lista.nrNoduri = 0;
//	while (!feof(file))
//	{
//		adaugareLaFinal(&lista, citireMasinaDinFisier(file));
//	}
//
//	fclose(file); 
//	return lista;
//
//}
//
//void dezalocare(ListaDubla* lista)
//{
//	Nod* p = lista->prim;
//	while (p)
//	{
//		Nod* aux = p;
//		p = p->next;
//		if (aux->info.model != NULL)
//		{
//			free(aux->info.model);
//		}
//		if (aux->info.numeSofer != NULL)
//		{
//			free(aux->info.numeSofer );
//		}
//		free(aux);
//	}
//	lista->prim = NULL;
//	lista->ultim = NULL;
//	lista->nrNoduri = 0;
//
//
//}
//
//float CalculeazaPretMediu(ListaDubla lista)
//{
//	if (lista.nrNoduri > 0)
//	{
//		float suma = 0;
//		Nod* p = lista.prim;
//		while (p)
//		{
//			suma += p->info.pret;
//			p = p->next;
//		}
//		return suma / lista.nrNoduri;
//	}
//	return 0;
//}
//
//void stergeMasinaDupaId(ListaDubla* lista, int id)
//{
//	if (lista->prim == NULL)
//	{
//		return;
//	}
//	Nod* p = lista->prim;
//	while (p != NULL &&p->info.id != id)
//	{
//		p = p->next;
//	}
//	if (p == NULL)
//	{
//		return;
//	}
//	if (p->prev == NULL) //daca e primul nod
//	{
//		
//			lista->prim = p->next;
//			if (lista->prim)
//			{
//				lista->prim->prev = NULL;
//			}
//	}
//	else
//	{
//		p->prev->next = p->next;
//	}
//	if (p->next != NULL)
//	{
//		p->next->prev = p->prev;
//	}
//	else
//	{
//		lista->ultim = p->prev;
//	}
//	if (p->info.model != NULL)
//	{
//		free(p->info.model);
//	}
//	if (p->info.numeSofer != NULL)
//	{
//		free(p->info.numeSofer);
//	}
//	free(p);
//	lista->nrNoduri--;
//}
//
//char* getNumeSoferMasinaScumpa(ListaDubla lista)
//{
//	if (lista.prim)
//	{
//		Nod* max = lista.prim;
//		Nod* p = lista.prim;
//		while (p)
//		{
//			if (max->info.pret < p->info.pret)
//			{
//				max = p;
//			}
//			p = p->next;
//		}
//		char* nume = malloc(sizeof(char) * (strlen(max->info.numeSofer) + 1));
//		strcpy(nume, max->info.numeSofer);
//		return nume;
//	}
//	else
//	{
//		return NULL;
//	}
//}
//
//int main()
//{
//	ListaDubla lista = citireListaDublaDInFisier("masini.txt");
//	//afisareListaMasinaDeLaIncepu(lista);
//	stergeMasinaDupaId(&lista, 6);
//	afisareListaMasinaDeLaFinal(lista);
//	//dezalocare(&lista);
//	float pret = CalculeazaPretMediu(lista);
//	printf("\nCalculeaza pret mediu %f", pret);
//	char* nume = getNumeSoferMasinaScumpa(lista);
//	printf("\n%s", nume);
//	if (nume != NULL)
//		free(nume);
//	return 0;
//}
