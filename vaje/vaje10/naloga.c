#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    // popravite / dopolnite ...
	for(int i = 0; i < stStudentov; i++)
	{
		if(studentje[i]->vpisna == vpisna)
			return i;
	}

    return -1;
}

int poisciPO(Student* student, char* predmet) {
    // popravite / dopolnite ...
	int stPO = student->stPO;
	PO* predmetPtr = student->po;
	
	for(int i = 0; i < stPO; i++)
	{		
		if(strcmp(predmet, predmetPtr[i].predmet) == 0)
			return i;
	}
	
    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    // popravite / dopolnite ...
	
	int indeksStudenta = poisciStudenta(studentje, stStudentov, vpisna);
	
	if(indeksStudenta != -1)
	{
		int indeksPO = poisciPO(studentje[indeksStudenta], predmet);
		
		Student* studPtr = studentje[indeksStudenta];
		PO* predmetPtr  = studPtr->po;
		
		if(indeksPO != -1)
		{
			// samo popravimo obstojeco oceno
			predmetPtr[indeksPO].ocena = ocena;
		} else
		{
			// dodamo nov zapis v tabelo
			predmetPtr[studPtr->stPO].ocena = ocena;
			strcpy(predmetPtr[studPtr->stPO].predmet, predmet);
			
			studPtr->stPO++; // povecamo st parov predmet-ocena
		}
		
		return stStudentov;
	} else
	{
		// ustvarimo studenta
		Student* newStudent = malloc(sizeof(Student));
		
		newStudent->vpisna = vpisna;
		newStudent->stPO = 1;
		newStudent->po = malloc(10 * sizeof(PO));
		
		(newStudent->po)[0].ocena = ocena;
		strcpy((newStudent->po)[0].predmet, predmet);
		
		studentje[stStudentov] = newStudent;
		return stStudentov + 1;
		
	}
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
