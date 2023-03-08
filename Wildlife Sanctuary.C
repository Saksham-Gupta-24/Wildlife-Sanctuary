#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

struct visitor
{
	char address[100], visitor_name[100], visitor_no[20];
	struct visitor *next;

} * head;

struct species
{
	char type_of_species[100], species_name[100], scientific_name[20], endangered[10];
	struct species *next;

} * start;

struct feeding
{
	char f_item[10], f_name[10];
	struct feeding *next;
} * begin;

void insert1(char *visitor_name, char *visitor_no, char *address)
{
	struct visitor *visitor = (struct visitor *)malloc(sizeof(struct visitor));
	strcpy(visitor->visitor_name, visitor_name);
	strcpy(visitor->visitor_no, visitor_no);
	strcpy(visitor->address, address);
	visitor->next = NULL;
	if (head == NULL)
	{
		head = visitor;
	}
	else
	{
		visitor->next = head;
		head = visitor;
	}
}

void insert2(char *type_of_species, char *species_name, char *scientific_name, char *endangered)
{
	struct species *temp;
	struct species *species = (struct species *)malloc(sizeof(struct species));
	strcpy(species->type_of_species, type_of_species);
	strcpy(species->species_name, species_name);
	strcpy(species->scientific_name, scientific_name);
	strcpy(species->endangered, endangered);
	species->next = NULL;
	if (start == NULL)
	{
		start = species;
	}
	else
	{
		species->next = start;
		start = species;
	}
}

void insert3(char *f_item, char *f_name)
{
	struct feeding *feeding = (struct feeding *)malloc(sizeof(struct feeding));
	strcpy(feeding->f_name, f_name);
	strcpy(feeding->f_item, f_item);
	feeding->next = NULL;
	if (begin == NULL)
	{
		begin = feeding;
	}
	else
	{
		feeding->next = begin;
		begin = feeding;
	}
}

void displayv()
{
	struct visitor *temp = head;
	clrscr();
	printf("\t\t\t\t\t\t\tsort by: newest first\n");
	if (temp == NULL)
	{
		printf("Nothing to display !!!");
	}
	else
	{
		printf("Visitors are\n");
		while (temp != NULL)
		{
			printf("Visitor_Name: %s\n", temp->visitor_name);
			printf("Visitor_number : %s\n", temp->visitor_no);
			printf("Address: %s\n", temp->address);
			temp = temp->next;
		}
	}
	getch();
}

void displays()
{
	struct species *temp = start;
	clrscr();
	printf("\t\t\t\t\t\t\tsort by: newest first\n");
	if (temp == NULL)
	{
		printf("Nothing to display !!!");
	}
	else
	{
		printf("Species are\n");
		while (temp != NULL)
		{

			printf("Type of species: %s\n", temp->type_of_species);
			printf("Name of species: %s\n", temp->species_name);
			printf("Scientific name: %s\n", temp->scientific_name);
			printf("Is the species endangered or not(yes/no): %s\n", temp->endangered);
			temp = temp->next;
		}
	}
	getch();
}

void feedingitem()
{
	struct feeding *temp;
	clrscr();
	temp = begin;
	printf("\t\t\t\t\t\t\tsort by: newest first\n");
	if (temp == NULL)
	{
		printf("Nothing to display !!!");
	}
	else
	{
		printf("Feeding items are\n");
		while (temp != NULL)
		{
			printf("\nFeed %s to %s\n", temp->f_item, temp->f_name);
			temp = temp->next;
		}
	}
	getch();
}

void schedule()
{
	clrscr();
	printf("\nOPENING HOURS\n");
	printf("\tDay\t\tTime\n");
	printf("MONDAY TO FRIDAY  :- 9 am to 5 pm\n");
	printf("SATURDAY & SUNDAY :- 10 am to 6 pm\n");
	printf("\nFEEDING HOURS\n");
	printf("All days  :- 12 am to 1 pm and 7 pm to 8 pm\n");
	getch();
}

void deletev(char item1[])
{
	struct visitor *temp1 = head;
	struct visitor *temp2 = head;
	while (temp1 != NULL)
	{
		if (strcmpi(temp1->visitor_name, item1) == 0)
		{
			printf("Record with name %s Found !!!\n", item1);
			if (temp1 == temp2)
			{
				head = head->next;
				free(temp1);
			}
			else
			{
				temp2->next = temp1->next;
				free(temp1);
			}
			printf("Record Successfully Deleted !!!\n");
			return;
		}
		temp2 = temp1;
		temp1 = temp1->next;
	}
	printf("Record with name %s is not found !!!\n", item1);
}

