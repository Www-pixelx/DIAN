#include<stdio.h>
int main()
{
	char name;
	int pass,price,quantity;
	printf("货物：A,B,C,D,E;通道：1，2，3，4，5;个数不大于五十。\n请输入想要摆放的货物的名称，通道，单价和个数（用空格隔开）\n");
	scanf("%c %d %d %d",&name,&pass,&price,&quantity);
	if((pass==1||pass==2||pass==3||pass==4||pass==5)&&quantity<=50&&(name=='A'||name=='B'||name=='C'||name=='E'||name=='D'))
	{
		printf("已在%d通道摆放%c货物共%d个，单价%d元\n%d: %c * %d 单价%d元",pass,name,quantity,price,pass,name,quantity,price);	
	}
	else{
		printf("请按要求正确输入"); 
	}

	return 0;
}