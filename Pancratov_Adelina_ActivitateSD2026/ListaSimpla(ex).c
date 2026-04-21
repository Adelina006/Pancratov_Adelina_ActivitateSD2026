//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//struct Produs {
//	int cod;
//	char* nume;
//	float pret;
//	float cantitate;
//	char* categorie;
//
//};
//
//typedef struct Produs Produs;
//typedef struct Nod Nod;
//struct Nod {
//	Produs produs;
//	Nod* next;
//};
//
//typedef struct Nod Nod;
//
//Produs citireProdusDinFisier(FILE* file)
//{
//	Produs produs;
//	char buffer[100];
//	char delimitatori[3] = ",\n";
//	fgets(buffer, 100, file);
//	produs.cod = atoi(strtok(buffer, delimitatori));
//	char* aux = strtok(NULL, delimitatori);
//	produs.nume = malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(produs.nume, aux);
//	produs.pret = atof(strtok(NULL, delimitatori));
//	produs.cantitate = atof(strtok(NULL, delimitatori));
//	aux = strtok(NULL, delimitatori);
//	produs.categorie = malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(produs.categorie, aux);
//	return produs;
//}
//
//void afisareProsus(Produs p)
//{
//	printf("\nCod: %d", p.cod);
//	printf("\nNume %s", p.nume);
//	printf("\nPret: %5.2f", p.pret);
//	printf("\nCantitate: %5.2f", p.cantitate);
//	printf("\nCategorie: %s", p.categorie);
//	printf("\n");
//}
//
//void afisareLista(Nod* cap)
//{
//	while (cap != NULL)
//	{
//		afisareProsus(cap->produs);
//		cap = cap->next;
//	}
//}
//
//void adaugareLaInceput(Nod** cap, Produs p)
//{
//	Nod* prd = malloc(sizeof(Nod));
//	prd->produs = p;
//	prd->next = (*cap);
//	(*cap) = prd;
//}
//
//void adaugareLaFinal(Nod** cap, Produs p)
//{
//	Nod* nou = malloc(sizeof(Nod));
//	nou->produs = p;
//	nou->next = NULL;
//	if ((*cap) ==NULL)
//	{
//		nou->next = (*cap);
//		(*cap) = nou;
//	}
//	else
//	{
//		Nod* aux = (*cap);
//		while (aux->next != NULL)
//		{
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//}
//
//void adaugareSortata(Nod** cap, Produs p)
//{
//	Nod* nou = malloc(sizeof(Nod));
//	nou->next = NULL;
//	nou->produs = p;
//	if ((*cap) == NULL || (*cap)->produs.cod > p.cod )
//	{
//		Nod* aux = (*cap);
//		(*cap) = nou;
//		nou->next = aux;
//
//	}
//	else
//	{
//		Nod* nod = (*cap);
//		while (nod->next != NULL && nod->next->produs.cod < p.cod )
//		{
//			nod = nod->next;
//		}
//		if (nod->next != NULL) {
//
//			nou->next = nod->next;
//			nod->next = nou;
//		}
//		else
//		{
//			nod->next = nou;
//		}
//		
//	}
//}
//
//
//
//Nod* CitireListaDinFisier(const char* numeFisier)
//{
//	FILE* file = fopen(numeFisier, "r");
//	Nod* lista = NULL;
//	while (!feof(file))
//	{
//		adaugareSortata(&lista, citireProdusDinFisier(file));
//	}
//
//	return lista;
//}
//
//void dezalocareLista(Nod** cap)
//{
//	Nod* p;
//	while ((*cap) != NULL)
//	{
//		p = (*cap);
//		(*cap) = (*cap)->next;
//		if (p->produs.nume != NULL)
//		{
//			free(p->produs.nume);
//		}
//		if (p->produs.categorie != NULL)
//		{
//			free(p->produs.categorie);
//		}
//		free(p);
//	}
//
//}
//
//float ClaculeazaPretMediu(Nod* cap)
//{
//	float suma = 0;
//	int k = 0;
//	while (cap != NULL)
//	{
//		suma += cap->produs.pret;
//		k++;
//		cap = cap->next;
//	}
//	if (k != 0)
//	{
//		return suma / k;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//float PretPeCategorie(Nod* cap, const char* categorie)
//{
//	float suma = 0;
//	while (cap != NULL)
//	{
//		if (strcmp(cap->produs.categorie, categorie) == 0)
//		{
//			suma += cap->produs.pret;
//		}
//		cap = cap->next;
//	}
//	return suma;
//}
//
//void StergereDupaCAtegorie(Nod** cap, const char* categorie)
//{
//	while ((*cap) && strcmp((*cap)->produs.categorie, categorie) == 0)
//	{
//		Nod* p = (*cap);
//		(*cap) = (*cap)->next;
//		if (p->produs.nume != NULL)
//		{
//			free(p->produs.nume);
//		}
//		if (p->produs.categorie != NULL)
//		{
//			free(p->produs.categorie);
//		}
//		free(p);
//	}
//	if ((*cap) != NULL)
//	{
//		Nod* curent = (*cap);
//		while (curent->next != NULL)
//		{
//			if (strcmp(curent->next->produs.categorie, categorie) == 0)
//			{
//				Nod* aux = curent->next;
//				curent->next = aux->next;
//
//				if (aux->produs.nume != NULL)
//				{
//					free(aux->produs.nume);
//				}
//				if (aux->produs.categorie != NULL)
//				{
//					free(aux->produs.categorie);
//				}
//				free(aux);
//			}
//			else
//			{
//				curent = curent->next;
//			}
//		}
//	
//	}
//	
//}
////filtreaza dupa stoc limitat
//Produs DeepCopy(Nod* cap)
//{
//	Produs copiat;
//	
//	(copiat).cod = cap->produs.cod;
//	(copiat).pret = cap->produs.pret;
//	(copiat).cantitate = cap->produs.cantitate;
//	(copiat).nume = malloc(sizeof(char) * (strlen(cap->produs.nume) + 1));
//	strcpy(copiat.nume, cap->produs.nume);
//	copiat.categorie = malloc(sizeof(char) * (strlen(cap->produs.categorie) + 1));
//	strcpy(copiat.categorie, cap->produs.categorie);
//
//	return copiat;
//}
//
//Nod* FiltreazaDupavaloareTotala(Nod* cap, float prag)
//{
//	Nod* lista = NULL;
//	while (cap)
//	{
//		if (cap->produs.pret * cap->produs.cantitate >= prag)
//		{
//			adaugareSortata(&lista, DeepCopy(cap));
//		}
//		cap = cap->next;
//	}
//	return lista;
//}
//
//void stergereDupaPret(Nod** cap, float pret)
//{
//	if ((*cap) == NULL)
//	{
//		return 0;
//	}
//	while ((*cap) && (*cap)->produs.pret < pret)
//	{
//		Nod* aux = (*cap);
//		(*cap) = (*cap)->next;
//		if (aux->produs.nume != NULL)
//		{
//			free(aux->produs.nume);
//		}
//		if (aux->produs.categorie != NULL)
//		{
//			free(aux->produs.categorie);
//		}
//		free(aux);
//	}
//	Nod* p = (*cap);
//	while (p->next)
//	{
//		if (p->next->produs.pret < pret)
//		{
//			Nod* aux = p->next;;
//			p->next = aux->next;
//			if (aux->produs.nume != NULL)
//			{
//				free(aux->produs.nume);
//			}
//			if (aux->produs.categorie != NULL)
//			{
//				free(aux->produs.categorie);
//			}
//			free(aux);
//		}
//		else
//		{
//			p = p->next;
//		}
//	}
//}
//
//int main()
//{
//	Nod* cap;
//	cap = CitireListaDinFisier("produse.txt");
//	afisareLista(cap);
//	//dezalocareLista(&cap);
//	float pret = ClaculeazaPretMediu(cap);
//	printf("\nPret Mediu = %5.2f", pret);
//	pret = PretPeCategorie(cap, "Bauturi");
//	printf("\nPret categorie = %5.2f", pret);
//	StergereDupaCAtegorie(&cap, "Electronice");
//	afisareLista(cap);
//	Nod* lista = FiltreazaDupavaloareTotala(cap, 500);
//	afisareLista(lista);
//	stergereDupaPret(&cap, 10);
//	afisareLista(cap);
//	dezalocareLista(&cap);
//	dezalocareLista(&lista);
//	return 0;
//}