void deletes(char item2[])
{
	struct species *temp1 = start;
	struct species *temp2 = start;
	while (temp1 != NULL)
	{
		if (strcmpi(temp1->species_name, item2) == 0)
		{
			printf("Record with name %s Found !!!\n", item2);
			if (temp1 == temp2)
			{
				start = start->next;
				free(temp1);
			}
			else
			{
				temp2->next = temp1->next;
				free(temp1);
			}
			printf("Record Successfully Deleted !!!\n");
			return;
		}
		temp2 = temp1;
		temp1 = temp1->next;
	}
	printf("Record with name %s is not found !!!\n", item2);
}

void searchv(char item3[])
{
	struct visitor *temp = head;
	if (head == NULL)
	{
		printf("Enter the data first !!!");
	}
	else
	{
		while (temp != NULL)
		{
			if (strcmpi(temp->visitor_name, item3) == 0)
			{
				printf("Visitor_Name: %s\n", temp->visitor_name);
				printf("Visitor_number : %s\n", temp->visitor_no);
				printf("Address: %s\n", temp->address);
			}
			else
			{
				printf("Record with name %s is not found !!!\n", item3);
			}
			temp = temp->next;
		}
	}
}

void searchs(char item4[])
{
	struct species *temp = start;
	if (start == NULL)
	{
		printf("Enter the data first !!!");
	}
	else
	{
		while (temp != NULL)
		{
			if (strcmpi(temp->species_name, item4) == 0)
			{
				printf("Type of species: %s\n", temp->type_of_species);
				printf("Name of species: %s\n", temp->species_name);
				printf("Scientific name: %s\n", temp->scientific_name);
				printf("Is the species endangered or not(yes/no): %s\n", temp->endangered);
			}
			else
			{
				printf("Record with name %s is not found !!!\n", item4);
			}
			temp = temp->next;
		}
	}
}

void modifyv(char item5[])
{
	struct visitor *temp = head;
	if (head == NULL)
	{
		printf("Enter the data first !!!");
	}
	else
	{
		while (temp != NULL)
		{
			if (strcmpi(temp->visitor_name, item5) == 0)
			{
				printf("Record with name %s Found !!!\n", item5);
				printf("Enter the new record\n");
				printf("\nEnter Visitor's Name: ");
				fflush(stdin);
				scanf("%[^\n]s", temp->visitor_name);
				printf("Enter Visitor phone no: ");
				scanf("%s", temp->visitor_no);
				printf("Enter visitor address: ");
				fflush(stdin);
				scanf("%[^\n]s", temp->address);
				printf("Updation Successful!!!\n");
			}
			else
			{
				printf("Record with name %s is not Found !!!\n", item5);
			}
			temp = temp->next;
		}
	}
}

void modifys(char item6[])
{
	struct species *temp = start;
	if (start == NULL)
	{
		printf("Enter the data first !!!");
	}
	else
	{
		while (temp != NULL)
		{
			if (strcmpi(temp->species_name, item6) != 0)
			{
				printf("Record with name %s is not Found !!!\n", item6);
			}
			else
			{
				printf("Record with name %s Found !!!\n", item6);
				printf("Enter the new record\n");
				printf("Enter the type of species whether plant or animal: ");
				scanf("%s", temp->type_of_species);
				printf("Enter name of species: ");
				fflush(stdin);
				scanf("%[^\n]s", temp->species_name);
				printf("Enter scientific name of the species: ");
				fflush(stdin);
				scanf("%[^\n]s", temp->scientific_name);
				printf("Is the species endangered or not(yes/no): ");
				scanf("%s", temp->endangered);
				printf("Updation Successful!!!\n");
			}
			temp = temp->next;
		}
	}
}

