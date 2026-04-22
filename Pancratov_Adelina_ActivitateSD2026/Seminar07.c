
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
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
//typedef struct Nod Nod;
//
//struct  Nod
//{
//	Masina masina;
//	Nod* next;
//};
//typedef struct HashTable HashTable;
//struct HashTable {
//	int dim;
//	Nod** tabela;
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
//void afisareListaMasini(Nod* cap)
//{
//	while (cap)
//	{
//		afisareMasina(cap->masina);
//		cap = cap->next;
//	}
//}
//
//void adaugareMasinaINlIsta(Nod* cap, Masina m) //adaugare intr o lista existenta
//{
//	Nod* p = cap;
//	while (p->next)
//	{
//		p = p->next;
//	}
//
//	Nod* nou = malloc(sizeof(Nod));
//	nou->masina = m;
//	nou->next = NULL;
//	p->next = nou;
//}
//
//HashTable Initializare(int dim)
//{
//	HashTable ht;
//	ht.dim = dim;
//	ht.tabela = (Nod**)malloc(sizeof(Nod*) * dim);
//	for (int i = 0; i < dim; i++)
//	{
//		ht.tabela[i] = NULL;
//	}
//
//	return ht;
//}
//
//int calculeazaHash(const char* nume, int dim)
//{
//	int suma = 0;
//	for (int i = 0; i < strlen(nume); i++)
//	{
//		suma += nume[i];
//	}
//	return suma % dim;
//}
//void inserareMasinaInHash(HashTable ht, Masina m)
//{
//	int pozitie = calculeazaHash(m.numeSofer, ht.dim);
//	if (ht.tabela[pozitie] == NULL)
//	{
//		ht.tabela[pozitie] = (Nod*)malloc(sizeof(Nod));
//		ht.tabela[pozitie]->masina = m;
//		ht.tabela[pozitie]->next = NULL;
//	}
//	else
//	{
//		adaugareMasinaINlIsta(ht.tabela[pozitie], m);
//	}
//
//}
//
//HashTable citireMasiniInHashDinFisier(const char* numeFisier, int dim)
//{
//	HashTable ht = Initializare(dim) ;
//	FILE* file = fopen(numeFisier, "r");
//	while (!feof(file))
//	{
//		Masina masina = citireMasinaDinFisier(file);
//		inserareMasinaInHash(ht, masina);
//	}
//	fclose(file);
//	return ht;
//}
//
//void afisareTabelaMasini(HashTable ht)
//{
//	for (int i = 0; i < ht.dim; i++)
//	{
//		if (ht.tabela[i] != NULL)
//		{
//			printf("\nMasinile de pe pozitia %d sunt:", i);
//			afisareListaMasini(ht.tabela[i]);
//		}
//		else
//		{
//			printf("\nPe pozitia %d nu avem masini", i);
//		}
//	}
//}
//
//void dezalocareListaMasini(Nod** cap)
//{
//	Nod* p = *cap;
//	while (p)
//	{
//		Nod* temp = p;
//		p = p->next;
//		if (temp->masina.model != NULL)
//		{
//			free(temp->masina.model);
//		}
//		if (temp->masina.numeSofer != NULL)
//		{
//			free(temp->masina.numeSofer);
//		}
//		free(temp);
//	}
//	(*cap) = NULL;
//}
//
//void dezalocareTabelaHash(HashTable* ht)
//{
//	for (int i = 0; i < ht->dim; i++)
//	{
//		dezalocareListaMasini(&(ht->tabela[i]));
//	}
//	free(ht->tabela);
//	ht->tabela = NULL;
//	ht->dim = 0;
//}
//float calculMediePeLista(Nod* cap)
//{
//	float suma = 0;
//	int contor = 0;
//	while (cap)
//	{
//		suma += cap->masina.pret;
//		contor++;
//		cap = cap->next;
//	}
//	if (contor > 0)
//	{
//		return suma / contor;
//	}
//}
//
//float* calculeazaPretulMediuPeCluster(HashTable ht, int* clustere)
//{
//	float* preturi = NULL;
//	*clustere = 0;
//	for (int i = 0; i < ht.dim; i++)
//	{
//		if (ht.tabela[i] != NULL)
//		{
//			(*clustere)++;
//		}
//	}
//	preturi = (float*)malloc((*clustere) * sizeof(float));
//	int contor = 0;
//	for (int i = 0; i < ht.dim; i++)
//	{
//		if (ht.tabela[i] != NULL)
//		{
//			preturi[contor] = calculMediePeLista(ht.tabela[i]);
//			contor++;
//		}
//	}
//	return preturi;
//}
//
//Masina getMasinaDinLista(Nod* cap, const char* nume)
//{
//	Masina m;
//	m.id = -1;
//	while (cap && strcmp(cap->masina.numeSofer, nume) != 0)
//	{
//		cap = cap->next;
//	}
//	if (cap != NULL)
//	{
//		m = cap->masina;
//		m.model = malloc((strlen(cap->masina.model) + 1) * sizeof(char));
//		strcpy(m.model, cap->masina.model);
//		m.numeSofer = malloc((strlen(cap->masina.numeSofer) + 1) * sizeof(char));
//		strcpy(m.numeSofer, cap->masina.numeSofer);
//	}
//
//	return m;
//	
//}
//
//Masina getMasinaDupaNumeSofer(HashTable ht, const char* numeCautat)
//{
//	Masina m;
//	m.id = -1;
//	int poz = calculeazaHash(numeCautat, ht.dim);
//	if (poz >= 0 && poz < ht.dim)
//	{
//		return getMasinaDinLista(ht.tabela[poz], numeCautat);
//	}
//
//	return m;
//}
//
//
//int main()
//{
//	HashTable ht = citireMasiniInHashDinFisier("masini.txt", 7);
//	afisareTabelaMasini(ht);
//	int nrclustere = 0;
//	float* preturi = calculeazaPretulMediuPeCluster(ht, &nrclustere);
//	for (int i = 0; i < nrclustere; i++)
//	{
//		printf("\n %.2f", preturi[i]);
//	}
//	Masina m = getMasinaDupaNumeSofer(ht, "Gigel");
//	printf("\nMasina: \n");
//	afisareMasina(m);
//	if (m.model != NULL)
//	{
//		free(m.model);
//	}
//	if (m.numeSofer != NULL)
//	{
//		free(m.numeSofer);
//	}
//	
//	dezalocareTabelaHash(&ht);
//	return 0;
//}
