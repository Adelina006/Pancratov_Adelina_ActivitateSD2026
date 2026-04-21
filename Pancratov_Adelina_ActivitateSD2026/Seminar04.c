
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

struct Masina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;

};

typedef struct Masina Masina;

struct Nod {
	Masina info;
	struct Nod* next;
};

typedef struct Nod Nod;

Masina citireMasinaDinFisier(FILE* file)
{
	char buffer[50];
	char delimitator[3] = ",\n";
	Masina masina;
	fgets(buffer, 50, file);
	masina.id = atoi(strtok(buffer, delimitator));
	masina.nrUsi = atoi(strtok(NULL, delimitator));
	masina.pret = atof(strtok(NULL , delimitator));
	masina.model = NULL;
	masina.numeSofer = NULL;
	char* aux = strtok(NULL, delimitator);
	masina.model = malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy(masina.model, aux);
	aux = strtok(NULL, delimitator);
	masina.numeSofer = malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy(masina.numeSofer, aux);
	masina.serie = *strtok(NULL, delimitator);

	return masina; 
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);

}

void afisareListaMasini(Nod* cap)
{
	while (cap != NULL)
	{
		afisareMasina(cap->info);
		cap = cap->next;
	}
}

void adaugareMasinaInListaLaFinal(Nod** cap, Masina masina)
{
	Nod* nou = malloc(sizeof(Nod));
	nou->info = masina;
	nou->next = NULL;
	if ((*cap))
	{
		Nod* p = (*cap);
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = nou;
	}
	else
	{
		(*cap) = nou;
	}
}

void InserareLaInceputInLista(Nod** cap, Masina masina)
{
	Nod* nou = malloc(sizeof(Nod));
	nou->info = masina;
	nou->next = (*cap);
	(*cap) = nou;
}

Nod* citesteListaDinFisier(const char* numeFisier)
{
	FILE* file = fopen(numeFisier, "r");
	Nod* cap = NULL;
	if (file) {
		while (!feof(file))
		{
			//creeam lista cu inserare la sfarsit 
			adaugareMasinaInListaLaFinal(&cap, citireMasinaDinFisier(file));

		}
	}
	fclose(file);
	return cap;
}

void dezalocare(Nod** cap)
{
	while ((*cap) != NULL)
	{
		Nod* p = (*cap);
		(*cap) = (*cap)->next;
		if (p->info.model != NULL)
		{
			free(p->info.model);
		}
		if (p->info.numeSofer != NULL)
		{
			free(p->info.numeSofer);
		}
		free(p);
	}
}

float calculeazaPretulMediu(Nod* cap)
{
	float suma = 0;
	int cnt = 0;
	while (cap != NULL)
	{
		suma += cap->info.pret;
		cnt++;
		cap = cap->next;
	}
	if (cnt > 0)
	{
		return suma / cnt;
	}

	return 0;
}

float calculeazaPretulMasinilorUnuiSofer(Nod* cap, const char* numeSofer)
{
	float suma = 0;
	while (cap != NULL)
	{
		
		if (strcmp(cap->info.numeSofer, numeSofer) == 0)
		{
			suma += cap->info.pret;
		}
		cap = cap->next;
	}
	return suma;
}

void stergeMasinaDinSeria(Nod** cap, char serieCautata)
{
	while ((*cap) && (*cap)->info.serie == serieCautata)
	{
		Nod* p = (*cap);
		(*cap) = p->next;
		if (p->info.model != NULL)
		{
			free(p->info.model);
		}
		if (p->info.numeSofer != NULL)
		{
			free(p->info.numeSofer);
		}
		free(p);
	}

	if ((*cap) != NULL)
	{

		Nod* aux = (*cap);
		while (aux) {
			while (aux->next && aux->next->info.serie != serieCautata)
			{
				aux = aux->next;
			}
			if (aux->next)
			{
				Nod* n = aux->next;
				aux->next = n->next;
				if (n->info.model != NULL)
				{
					free(n->info.model);
				}
				if (n->info.numeSofer != NULL)
				{
					free(n->info.numeSofer);
				}
				free(n);
			}
			else
			{
				aux = NULL;
			}
		}

	}
	return(*cap);
}


int main()
{
	Nod* cap = citesteListaDinFisier("masini.txt");
	//afisareListaMasini(cap);
	//dezalocare(&cap);
	printf("\nPretul mediu e %5.2f", calculeazaPretulMediu(cap));
	printf("\nPretul masinilor lui Ionescu e %5.2f", calculeazaPretulMasinilorUnuiSofer(cap, "Ionescu"));
	printf("\nstergere seria a\n");
	stergeMasinaDinSeria(&cap, 'A');
	afisareListaMasini(cap);
	dezalocare(&cap);
	return 0;
}
