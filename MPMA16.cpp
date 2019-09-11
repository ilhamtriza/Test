/*------------------------------------------------------------------
File		: MPMA16.cpp
Program		: Operasi Matriks Kali, Tambah, Row Sort, Column Sort
Dibuat oleh	: Ilham Triza Kurniawan
Tanggal		: 5 Desember 2018
--------------------------------------------------------------------*/


#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;

int i, j, k, l;

//Modul yang berfungsi untuk menukarkan
void tukar (int *v, int *g)
{
	int temp;
	
	temp = *v;
	*v = *g;
	*g = temp;
}


//Proses pengurutan angka pada baris dari yang terkecil ke yang terbesar
void RowSort(int x[10][10], int barisa, int koloma)
{
	int k;
	//proses pengurutan angka pada baris
	for (i=0;i<barisa;i++)
	{
		for (j=0;j<koloma-1;j++)
		{
			for (k=j+1;k<koloma;k++)
			{
				if (x[i][j]>x[i][k])
				{
					tukar (&x[i][j],&x[i][k]);
					/* Modul tukar tersebut menggantikan operasi sbb:
						temp = A[i][j];
						A[i][j] = a[i][k];
						A[i][k] = temp;
					*/
				}
			}
		}
	}
}


//Proses pengurutan angka pada kolom dari yang terkecil ke yang terbesar
void ColumnSort (int x[10][10],int barisa, int koloma)
{
	int k;
	//Proses pengurutan angka pada kolom
	for (j=0;j<koloma;j++)
	{
		for (i=0;i<barisa-1;i++)
		{
			for (k=i+1;k<barisa;k++)
			{
				if (x[i][j]>x[k][j])
				{
					tukar (&x[i][j],&x[k][j]);
				}
			}
		}
	}
}


//Modul Menampilkan Matriks
void ShowMatriks(int x[10][10], int barisa, int koloma)
{ 
	i=0;
	while (i<barisa)
	{
		j=0;
		while (j<koloma)
		{
			if (x[i][j]<10)
			{
				printf(" %d ",x[i][j]);
			}
			else
			{
				printf("%d ",x[i][j]);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n");
	
}


//Modul Menambahkan Matriks
void TambahMatriks(int x[10][10], int y[10][10], int barisa, int koloma, int barisb, int kolomb, int z[10][10])
{
	if (barisa==barisb && koloma==kolomb)
	{
		i=0;
		k=0;
	
		while(i<barisa)
		{
			j=0;
			l=0;
			while(j<koloma)
			{
				if(j==l) 
				{
					z[i][j] = x[i][j] + y[k][l];
				}
				j++;
				l++;
			}
			i++;
			k++;
		}
	}
	else
	{
		printf("Matriks Tidak dapat ditambahkan karena Ordonya berbeda");
	}
}


//Modul Perkalian Matriks
void KaliMatriks(int x[10][10], int y[10][10], int barisa, int koloma, int barisb, int kolomb, int z[10][10])
{
	int m,n,sum;
	if (koloma==barisb)
	{
		n=koloma;
		i=0;
		while(i<barisa)
		{
			j=0;
			while (j<kolomb)
			{
				z[i][j]=0;
				m=0;
				while(m<n)
				{
					sum=x[i][m] * y[m][j];
					z[i][j] += sum;
					m++;
				}
				j++;
			}
			i++;
		}
	}
}


//Program Utama
int main ()
{
	//Deklarasi variable
	int a[10][10];
	int b[10][10];
	int c[10][10];
	int ba,ka,bb,kb,barisa,koloma,barisb,kolomb,ordokali;
	int pil;
	char e = 'Y';
	
	system("cls");
	fflush(stdin);
	
	//Input jumlah baris dan kolom Matriks A
	printf("Masukkan Jumlah Baris A : ");
	scanf("%d",&barisa);
	printf("Masukkan Jumlah Kolom A : ");
	scanf("%d",&koloma);
	printf("===========================\n");
	printf("Masukkan Anggota Matriks A\n");
	ba=0;
	while (ba<barisa)
	{
		ka=0;
		while (ka<koloma)
		{
			printf("Data[%d][%d]= ",ba+1,ka+1);
			scanf("%d",&a[ba][ka]);
			ka++;
		}
		ba++;
	}
	printf("\n\n");
	
	//Input jumlah baris dan kolom Matriks A
	printf("Masukkan Jumlah Baris B : ");
	scanf("%d",&barisb);
	printf("Masukkan Jumlah Kolom B : ");
	scanf("%d",&kolomb);
	printf("===========================\n");
	printf("Masukkan Anggota Matriks B\n");
	bb=0;
	while (bb<barisb)
	{
		kb=0;
		while (kb<kolomb)
		{
			printf("Data[%d][%d]= ",bb+1,kb+1);
			scanf("%d",&b[bb][kb]);
			kb++;
		}
		bb++;
	}
	system("cls");
	printf("===========================\n\n");
	printf("Matriks A: \n");
	ShowMatriks(a,barisa,koloma);
	printf("Matriks B: \n");
	ShowMatriks(b,barisb,kolomb);
	
	//Pemilihan Menu
	printf("\nMENU\n");
	printf("1. A + B\n");
	printf("2. A * B\n");
	printf("3. Row Sort\n");
	printf("4. ColumnSort\n");
	printf("Pilih perintah : \n");
	printf("> ");
	scanf("%s",&pil);
	
	
	switch (pil)
	{
		case '1':{
			system ("cls");
			TambahMatriks(a,b,barisa,koloma,barisb,kolomb,c);
			printf("A + B : \n");
			ShowMatriks(c,barisa,koloma);
			break;
			}
		case '2':{
			system ("cls");
			KaliMatriks(a,b,barisa,koloma,barisb,kolomb,c);
			printf("A * B : \n");
			ShowMatriks(c,barisa,kolomb);
			break;
		}
		case '3':{
			system("cls");
			RowSort(a,barisa,koloma);
			printf("Matriks A Setelah di Row Sort: \n");
			ShowMatriks(a,barisa,koloma);
			RowSort(b,barisb,kolomb);
			printf("\nMatriks B Setelah di Row Sort: \n");
			ShowMatriks(b,barisb,kolomb);
			break;
		}
		case '4':{
			system("cls");
			ColumnSort(a,barisa,koloma);
			printf("Matriks A Setelah di Column Sort: \n");
			ShowMatriks(a,barisa,koloma);
			ColumnSort(b,barisb,kolomb);
			printf("\nMatriks B Setelah di Column Sort: \n");
			ShowMatriks(b,barisb,kolomb);
			break;
		}
	}
	
	fflush(stdin);
	printf("Apakah ingin mengulangi?(Y/T) : ");
	scanf("%c", &e);
	if(e != 'T')
	{
		main();
	}
	
	
	return 0;
}


