//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct Student {
//	int id;
//	char* nume;
//	int nrNote;
//	int* note;
//	float medie; //calculata ca medie aritmetica a notelor 
//	char bursa; //D = da; N = nu (in functie de medie)
//};
//typedef struct Student Student;
//
////Functie care sa citeasca studentii dintr un fisier 
//void adaugaNota(Student* student, int nota)
//{
//	if (nota > 1 && nota <= 10)
//	{
//		student->nrNote++;
//		int* aux = malloc((student->nrNote ) * sizeof(int));
//		for (int i = 0; i < student->nrNote - 1 ;  i++)
//		{
//			aux[i] = student->note[i]; 
//		}
//		aux[student->nrNote - 1] = nota;
//		free(student->note);
//		student->note = malloc(student->nrNote * sizeof(int));
//		for (int i = 0; i < student->nrNote; i++)
//		{
//			student->note[i] = aux[i];
//		}
//
//		free(aux);
//
//	}
//}
//
//void adaugareStudentInVector(Student student, int* nrStudenti, Student** vector)
//{
//	Student* aux = malloc(((*nrStudenti) +1) * sizeof(Student));
//	for (int i = 0; i < (*nrStudenti); i++)
//	{
//		aux[i] = (*vector)[i];
//	}
//	(*nrStudenti)++;
//	aux[(*nrStudenti) - 1] = student;
//	free(*vector);
//	(*vector) = aux;
//
//
//}
//
//Student citireStudentDinFisier(FILE* file)
//{
//	Student student;
//	char buffer[50];
//	char delimitator[3] = ",\n";
//	fgets(buffer, 50, file);
//	student.id = atoi(strtok(buffer, delimitator));
//	char* nume = strtok(NULL, delimitator);
//	student.nume = malloc((strlen(nume) + 1) * sizeof(char));
//	strcpy(student.nume, nume);
//	student.nrNote = 0;
//	student.note = NULL;
//	char* token = strtok(NULL, delimitator);
//	
//	while (token != NULL)
//	{
//		int nota = atoi(token);
//		adaugaNota(&student, nota);
//		token = strtok(NULL, delimitator);
//	
//	}
//	if (student.note != NULL)
//	{
//		float suma = 0;
//		for (int i = 0; i < student.nrNote; i++)
//		{
//			suma += student.note[i];
//		}
//		student.medie = suma / student.nrNote;
//	}
//	if (student.medie >= 8.50)
//	{
//		student.bursa = 'D';
//	}
//	else
//	{
//		student.bursa = 'N';
//	}
//
//
//	return student;
//}
//
//Student* citireVectorStudentiDinFisier(const char* numeFisier, int *nrStudenti)
//{
//	FILE* file = fopen(numeFisier, "r");
//	Student* vector = NULL;
//	while (!feof(file))
//	{
//		adaugareStudentInVector(citireStudentDinFisier(file), nrStudenti, &vector);
//	}
//	fclose(file);
//	return vector;
//	
//}
//
//void afisareStudent(Student s)
//{
//	printf("\nId: %d\n", s.id);
//	printf("\nNume: %s\n", s.nume);
//	printf("\nNr note : %d\n", s.nrNote);
//	for (int i = 0; i < s.nrNote; i++)
//	{
//		printf("\nnota %d: %d\n",i, s.note[i]);
//	}
//	printf("\nMedie: %5.2f\n", s.medie);
//	printf("\nBursa: %c\n", s.bursa);
//}
//
//void afisareVectorStudenti(Student* s, int nrStudenti)
//{
//	for (int i = 0; i < nrStudenti; i++)
//	{
//		afisareStudent(s[i]);
//		printf("\n");
//	}
//}
//
////Functie care returneaza studentii bursieri
//Student* returneazaBursieri(Student* studenti, int nrStudenti, int* studentiBursieri)
//{
//	Student* aux = NULL;
//	(*studentiBursieri) = 0;
//	for (int i = 0; i < nrStudenti; i++)
//	{
//		if (studenti[i].medie > 8.50)
//		{
//			(*studentiBursieri)++;
//		}
//	}
//	aux = malloc(sizeof(Student) * (*studentiBursieri));
//	int k = 0;
//	for (int i = 0; i < nrStudenti; i++)
//	{
//		if (studenti[i].medie > 8.50)
//		{
//			aux[k].id = studenti[i].id;
//			aux[k].nume = malloc(sizeof(char) * (strlen(studenti[i].nume) + 1));
//			strcpy(aux[k].nume, studenti[i].nume);
//			aux[k].nrNote = studenti[i].nrNote;
//			aux[k].note = malloc(sizeof(int) * aux[k].nrNote);
//			for (int j = 0; j < aux[k].nrNote; j++)
//			{
//				aux[k].note[j] = studenti[i].note[j];
//			}
//			aux[k].medie = studenti[i].medie;
//			aux[k].bursa = studenti[i].bursa;
//
//			k++;
//		}
//	}
//
//	return aux;
//}
//
////adaugare nota si actualizare student dupa id
//
//void actualizareNote(Student** studenti, int nrStudenti, int id, int nota)
//{
//	for (int i = 0; i < nrStudenti; i++)
//	{
//		if ((*studenti)[i].id == id)
//		{
//			adaugaNota(&(*studenti)[i], nota);
//			if ((*studenti)[i].note != NULL)
//			{
//				float suma = 0;
//				for (int i = 0; i < (*studenti)[i].nrNote; i++)
//				{
//					suma += (*studenti)[i].note[i];
//				}
//				(*studenti)[i].medie = suma / (*studenti)[i].nrNote;
//			}
//			if ((*studenti)[i].medie >= 8.50)
//			{
//				(*studenti)[i].bursa = 'D';
//			}
//			else
//			{
//				(*studenti)[i].bursa = 'N';
//			}
//		}
//	}
//}
//
//
//void dezalocareVector(Student** s, int* nrStudenti)
//{
//	for (int i = 0; i < (*nrStudenti); i++)
//	{
//		free((*s)[i].nume);
//		free((*s)[i].note);
//	}
//	free(*s);
//	(*nrStudenti) = 0;
//}
//
//int main()
//{
//	int nrStudenti = 0;
//	Student* studenti = citireVectorStudentiDinFisier("studenti.txt", &nrStudenti);
//	afisareVectorStudenti(studenti, nrStudenti);
//	int nrBursieri = 0;
//	Student* bursieri = returneazaBursieri(studenti, nrStudenti, &nrBursieri);
//	printf("\nStudenti Bursieri)");
//	afisareVectorStudenti(bursieri, nrBursieri);
//	actualizareNote(&studenti, nrStudenti, 1, 2);
//	printf("\nStudenti Bursieri)");
//	bursieri = returneazaBursieri(studenti, nrStudenti, &nrBursieri);
//	afisareVectorStudenti(bursieri, nrBursieri);
//	dezalocareVector(&studenti, &nrStudenti);
//	dezalocareVector(&bursieri, &nrBursieri);
//	return 0;
//}