void main()
{
	int choice, o;
	char item1[20], item2[20], item3[20], item4[20], item5[20], item6[20], address[100], visitor_name[100], visitor_no[20];
	char type_of_species[100], species_name[100], scientific_name[20], endangered[10], f_item[10], f_name[10];
	head = NULL;
	start = NULL;
	begin = NULL;
end:
	clrscr();
	printf("\t\t**************************************\n\t\tWELCOME TO THE JK WILD LIFE SANCTUARY\n\t\t**************************************\n");
	do
	{
		printf("\n\t\t\t\tMENU\n");
		printf("1.Add record\n2.Delete record\n3.Modify the record\n4.Search any record\n5.Display any record\n6.Exit\n");
		printf("\nChoose an option: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			while (1)
			{
				clrscr();
				printf("\n\t\t\tADD MENU\n1.For visitor\n2.For species\n3.Feeding items\n4.Go back to main menu\n\nChoose an option: ");
				scanf("%d", &o);
				switch (o)
				{
				case 1:
					clrscr();
					printf("Enter Visitor's Name: ");
					fflush(stdin);
					scanf("%[^\n]s", visitor_name);
					printf("Enter Visitor phone no: ");
					scanf("%s", visitor_no);
					printf("Enter visitor address: ");
					fflush(stdin);
					scanf("%[^\n]s", address);
					insert1(visitor_name, visitor_no, address);
					break;
				case 2:
					clrscr();
					printf("Enter the type of species whether plant or animal: ");
					scanf("%s", type_of_species);
					printf("Enter name of species: ");
					fflush(stdin);
					scanf("%[^\n]s", species_name);
					printf("Enter scientific name of the species: ");
					fflush(stdin);
					scanf("%[^\n]s", scientific_name);
					printf("Is the species endangered or not(yes/no): ");
					scanf("%s", endangered);
					insert2(type_of_species, species_name, scientific_name, endangered);
					break;
				case 3:
					clrscr();
					printf("Enter the name of the product: ");
					scanf("%s", f_item);
					printf("Enter the name of the animal which you want to feed %s: ", f_item);
					fflush(stdin);
					scanf("%[^\n]s", f_name);
					insert3(f_item, f_name);
					break;
				case 4:
					goto end;
					break;
				default:
					printf("Enter a valid choice!!");
					getch();
					break;
				}
			}
		case 5:
			while (1)
			{
				clrscr();
				printf("\n\t\t\tDISPLAY MENU\n1.For visitor\n2.For species\n3.Feeding items\n4.Time Schedule of the sanctuary\n5.Go back to main menu\n");
				printf("\nChoose an option: ");
				scanf("%d", &o);
				switch (o)
				{
				case 1:
					displayv();
					break;
				case 2:
					displays();
					break;
				case 3:
					feedingitem();
					break;
				case 4:
					schedule();
					break;
				case 5:
					goto end;
					break;
				default:
					printf("Enter a valid choice!!");
					getch();
					break;
				}
			}
		case 2:
			while (1)
			{
				clrscr();
				printf("\n\t\t\tDELETE MENU\n1.For visitor\n2.For species\n3.Go back to main menu\n\nChoose an option: ");
				scanf("%d", &o);
				switch (o)
				{
				case 1:
					clrscr();
					printf("Enter the name of the visitor whose record you want to delete: ");
					fflush(stdin);
					scanf("%[^\n]s", item1);
					deletev(item1);
					getch();
					break;
				case 2:
					clrscr();
					printf("Enter the name of the species whose record you want to delete: ");
					fflush(stdin);
					scanf("%[^\n]s", item2);
					deletes(item2);
					getch();
					break;
				case 3:
					goto end;
					break;
				default:
					printf("Enter a valid choice!!");
					getch();
					break;
				}
			}
		case 3:
			while (1)
			{
				clrscr();
				printf("\n\t\t\tMODIFY MENU\n1.For visitor\n2.For species\n3.Go back to main menu\n\nChoose an option: ");
				scanf("%d", &o);
				switch (o)
				{
				case 1:
					clrscr();
					printf("Enter the name of the visitor whose record you want to modify: ");
					fflush(stdin);
					scanf("%[^\n]s", item5);
					modifyv(item5);
					getch();
					break;
				case 2:
					clrscr();
					printf("Enter the name of the species whose record you want to modify: ");
					fflush(stdin);
					scanf("%[^\n]s", item6);
					modifys(item6);
					getch();
					break;
				case 3:
					goto end;
					break;
				default:
					printf("Enter a valid choice!!");
					getch();
					break;
				}
			}
		case 4:
			while (1)
			{
				clrscr();
				printf("\n\t\t\tSEARCH MENU\n1.For visitor\n2.For species\n3.Go back to main menu\n");
				printf("\nChoose an option: ");
				scanf("%d", &o);
				switch (o)
				{
				case 1:
					clrscr();
					printf("Enter the name of the visitor whose record you want to search: ");
					fflush(stdin);
					scanf("%[^\n]s", item3);
					searchv(item3);
					getch();
					break;
				case 2:
					clrscr();
					printf("Enter the name of the species whose record you want to search: ");
					fflush(stdin);
					scanf("%[^\n]s", item4);
					searchs(item4);
					getch();
					break;
				case 3:
					goto end;
					break;
				default:
					printf("Enter a valid choice!!");
					getch();
					break;
				}
			}
		case 6:
			exit(0);
			break;
		default:
			printf("Enter a valid number!!");
			getch();
			break;
		}
	} while (choice);
}