#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int i=0,j,value,l,p,sum=0,y,qt,m,n,qnty,e;
struct FoodDetails {
	char part[50];
	int quantity;
	int rate;
};
struct FoodDetails details[100];
struct BillDetails {
	char food[50];
	int billquantity;
	int billrate;
	int billamnt;
	int billtotal;
};
struct BillDetails bills[100];
void input(){
	printf("Enter particulars:\n");
	scanf("%s",&details[i].part);
	printf("Enter quantity:\n");
	scanf("%d",&details[i].quantity);
	printf("Enter rate:\n");
	scanf("%d",&details[i].rate);
	printf("\nProduct added successfully");
	i++;
}
void chinput(){
	int dh,z2;
	char n[4];
	char dh1[4];
	z2=strcmp(dh1,"y");
	strcpy(n,"y");
	do{
		input();
		printf("\nDo you want to add more products?");
		scanf("%s",&dh1);
		if(z2==0)
			continue;
		else if(strcmp(dh1,"n")==0){
			break;
		}
	}while(strcmp(n,"y")==0);
}
void output(){
	if(i==0){
		printf("\nNO PRODUCTS ADDED");
	}else{
		printf("\n-----------------------------");
		printf("\nPARTICULARS\tQUANTITY\tRATE");
		printf("\n-----------------------------");
		for(j=0;j<i;j++){
			printf("\n%s\t\t%d\t\t%d",details[j].part,details[j].quantity,details[j].rate);
		}
	}
}
void singlefood(){
	char food[56];
	if(i==0){
		printf("NO PRODUCTS ADDED");
	}
	else {
		printf("Enter Food Name:\n");
		scanf("%s",&food);
		for(m=0;m<i;m++){
			value=strcmp(food,details[m].part);
			if(value==0){
				printf("Rate=%d\nQuantity=%d",details[m].rate,details[m].quantity);
				break;
			}
		}
		if(m==i){
			printf("Food Not Stored");
		}
}
}
void updatestock(){
	char foname[56];
	if(i==0){
		printf("\nNO PRODUCTS ADDED");
	}else{
		printf("\nEnter food name:");
		scanf("%s",&foname);
		for(y=0;y<i;y++){
			if(strcmp(foname,details[y].part)==0){
				printf("Enter quantity:");
				scanf("%d",&qnty);
				details[y].quantity+=qnty;
				printf("\nUpdation successful");
				break;
			}
		}
		if(y==i){
			printf("Food not stored");
		}
}
}
void getbill(){
	char fname[56];
	if(i==0){
		printf("\nNO PRODUCTS ADDED");
	}else{
		printf("\nEnter food name:");
		scanf("%s",&fname);
		for(p=0;p<i;p++){
			if(strcmp(fname,details[p].part)==0){
				printf("Enter quantity:");
				scanf("%d",&qt);
				if(qt<=details[p].quantity){
					details[p].quantity-=qt;
					strcpy(bills[e].food,details[p].part);
					bills[e].billquantity=qt;
					bills[e].billrate=details[p].rate;
					bills[e].billamnt=bills[e].billquantity*bills[e].billrate;
					bills[e].billtotal+=bills[e].billamnt;
					e++;
					break;
				}
				else{
					printf("Insufficient Stock");
					printf("\nActual quantity=%d",details[p].quantity);
					break;
				}
			}
		}
				if(p==i){
					printf("Food Not Stored");
				}
			}
}
void billing(){
	 if(i==0){
		printf("NO PRODUCTS ADDED");
	 }
	 else{
	 printf("\n\tHARISH RESTAURANT\t");
	 printf("\n\tPure Veg\t");
	 printf("\n\tMadurai\t");
	 printf("\n-----------INVOICE------------");
	 printf("\nFoods\tQty\tRate\tAmount");
	 printf("\n------------------------------");
	 for(l=0;l<e;l++){
		printf("\n%s\t%d\t%d\t%d",bills[l].food,bills[l].billquantity,bills[l].billrate,bills[l].billamnt);
		sum=sum+bills[l].billtotal;
	 }
	 printf("\nTotal=%d",sum);

	}
}
void checkbill(){
	int dh,z2;
	char n[4];
	char dh1[3];
	if(i==0){
		printf("\nNO PRODUCTS ADDED");
	}else{
	z2=strcmp(dh1,"y");
	strcpy(n,"y");
	do{
		getbill();
		printf("\nDo you want to add more products for billing?");
		scanf("%s",&dh1);
		if(z2==0)
			continue;
		else if(strcmp(dh1,"n")==0){
			billing();
			break;
		}
	}while(strcmp(n,"y")==0);
	}
}
void menu(int ch) {
	printf("\n\t\tWorld's No.1 Restaurant\t");
	printf("\n\t************************************");
	printf("\n\t\tHARISH RESTAURANT\t");
	printf("\n\t************************************");
	printf("\n\t1.Add Food Details");
	printf("\n\t2.View All Added Food Details");
	printf("\n\t3.Single Food");
	printf("\n\t4.Update stock");
	printf("\n\t5.Billing");
	printf("\n\t6.Exit");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch){
	case 1:
		printf("Add Food Details\n");
		chinput();
		break;
	case 2:
		printf("View All Added Food Details");
		output();
		break;
	case 3:
		printf("Single Food\n");
		singlefood();
		break;
	case 4:
		printf("Update Stock");
		updatestock();
		break;
	case 5:
		printf("Billing");
		checkbill();
		break;
	case 6:
		printf("Exit");
		exit(0);
		break;
	default:
		printf("Enter a valid choice");
	}
}
void main(){
	int ch,z1;
	char m[4];
	char ch1[3];
	clrscr();
	z1=strcmp(ch1,"y");
	strcpy(m,"y");
	do{
		menu(ch);
		printf("\nDo you want to continue to menu?");
		scanf("%s",&ch1);
		if(z1==0)
			continue;
		else if(strcmp(ch1,"n")==0){
			printf("Thank You");
			break;
		}
	}while(strcmp(m,"y")==0);
	getch();

}

