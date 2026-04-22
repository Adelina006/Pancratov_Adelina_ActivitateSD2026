//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
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
//	if (masina.id == -1) {
//		printf("\n Masina nu exista");
//		return;
//	}
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//typedef struct Nod Nod;
//struct Nod {
//	Masina masina;
//	Nod* next;
//
//};
////functia de push la inceputul stivei
//void push(Nod** stiva, Masina m)
//{
//	Nod* nou = malloc(sizeof(Nod));
//	nou->masina = m;
//	nou->next = NULL;
//	if ((*stiva) == NULL)
//	{
//		(*stiva) = nou;
//	}
//	else
//	{
//		Nod* p = (*stiva);
//		(*stiva) = nou;
//		nou->next = p;
//	}
//}
//
//Masina pop(Nod** stiva)
//{
//	Masina m;
//	m.id = -1;
//	if (*stiva != NULL)
//	{
//		Nod* p = (*stiva);
//		(*stiva) = (*stiva)->next;
//		m = p->masina;
//		m.model = malloc(sizeof(char) * (strlen(p->masina.model) + 1));
//		strcpy(m.model, p->masina.model);
//		m.numeSofer = malloc(sizeof(char) * (strlen(p->masina.numeSofer) + 1));
//		strcpy(m.numeSofer, p->masina.numeSofer);
//	}
//	return m;
//}
//
//char emptyStack(Nod* stiva)
//{
//	return !stiva;
//}
//
//Nod* citireStackDInFisier(const char* fisier)
//{
//	FILE* file = fopen(fisier, "r");
//	Nod* stiva = NULL;
//	while (!feof(file))
//	{
//		push(&stiva, citireMasinaDinFisier(file));
//	}
//	fclose(file);
//	return stiva;
//}
//
//void afisare(Nod* stiva)
//{
//		while (stiva)
//		{
//			afisareMasina(stiva->masina);
//			stiva = stiva->next;
//		}
//	
//}
//
////coada= queue
//typedef struct NodDublu NodDublu;
//struct NodDublu
//{
//	Masina masina;
//	NodDublu* next;
//	NodDublu* prev;
//};
//
//typedef struct Queue Queue;
//struct Queue
//{
//	NodDublu* prim;
//	NodDublu* last;
//};
//
////adaugare la final
//void enqueue(Queue* coada, Masina m)
//{
//	NodDublu* nou = malloc(sizeof(Nod));
//	nou->masina = m;
//	nou->next = NULL;
//	nou->prev = NULL;
//	if ((*coada).last == NULL)
//	{
//		(*coada).prim = nou;
//	}
//	else
//	{
//		nou->prev = (*coada).last;
//		(*coada).last->next = nou;
//		
//	}
//
//	(*coada).last = nou;
//}
//
////scoatere la inceput
//Masina dequeue(Queue* coada)
//{
//	Masina m;
//	m.id = 1;
//	if ((*coada).prim == NULL)
//	{
//		return;
//	}
//	else
//	{
//		NodDublu* nod = (*coada).prim;
//		(*coada).prim = (*coada).prim->next;
//		(*coada).prim->prev = NULL;
//
//		return nod->masina;
//	}
//}
//
//
//int main()
//{
//	Nod* stiva = citireStackDInFisier("masini.txt");
//	afisare(stiva);
//	return 0;
//}
//
