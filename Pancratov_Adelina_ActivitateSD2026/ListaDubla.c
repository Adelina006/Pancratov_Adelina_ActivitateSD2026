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
//	Nod* prev;
//};
//
//typedef struct ListaDubla ListaDubla;
//struct ListaDubla
//{
//	Nod* first;
//	Nod* last;
//	int nrNoduri;
//};
////sterge un pilot dupa ceva->sterge mai multi piloti dupa ceva
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
// void afisarePilot(Pilot p)
//{
//	printf("\nId: %d\n", p.id);
//	printf("\nGreutate: %5.2f\n", p.greutate);
//	printf("\nEchipa: %s\n", p.echipa);
//	printf("\nNr medalii :  %d\n", p.nrMedalii);
//}
//
// void afisareDeLaInceput(ListaDubla lista)
// {
//	 if (lista.first == NULL)
//	 {
//		 return;
//	 }
//	 Nod* p = lista.first;
//	 while (p)
//	 {
//		 afisarePilot(p->pilot);
//		 p = p->next;
//	 }
// }
//
// void afisareDELaFinal(ListaDubla lista)
// {
//	 if (lista.last == NULL)
//	 {
//		 return;
//	 }
//	 Nod* p = lista.last;
//	 while (p)
//	 {
//		 afisarePilot(p->pilot);
//		 p = p->prev;
//	 }
// }
//
// void adaugareLaFinal(ListaDubla* lista, Pilot p)
// {
//	 Nod* nou = malloc(sizeof(Nod));
//	 nou->pilot = p;
//	 nou->next = NULL;
//	 nou->prev = NULL;
//	 if (lista->last != NULL)
//	 {
//		 nou->prev = lista->last;
//		 lista->last->next = nou;
//		 
//	 }
//	 else
//	 {
//		 lista->first = nou;
//	 }
//	 lista->last = nou;
//	 lista->nrNoduri++;
//
// }
//
// void adaugareLaInceput(ListaDubla* lista, Pilot p)
// {
//	 Nod* nou = malloc(sizeof(Nod));
//	 nou->pilot = p;
//	 nou->next = NULL;
//	 nou->prev = NULL;
//	 if (lista->first != NULL)
//	 {
//		 nou->next = lista->first;
//		 lista->first->prev = nou;
//	 }
//	 else
//	 {
//		 lista->last = nou;
//	 }
//	 lista ->first = nou;
//	 lista->nrNoduri++;
// }
//
// void adaugareDupaID(ListaDubla* lista, Pilot p)
// {
//	 Nod* nou = malloc(sizeof(Nod));
//	 nou->pilot = p;
//	 nou->next = NULL;
//	 nou->prev = NULL;
//	 Nod* curent = lista->first;
//	 if (lista->first == NULL)
//	 {
//		 lista->first = nou;
//		 lista->last = nou;
//		 lista->nrNoduri ++;
//		 return;
//	 }
//	 while (curent && curent->pilot.id < p.id)
//	 {
//		 curent = curent->next;
//	 }
//	 nou->next = curent;
//	 nou->prev = (curent != NULL) ? curent->prev : lista->last;
//	 if (nou->next)
//	 {
//		 nou->next->prev = nou;
//	 }
//	 else
//	 {
//		 lista->last = nou;
//	 }
//	 if (nou->prev)
//	 {
//		 nou->prev->next = nou;
//	 }
//	 else
//	 {
//		 lista->first = nou;
//	 }
//
//	 lista->nrNoduri++;
// }
//
// ListaDubla citireListaDinFisier(const char* numeFisier)
// {
//	 FILE* file = fopen(numeFisier, "r");
//	 ListaDubla lista;
//	 lista.first = NULL;
//	 lista.last = NULL;
//	 lista.nrNoduri = 0;
//	 while (!feof(file))
//	 {
//		 adaugareDupaID(&lista, CitirePilotdinFisier(file));
//	 }
//
//	 fclose(file);
//	 return lista;
// }
// void dezalocareListaDubla(ListaDubla* lista)
// {
//	 Nod* curent = lista->first;
//	 while (curent)
//	 {
//		 Nod* aux = curent;
//		 curent = curent->next;
//		 if (aux->pilot.echipa != NULL)
//		 {
//			 free(aux->pilot.echipa);
//		 }
//		 free(aux);
//	 }
//	 lista->first = NULL;
//	 lista->last = NULL;
//	 lista->nrNoduri = 0;
// }
//
// float calculeazaGreutateamedie(ListaDubla lista)
// {
//	 float suma = 0;
//	 Nod* p = lista.first;
//	 while (p)
//	 {
//		 suma += p->pilot.greutate;
//		 p = p->next;
//	 }
//	 if (lista.nrNoduri != 0)
//	 {
//		 return suma / lista.nrNoduri;
//	 }
//	 else
//	 {
//		 return 0;
//	 }
// }
//
// Nod* celeMaiMulteMedalii(ListaDubla lista)
// {
//	 if (lista.first != NULL)
//	 {
//		 Nod* p = lista.first;
//		 Nod* max = lista.first;
//		 while (p)
//		 {
//			 if (p->pilot.nrMedalii > max->pilot.nrMedalii)
//			 {
//				 max = p;
//			 }
//			 p = p->next;
//		 }
//		 
//		 return max;
//
//		 
//	 }
// }
//
// void stergeNod(ListaDubla* lista, int id) 
// {
//	 if (lista->first == NULL)
//	 {
//		 return;
//	 }
//	 Nod* p = lista->first;
//	 while (p && p->pilot.id != id)
//	 {
//		 p = p->next;
//	 }
//	 if (p == NULL)
//	 {
//		 return;
//	 }
//	 if (p->prev = NULL)
//	 {
//		 lista->first = p->next;
//		 if (lista->first)
//		 {
//			 lista->first->prev = NULL;
//		 }
//
//	 }
//	 else
//	 {
//		 p->prev->next = p->next;
//	 }
//	if (p->next)
//		 {
//			 p->next->prev = p->prev;
//		 }
//	else
//	{
//		lista->last = p->prev;
//	}
//	if (p->pilot.echipa != NULL)
//	{   
//		free(p->pilot.echipa);
//	}
//	free(p);
//	lista->nrNoduri--;
//	 
// }
//
// int main()
// {
//	 ListaDubla lista = citireListaDinFisier("piloti.txt");
//	 afisareDeLaInceput(lista);
//	 float greutate = calculeazaGreutateamedie(lista);
//	 printf("\n %5.2f", greutate);
//	 Nod* p = celeMaiMulteMedalii(lista);
//	 afisarePilot(p->pilot);
//	 return 0;
// }