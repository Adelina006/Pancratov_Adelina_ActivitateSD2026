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
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("nrUsi: %d\n", masina.nrUsi);
//	printf("Pret: %5.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume Sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n", masina.serie);
//
//}
//
//void afisareVectorMasini(Masina* masini, int nrMasini) {
//	for (int i = 0; i < nrMasini; i++)
//	{
//		afisareMasina(masini[i]);
//	}
//}
//
//void adaugaMasinaInVector(Masina** masini, int * nrMasini, Masina masinaNoua) {
//	(*nrMasini)++;
//	Masina* aux = malloc(sizeof(Masina) * (*nrMasini));
//	for (int i = 0; i < (*nrMasini) - 1; i++)
//	{
//		aux[i] = (*masini)[i];
//	}
//	aux[(*nrMasini) - 1] = masinaNoua;
//	free(*masini);
//	(*masini) = aux;
//
//}
//
//Masina citireMasinaFisier(FILE* file) {
//
//	char buffer[50];
//	fgets(buffer, 50, file);
//	Masina masina;
//	char delimitator[3] = ",\n";
//	masina.id=atoi(strtok(buffer, delimitator));
//	masina.nrUsi = atoi(strtok(NULL, delimitator));
//	masina.pret = atof(strtok(NULL, delimitator));
//	char* aux = strtok(NULL, delimitator);
//	masina.model = malloc((strlen(aux) + 1) * sizeof(char));
//	strcpy(masina.model, aux);
//	aux = strtok(NULL, delimitator);
//	masina.numeSofer = malloc((strlen(aux) + 1) * sizeof(char));
//	strcpy(masina.numeSofer, aux);
//	char* serie = strtok(NULL, delimitator);
//	masina.serie = serie[0];
//
//	return masina;
//
//}
//
//Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
//
//	FILE* file = fopen(numeFisier, "r");
//	Masina* masini = NULL;
//	(*nrMasiniCitite) = 0;
//	while (!feof(file))
//	{
//		adaugaMasinaInVector(&masini, nrMasiniCitite, citireMasinaFisier(file));
//	
//	}
//
//	fclose(file);
//	return masini;
//}
//
//void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
//	for (int i = 0; i < (*nrMasini); i++)
//	{
//		free((*vector)[i].model);
//		free((*vector)[i].numeSofer);
//	}
//	free(*vector);
//	*vector = NULL;
//	*nrMasini = 0;
//}
//
//int main() {
//
//	int nrMasini = 0;
//	Masina* masini = citireVectorMasiniFisier("masini.txt", &nrMasini);
//	afisareVectorMasini(masini, nrMasini);
//
//	return 0;
//}