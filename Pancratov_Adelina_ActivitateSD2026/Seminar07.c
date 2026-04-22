//////vector de  liste 
////
////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////#include <stdlib.h>
////#include <string.h>
////
//////trebuie sa folositi fisierul masini.txt
//////sau va creati un alt fisier cu alte date
////
////struct StructuraMasina {
////	int id;
////	int nrUsi;
////	float pret;
////	char* model;
////	char* numeSofer;
////	unsigned char serie;
////};
////typedef struct StructuraMasina Masina;
////typedef struct Nod Nod;
//////creare structura pentru un nod dintr-o lista simplu inlantuita
////struct  Nod
////{
////	Masina masina;
////	Nod* next;
////};
////
////
//////creare structura pentru tabela de dispersie
////// aceasta este un vector de liste
////struct HashTable {
////	int dim;
////	Nod** head;
////};
////typedef struct HashTable HashTable;
////
////Masina citireMasinaDinFisier(FILE* file) {
////	char buffer[100];
////	char sep[3] = ",\n";
////	fgets(buffer, 100, file);
////	char* aux;
////	Masina m1;
////	aux = strtok(buffer, sep);
////	m1.id = atoi(aux);
////	m1.nrUsi = atoi(strtok(NULL, sep));
////	m1.pret = atof(strtok(NULL, sep));
////	aux = strtok(NULL, sep);
////	m1.model = malloc(strlen(aux) + 1);
////	strcpy_s(m1.model, strlen(aux) + 1, aux);
////
////	aux = strtok(NULL, sep);
////	m1.numeSofer = malloc(strlen(aux) + 1);
////	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
////
////	m1.serie = *strtok(NULL, sep);
////	return m1;
////}
////
////void afisareMasina(Masina masina) {
////	printf("Id: %d\n", masina.id);
////	printf("Nr. usi : %d\n", masina.nrUsi);
////	printf("Pret: %.2f\n", masina.pret);
////	printf("Model: %s\n", masina.model);
////	printf("Nume sofer: %s\n", masina.numeSofer);
////	printf("Serie: %c\n\n", masina.serie);
////}
////
////void afisareListaMasini(Nod* nod) {
////	//afiseaza toate elemente de tip masina din lista dublu inlantuita
////	//prin apelarea functiei afisareMasina()
////	while (nod)
////	{
////		afisareMasina(nod->masina);
////		nod = nod->next;
////	}
////
////}
////
////void adaugaMasinaInLista(Nod** nod, Masina masinaNoua) {
////	//adauga la final in lista primita o noua masina pe care o primim ca parametru
////	Nod* nou = (Nod*)malloc(sizeof(Nod));
////	nou->masina = masinaNoua;
////	nou->next = NULL;
////
////	if (!*nod)
////	{
////		*nod = nou;
////	}
////	else
////	{
////		Nod* aux = *nod;
////		while (aux->next)
////		{
////			aux = aux->next;
////		}
////		aux->next = nou;
////	}
////
////
////}
////
////
////HashTable initializareHashTable(int dimensiune) {
////	HashTable ht;
////	//initializeaza vectorul de liste si seteaza fiecare lista ca fiind NULL;
////	ht.dim = dimensiune;
////	ht.head = malloc(sizeof(Nod*) * ht.dim); //mi am alocat spatiu ptr vectorul de pointeri 
////	for (int i = 0; i < ht.dim; i++)
////	{
////		ht.head[i] = NULL;
////	}
////	return ht;
////}
////
////int calculeazaHash(int id, int dimensiune) {
////	// este calculat hash-ul in functie de dimensiunea tabelei si un atribut al masinii
////	return (id * 31) % dimensiune;
////
////}
////
////void inserareMasinaInTabela(HashTable ht, Masina masina) {
////	//este folosit mecanismul CHAINING
////	//este determinata pozitia si se realizeaza inserarea pe pozitia respectiva
////	int hash = calculeazaHash(masina.id, ht.dim);
////	if (ht.head[hash] != NULL)
////	{
////		adaugaMasinaInLista(&ht.head[hash], masina);
////
////		return;
////	}
////	Nod* nod = malloc(sizeof(Nod));
////	nod->masina = masina;
////	nod->next = NULL;
////
////	ht.head[hash] = nod;
////
////	//puteam folosi adaugainlista
////
////
////}
////
////HashTable citireMasiniDinFisier(const char* numeFisier) {
////	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
////	//prin apelul repetat al functiei citireMasinaDinFisier()
////	// aceste masini sunt inserate intr-o tabela de dispersie initializata aici
////	//ATENTIE - la final inchidem fisierul/stream-ul
////
////	FILE* f = fopen(numeFisier, "r");
////	HashTable ht = initializareHashTable(5);
////	while (!feof(f))
////	{
////		Masina masina = citireMasinaDinFisier(f);
////		inserareMasinaInTabela(ht, masina);
////	}
////	fclose(f);
////
////	return ht;
////
////
////}
////
////void afisareTabelaDeMasini(HashTable ht) {
////	//sunt afisate toate masinile cu evidentierea clusterelor realizate
////	for (int i = 0; i < ht.dim; i++)
////	{
////		if(ht.head[i] != NULL)
////		{
////			printf("Cluster %d", i + 1);
////			
////			Nod* aux = ht.head[i];
////			afisareListaMasini(aux);
////
////			printf("=======================================\n");
////		}
////	}
////
////}
////
////void dezalocareTabelaDeMasini(HashTable *ht) {
////	//sunt dezalocate toate masinile din tabela de dispersie
////	for (int i = 0; i < ht->dim; i++)
////	{
////		if (ht->head[i] != NULL)
////		{
////			Nod* p = ht->head[i];
////			Nod* next = NULL;
////
////			while (p != NULL)
////			{
////				free(p->masina.model);
////				free(p->masina.numeSofer);
////
////				next = p->next;
////				free(p);
////				p = next;
////			}
////		}
////
////	}
////	free(ht->head);
////	ht->dim = 0;
////	ht->head = NULL;
////
////
////}
////
////float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
////	//calculeaza pretul mediu al masinilor din fiecare cluster.
////	//trebuie sa returnam un vector cu valorile medii per cluster.
////	//lungimea vectorului este data de numarul de clustere care contin masini
////
////	int nr = 0;
////	for (int i  = 0; i < ht.dim; i++)
////	{
////		if (ht.head[i] != NULL)
////		{
////			nr++;
////		}
////	}
////
////	float* mediePerCluster = malloc(nr * sizeof(float));
////	int j = 0;
////	for (int i = 0; i < ht.dim; i++)
////	{
////		if (ht.head[i] != NULL)
////		{
////			int nrNoduri = 0;
////			float  sum = 0;
////
////			Nod* aux = ht.head[i];
////			while (aux != NULL)
////			{
////				nrNoduri++;
////				sum += aux->masina.pret;
////
////				aux = aux->next;
////			}
////
////			mediePerCluster[j++] = sum / nrNoduri;
////		}
////	}
////
////	return mediePerCluster;
////}
////
////Masina getMasinaById(HashTable ht, int id) {
////	Masina m;
////	m.id = -1;
////	//cauta masina dupa valoarea atributului cheie folosit in calcularea hash-ului
////	//trebuie sa modificam numele functiei 
////	int hash = calculeazaHash(id, ht.dim);
////	//trebuie sa mai verificam daca hash ul e intre 0 si hash
////	Nod* aux = ht.head[hash];
////	while (aux != NULL)
////	{
////		if (aux->masina.id == id)
////		{
////			m = aux->masina;
////			m.model = malloc((strlen(aux->masina.model) + 1) * sizeof(char));
////			strcpy(m.model, aux->masina.numeSofer);
////
////			
////		}
////
////		aux = aux->next;
////	}
////
////	return m;
////}
////
////int main() {
////
////	HashTable ht = citireMasiniDinFisier("masini.txt");
////	//afisareTabelaDeMasini(ht);
////
////	afisareMasina(getMasinaById(ht, 9));
////
////	dezalocareTabelaDeMasini(&ht);
////	return 0;
////}
//
//
//
//
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
