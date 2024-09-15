#include<stdio.h>
int main()
{
	int sum = 0;//总价
	int pay = 0;//每次付的钱
	int amount = 0;//总付款
	printf("请输入购买商品的总价");
	scanf("%d",&sum);
	printf("请付款");
	while(1){
	scanf("%d",&pay);
	amount += pay;
	if((pay == 1 || pay == 2 || pay == 5) && amount >= sum){
		printf("成功付款，找您%d元\n",amount - sum);
		break;}
	else if((pay == 1 || pay == 2 || pay == 5) && amount < sum){
	printf("金额不足，剩%d元未付清，请继续付款\n",sum - amount);
	continue;}		
	else
	{
		printf("您只能一次支付一元、二元或五元，请重新支付。\n");	
	}
}printf("谢谢惠顾！");
return 0;
}
