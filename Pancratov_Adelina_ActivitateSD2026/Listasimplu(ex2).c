//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Pilot {
//	int id;
//	float greutate;
//	char* echipa;
//	int nrMedalii; //e relevant
//};
//typedef struct Pilot Pilot;
//typedef struct Nod Nod;
//struct Nod {
//	Pilot pilot;
//	Nod* next;
//};
//
//void adaugareDupaIdCrescator(Nod** cap, Pilot p)
//{
//	Nod* nou = malloc(sizeof(Nod));
//	nou->pilot = p;
//	nou->next = NULL;
//	if ((*cap) == NULL || (*cap)->pilot.id >= p.id)
//	{
//		Nod* aux = (*cap);
//		(*cap) = nou;
//		nou->next = aux;
//	}
//	else
//	{
//		Nod* curent = (*cap);
//		while (curent->next != NULL && curent->next->pilot.id < p.id)
//		{
//			curent = curent->next;
//		}
//		if (curent->next != NULL)
//		{
//			nou->next = curent->next;
//			curent->next = nou;
//		}
//		else
//		{
//			curent->next = nou;
//		}
//	}
//}
//
//Pilot CitirePilotdinFisier(FILE* file)
//{
//	char buffer[60];
//	char del[3] = ",\n";
//	Pilot p;
//	fgets(buffer, 60, file);
//	p.id = atoi(strtok(buffer, del));
//	p.greutate = atof(strtok(NULL, del));
//	char* aux = strtok(NULL, del);
//	p.echipa = malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(p.echipa, aux);
//	p.nrMedalii = atoi(strtok(NULL, del));
//
//	return p;
//}
//
//Nod* CitireListaFisier(const char* numeFisier)
//{
//	Nod* cap = NULL;
//	FILE* file = fopen(numeFisier, "r");
//	while (!feof(file))
//	{
//		adaugareDupaIdCrescator(&cap, CitirePilotdinFisier(file));
//	}
//
//	fclose(file);
//	return cap;
//}
//
//void afisarePilot(Pilot p)
//{
//	printf("\nId: %d\n", p.id);
//	printf("\nGreutate: %5.2f\n", p.greutate);
//	printf("\nEchipa: %s\n", p.echipa);
//	printf("\nNr medalii :  %d\n", p.nrMedalii);
//}
//
//void afisareLista(Nod* cap)
//{
//	while (cap!= NULL)
//	{
//		afisarePilot(cap->pilot);
//		cap = cap->next;
//	}
//}
//
//int contorPilotiPerEchipa(Nod* cap, const char* echipa)
//{
//	int k = 0;
//	if (cap == NULL)
//	{
//		return 0;
//	}
//	while (cap != NULL)
//	{
//		if (strcmp(cap->pilot.echipa, echipa) == 0)
//		{
//			k++;
//		}
//		cap = cap->next;
//	}
//
//	return k;
//}
//
//Pilot ReturneazaPilotupaId(Nod* cap, int id)
//{
//	Pilot p;
//	if (cap == NULL)
//	{
//		p.id = -1;
//		return p;
//	}
//	while (cap != NULL)
//	{
//		if (cap->pilot.id == id)
//		{
//			p.id = cap->pilot.id;
//			p.greutate = cap->pilot.greutate;
//			p.echipa = malloc(sizeof(char) * (strlen(cap->pilot.echipa) + 1));
//			strcpy(p.echipa, cap->pilot.echipa);
//			p.nrMedalii = cap->pilot.nrMedalii;
//		}
//
//		cap = cap->next;
//	}
//	return p;
//}
//
//void modificareNrMedalii(Nod* cap, const char* echipa)
//{
//	if (cap == NULL)
//	{
//		return 0;
//	}
//	while (cap != NULL)
//	{
//		if (strcmp(cap->pilot.echipa, echipa) == 0)
//		{
//			cap->pilot.nrMedalii -= 1;
//		}
//
//		cap = cap->next;
//	}
//}
//
//void dezalocarePilot(Pilot p)
//{
//	if (p.echipa != NULL)
//	{
//		free(p.echipa);
//	}
//
//}
//
//void dezalocareLista(Nod** cap)
//{
//	Nod* curent = (*cap);
//	while ((*cap) != NULL)
//	{
//		(*cap) = (*cap)->next;
//		dezalocarePilot(curent->pilot);
//		curent->next = NULL;
//		free(curent);
//		curent = (*cap);
//	}
//
//}
////inserare la inceput
//void InserareLaInceput(Nod** cap, Pilot p)
//{
//	Nod* nou = malloc(sizeof(Nod));
//	nou->pilot = p;
//	nou->next = NULL;
//	nou->next = (*cap);
//	(*cap) = nou;
//}
//
//void InserareLaSfarsit(Nod** cap, Pilot p)
//{
//	Nod* nou = malloc(sizeof(Nod));
//	nou->pilot = p;
//	nou->next = NULL;
//	if ((*cap) == NULL)
//	{
//		nou->next = (*cap);
//		(*cap) = nou;
//	}
//	else 
//	{
//		Nod* aux = (*cap);
//		while (aux->next != NULL)
//		{
//			aux = (*cap)->next;
//		}
//		aux->next = nou;
//	}
// }
//
//void inserareDupaId(Nod** cap, Pilot p)
//{
//	Nod* nou = malloc(sizeof(Nod));
//	nou->pilot = p;
//	nou->next = NULL;
//	if ((*cap) == NULL || (*cap)->pilot.id >= p.id)
//	{
//		Nod* aux = (*cap);
//		(*cap) = nou;
//		nou->next = aux;
//	}
//	else
//	{
//		Nod* curent = (*cap);
//		while (curent->next != NULL && curent->next->pilot.id < p.id)
//		{
//			curent = curent->next;
//		}
//		if (curent->next == NULL)
//		{
//			curent->next = nou;
//		}
//		else
//		{
//			nou->next = curent->next;
//			curent->next = nou;
//		}
//	}
//
//}
//
//void StergereDupaId(Nod** cap, int id)
//{
//	if ((*cap) == NULL)
//	{
//		return 0;
//	}
//	while ((*cap) != NULL && (*cap)->pilot.id == id)
//	{
//		Nod* aux = (*cap);
//		(*cap) = (*cap)->next;
//		if (aux->pilot.echipa != NULL)
//		{
//			free(aux->pilot.echipa);
//		}
//		free(aux);
//
//	}
//	if ((*cap != NULL))
//	{
//		Nod* curent = (*cap);
//		while (curent->next != NULL)
//		{
//			if (curent->next->pilot.id != id)
//			{
//				curent = curent->next;
//			}
//			else
//			{
//				Nod* aux = curent->next;
//				curent->next = aux->next;
//				if (aux->pilot.echipa != NULL)
//				{
//					free(aux->pilot.echipa);
//				}
//				free(aux);
//
//			}
//		}
//
//	}
//}
//
//int main()
//{
//	Nod* lista = CitireListaFisier("piloti.txt");
//	afisareLista(lista);
//	int cnt = 0;
//	cnt = contorPilotiPerEchipa(lista, "RedBull");
//	printf("\nExista %d piloti in grupa %s", cnt, "Redbull");
//	printf("\n\n");
//	Pilot p = ReturneazaPilotupaId(lista, 5);
//	afisarePilot(p);
//	modificareNrMedalii(lista, "RedBull");
//	afisareLista(lista);
//	dezalocareLista(&lista);
//	return 0;
//}