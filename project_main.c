#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void Input();
void writeTheFile();
void Search();
void Output();

struct date
{
	int month;
	int day;
	int year;
};

struct acc
{
	int number;
	char name[100];
	int acct_no;
	float phone;
	char street[100];
	char city[100];
	char account_type;
	float oldBalance;
	float newBalance;
	float payment;
	struct date lastpayment;
} consumer;
int TL, SL, TS;
void main()
{
	int i, n;
	char ch;
	system("cls");
	printf("Billing System For Warehouse:\n\n");
	printf("\n");
	printf("\n1:    to add account on list\n");
	printf("2:    to Search consumer acc\n");
	printf("3:    exit\n");
	printf("\n\n");
	do
	{
		printf("\nPlease select what do yo want to do:----> ");
		ch = getche();
	} while (ch <= '0' || ch > '3');
	switch (ch)
	{
	case '1':
		system("cls");
		printf("\nhow many consumer accounts?");
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			Input();
			if (consumer.payment > 0)
				consumer.account_type = (consumer.payment < 0.1 * consumer.oldBalance) ? 'O' : 'D';
			else
				consumer.account_type = (consumer.oldBalance > 0) ? 'D' : 'C';
			consumer.newBalance = consumer.oldBalance - consumer.payment;
			writeTheFile();
		}
		main();
	case '2':
		system("cls");
		printf("Search by what?\n");
		printf("\n1 --- Search by consumer number\n");
		printf("2 --- Search by consumer name\n");
		Search();
		ch = getche();
		main();
	case '3':
		system("cls");
		printf("\n System is closed");
		exit(1);
	}
}

void Input()
{
	FILE *fp = fopen("bidur.dat", "rb");
	fseek(fp, 0, SEEK_END);
	TL = ftell(fp);
	SL = sizeof(consumer);
	TS = TL / SL;
	fseek(fp, (TS - 1) * SL, SEEK_SET);
	fread(&consumer, sizeof(consumer), 1, fp);
	printf("\nconsumer no:%d\n", ++consumer.number);
	fclose(fp);
	printf("         acc number:");
	scanf("%d", &consumer.acct_no);
	printf("\n       Name:");
	scanf("%s", consumer.name);
	printf("\n       mobile no:");
	scanf("%f", &consumer.phone);
	printf("\n         Street:");
	scanf("%s", consumer.street);
	printf("\n         City:");
	scanf("%s", consumer.city);
	printf("         Previous balance:");
	scanf("%f", &consumer.oldBalance);
	printf("         Current payment:");
	scanf("%f", &consumer.payment);
	printf("         Payment date(mm/dd/yyyy):");
	scanf("%d/%d/%d", &consumer.lastpayment.month, &consumer.lastpayment.day, &consumer.lastpayment.year);
	return;
}

void writeTheFile()
{
	FILE *fp;
	fp = fopen("bidur.dat", "ab");
	fwrite(&consumer, sizeof(consumer), 1, fp);
	fclose(fp);
	return;
}

void Search()
{
	char ch;
	char nam[100];
	int n, i, m = 1;
	FILE *fp;
	fp = fopen("bidur.dat", "rb");
	do
	{
		printf("\nenter your choice:");
		ch = getche();
	} while (ch != '1' && ch != '2');
	switch (ch)
	{
	case '1':
		fseek(fp, 0, SEEK_END);
		TL = ftell(fp);
		SL = sizeof(consumer);
		TS = TL / SL;
		do
		{
			printf("\nchoose consumer number:");
			scanf("%d", &n);
			if (n <= 0 || n > TS)
				printf("\nenter correct\n");
			else
			{
				fseek(fp, (n - 1) * SL, SEEK_SET);
				fread(&consumer, SL, 1, fp);
				Output();
			}
			printf("\n\nagain?(y/n)");
			ch = getche();
		} while (ch == 'y');
		fclose(fp);
		break;
	case '2':
		fseek(fp, 0, SEEK_END);
		TL = ftell(fp);
		SL = sizeof(consumer);
		TS = TL / SL;
		fseek(fp, (TS - 1) * SL, SEEK_SET);
		fread(&consumer, sizeof(consumer), 1, fp);
		n = consumer.number;

		do
		{
			printf("\nenter the name:");
			scanf("%s", nam);
			fseek(fp, 0, SEEK_SET);
			for (i = 1; i <= n; i++)
			{
				fread(&consumer, sizeof(consumer), 1, fp);
				if (strcmp(consumer.name, nam) == 0)
				{
					Output();
					m = 0;
					break;
				}
			}
			if (m != 0)
				printf("\n\ndoesn't exist\n");
			printf("\nanother?(y/n)");
			ch = getche();
		} while (ch == 'y');
		fclose(fp);
	}
	return;
}

void Output()
{
	printf("\n\n    consumer no    :%d\n", consumer.number);
	printf("    Name 	   :%s\n", consumer.name);
	printf("    Mobile no      :%.f\n", consumer.phone);
	printf("    acc number :%d\n", consumer.acct_no);
	printf("    Street         :%s\n", consumer.street);
	printf("    City           :%s\n", consumer.city);
	printf("    Old balance    :%.2f\n", consumer.oldBalance);
	printf("    Current payment:%.2f\n", consumer.payment);
	printf("    New balance    :%.2f\n", consumer.newBalance);
	printf("    Payment date   :%d/%d/%d\n\n", consumer.lastpayment.month, consumer.lastpayment.day, consumer.lastpayment.year);
	printf("    acc status :");
	switch (consumer.account_type)
	{
	case 'C':
		printf("CURRENT\n\n");
		break;
	case 'O':
		printf("OVERDUE\n\n");
		break;
	case 'D':
		printf("DELINQUENT\n\n");
		break;
	default:
		printf("ERROR\\n\n");
	}
	return;
}
