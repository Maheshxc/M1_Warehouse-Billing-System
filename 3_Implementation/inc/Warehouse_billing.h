
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
