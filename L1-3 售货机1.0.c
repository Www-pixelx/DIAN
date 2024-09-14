#include<stdio.h>
int main()
{//摆放货物
		int price,quantity;
	printf("货物名称：A ;通道：1\n请输入摆放货物的单价");
	scanf("%d",&price);
	printf("请输入摆放货物的个数（<=50)");
	while(1){
		scanf("%d",&quantity);
		if(quantity>50)
		printf("您最多只能摆放50件货物，请重新输入");
	    else
	    printf("已在1通道摆放A货物%d个，单价%d元。\n",quantity,price);
	    break;
		}
	//购买
	int num = 0;
	int amount1 = 0;
	char input;
	while(amount1<=quantity){
	site1:
	printf("请输入购买的货物数量");
	scanf("%d",&num);
	if(num>quantity){break;}
	else{
	if(amount1 + num > 100)break;
	else
	amount1 += num;
	int sum = price*amount1;
	int pay = 0;
	int amount = 0;
	int i;
	error:
	printf("您一共消费%d元，请付款\n",sum);
	scanf("%d",&pay);
	int change = pay - sum;
	if((pay == 1 || pay == 2 || pay == 5) && pay >= sum){
		printf("成功付款，找您%d元",change);
	}
	else if((pay == 1 || pay == 2 || pay == 5) && pay < sum)
	{
		while(amount < (sum - pay)){
			printf("金额不足，请继续付款\n");
			scanf("%d",&i);
			if(i == 1 || i == 2 || i == 5){
				amount += i;
			}
			else{
				printf("您只能一次支付一元、二元或五元\n");
				}
			}
		printf("付款成功，找您%d元\n",amount - sum + pay);
	}
	else
	{
		printf("您只能一次支付一元、二元或五元，请重新支付。\n");
		goto error;
	}
	printf("是否再次购买?若是，请按1；若不是，按任意键结束购物。");
	scanf("%c",&input);
	input = getchar();
	if(input == '1'){continue;}
	else{break;}
	}
	}printf("货物不足,还剩%d件货物。\n",quantity - amount1);
	printf("是否再次购买?若是，请按2；若不是，按任意键结束购物。");
	char ii;
	scanf("%c",&ii);
	ii = getchar();
	if(ii == '2')goto site1;
	else
	return 0;
}
