#include<stdio.h>
int main()
{
	int sum = 0;
	int pay = 0;
	int amount = 0;
	int i;
	printf("请输入购买商品的总价");
	scanf("%d",&sum);
	error:
	printf("请付款");
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
		printf("付款成功，找您%d元",amount - sum + pay);
	}
	else
	{
		printf("您只能一次支付一元、二元或五元，请重新支付。\n");
		goto error;
	}
return 0;
}