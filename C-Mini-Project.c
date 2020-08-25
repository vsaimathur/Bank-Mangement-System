#include<stdio.h>
#include<string.h>
typedef struct
{
	char name[20];
	long long int phone_number;
	int age;
	long long int pincode;
	char res_name[30];
	long long int income;
	long long int bb;
	int account_no;
}bank;
int new_account(bank p[20]);
int view_account(bank p[20],int t);
int update_account(bank p[20],int t);
int	transaction(bank p[20],int t);
int remove_account(bank p[20],int t);
int display_customers(bank p[20],int t);
void main()
{
	int t=0;
	int decider;
	printf("\t\tBANKING SOFTWARE\t\t\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	while(1)
	{
		bank p[20];
		int choice;
		printf("-----------------------------------------------------------------------------------------------------\n");
		printf("\t\tMAINMENU\t\t\n");
		printf("-----------------------------------------------------------------------------------------------------\n");
		printf("1.Add a new account\n");
		printf("2.Update an existing account\n");
		printf("3.Check the details of existing account\n");
		printf("4.Transactions\n");
		printf("5.view customers list\n");
		printf("6.Removing the existing account\n");
		printf("\nEnter your choice:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: t=new_account(p);
			break;
			case 2: update_account(p,t); 
			break;
			case 3: view_account(p,t);
			break;
			case 4: transaction(p,t);
			break;
			case 5: display_customers(p,t);
			break;
			case 6: remove_account(p,t);
			break;
			default: printf("Invalid choice!\n");
			break;
		}
		printf("enter 1 if you want to continue, else enter 0:\t");
		scanf("%d",&decider);
		if(decider==0)
		{
			break;
		}
	}
}

int new_account(bank p[20])
{
	static int i=0;
	printf("\nenter name:\t");
	scanf("%s",p[i].name);					//Dont give spaces in between your name.
	printf("\nenter age:\t");				//Dont Enter the same person details again.
	scanf("%d",&p[i].age);
	printf("\nenter phone number:\t");
	scanf("%lld",&p[i].phone_number);
	printf("\nenter pincode:\t");
	scanf("%lld",&p[i].pincode);
	printf("\nenter residence name:\t");
	scanf("%s",p[i].res_name);
	printf("\nenter your income per annum:\t");
	scanf("%lld",&p[i].income);
	p[i].account_no=i+1;
	p[i].bb=500;							//Minimun Account Balance
	printf("\nYour account has been created successfully\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("\t\tTHANK YOU\t\t\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	i++;
	return i;
}
int view_account(bank p[20],int t)
{
	int s;
	int i;
	printf("enter bank account number:\t");
	scanf("%d",&s);
	for(i=0;i<t;i++)
	{	
		if(s==0)
		{
			printf("This account is deleted\n");
			printf("-----------------------------------------------------------------------------------------------------\n");
		}
		if(s==p[i].account_no)
		{
			printf("-----------------------------------------------------------------------------------------------------");
			printf("\nname:\t%s",p[i].name);
			printf("\nage:\t%d",p[i].age);
			printf("\nphone number:\t%lld",p[i].phone_number);
			printf("\npincode:\t%lld",p[i].pincode);
			printf("\nresidence:\t%s",p[i].res_name);
			printf("\nincome:\t%lld\n",p[i].income);
			printf("account number:\t%d\n",p[i].account_no);
			printf("bank account balance:\t%lld\n",p[i].bb);
			printf("-----------------------------------------------------------------------------------------------------\n");
		}	
	}
	return 0;
}

int display_customers(bank p[20],int t)
{
	int i;
	printf("The list of customers are:\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("\t\tS.NO\t\tNAME\t\tACCOUNT NUMBER\t\tBANK BALANCE\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	for(i=0;i<t;i++)
	{
		if(p[i].account_no==0)
		{
			continue;
		}
		printf("\t\t%d.\t\t%s\t\t\t%d\t\t\t%d\n",i+1,p[i].name,p[i].account_no,p[i].bb);	
		printf("-----------------------------------------------------------------------------------------------------\n");
 	}
 	return 0;
}

int update_account(bank p[20],int t)
{
	int no_updateac;
	int i;
	printf("Enter bank account number:\t");
	scanf("%d",&no_updateac);
	if(no_updateac!=0)
	{
		for(i=0;i<t;i++)
		{	
			if(no_updateac==p[i].account_no)
			{
				printf("Please enter the details again carefully:");
				printf("\nenter name:\t");
				scanf("%s",p[i].name);			//Dont give spaces in between your name.
				printf("\nenter age:\t");
				scanf("%d",&p[i].age);
				printf("\nenter phone number:\t");
				scanf("%lld",&p[i].phone_number);
				printf("\nenter pincode:\t");
				scanf("%lld",&p[i].pincode);
				printf("\nenter residence name:\t");
				scanf("%s",p[i].res_name);
				printf("\nenter your income per annum:\t");
				scanf("%lld",&p[i].income);
				printf("\nYour account has been updated successfully\n");
				printf("-----------------------------------------------------------------------------------------------------\n");
				printf("\t\tTHANK YOU\t\t\n");
				printf("-----------------------------------------------------------------------------------------------------\n");
			}
		}
	}
	else
	{
		printf("This account is deleted\n");
		printf("-----------------------------------------------------------------------------------------------------\n");
	}
	return 0;
}
int	transaction(bank p[20],int t)
{
	int s1;
	long long int amt1;
	long long int amt2;
	int select;
	int i;
	printf("Enter your bank account number:\t");
	scanf("%d",&s1);
	for(i=0;i<t;i++)
	{
		if(s1==0)
		{
			printf("This account has been removed\n\n");
			printf("Enter a valid bank account number\n");
			printf("-----------------------------------------------------------------------------------------------------\n");
			printf("\t\tTHANK YOU\t\t\n");
			printf("-----------------------------------------------------------------------------------------------------\n");
			break;
		}
		if(s1==p[i].account_no)
		{
			printf("1. Deposit amount\n");
			printf("2. Withdraw amount\n");
			printf("3. Check balance\n");
			printf("Enter your choice:\t");
			scanf("%d",&select);
			if(select==1)
			{
				printf("Enter the amount you want to deposit:\t");
				scanf("%lld",&amt1);
				p[i].bb+=amt1;
				printf("\nCurrent Bank Balance is:\t%lld\n",p[i].bb);
				printf("-----------------------------------------------------------------------------------------------------\n");
				printf("\t\tTHANK YOU\t\t\n");
				printf("-----------------------------------------------------------------------------------------------------\n");
				}
			else if(select==2)
			{
				printf("Enter the withdraw amount:\t");
				scanf("%lld",&amt2);
				if(p[i].bb < amt2)
				{
					printf("Bank balance is insufficient to withdraw:\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					printf("\t\tTHANK YOU\t\t\n");
					printf("-----------------------------------------------------------------------------------------------------\n");			}
				else if(p[i].bb >= amt2)
				{
					p[i].bb-=amt2;
					printf("\nCurrent Bank Balance is:\t%lld\n",p[i].bb);
					printf("-----------------------------------------------------------------------------------------------------\n");
					printf("\t\tTHANK YOU\t\t\n");
					printf("-----------------------------------------------------------------------------------------------------\n");}
			}
			else if(select==3)
			{
				printf("The current account balance is:\t%lld\n",p[i].bb);
				printf("-----------------------------------------------------------------------------------------------------\n");
				printf("\t\tTHANK YOU\t\t\n");
				printf("-----------------------------------------------------------------------------------------------------\n");		
			}
		}
	}
	return 0;
}
int remove_account(bank p[20],int t)
{
	int a_no,lastcall;
	printf("Enter the bank account number:\n");
	scanf("%d",&a_no);
	printf("Enter 1 if you are sure, else enter 0:\t");
	scanf("%d",&lastcall);
	if(a_no!=0)
	{
		if(lastcall==1)
		{
			p[a_no-1].income='\0';
			p[a_no-1].bb='\0';
			p[a_no-1].res_name[0]='\0';
			p[a_no-1].account_no='\0';
			p[a_no-1].pincode='\0';
			p[a_no-1].age='\0';
			p[a_no-1].phone_number='\0';
			p[a_no-1].name[0]='\0';
			printf("The account has been deleted successfully");
			printf("\n-----------------------------------------------------------------------------------------------------\n");
			printf("\t\tTHANK YOU\t\t\n");
			printf("-----------------------------------------------------------------------------------------------------\n");
			}
		else
		{
			printf("\n-----------------------------------------------------------------------------------------------------\n");
			printf("\t\tTHANK YOU\t\t\n");
			printf("-----------------------------------------------------------------------------------------------------\n");
		}
		return 0;
	}
	else
	{
		printf("This account is already deleted");
		printf("\n-----------------------------------------------------------------------------------------------------\n");
		printf("\t\tTHANK YOU\t\t\n");
		printf("-----------------------------------------------------------------------------------------------------\n");
	}
}