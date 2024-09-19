#include <stdio.h>
#include <string.h>
int main()
{//摆放货物
	int price,qnty;
	printf("货物名称：A ;通道：1\n请输入摆放货物的单价");
	scanf("%d",&price);
	printf("请输入摆放货物的个数（<=50)");
	while(1){
		scanf("%d",&qnty);
		if(qnty>50){
		printf("您最多只能摆放50件货物，请重新输入\n");
		continue;}
	    else{
	    printf("已在1通道摆放A货物%d个，单价%d元。\n",qnty,price);
	    break;}
		}
		//付款
	int num;//购买的数量	
	int sum;//总价
	int pay;//每次付的钱
	int amount;//总付款
	char i[100],ii[100];
	while(1){
	while(1){
	printf("剩%d件货物，单价%d元，请输入购买商品的数量",qnty,price);
	scanf("%d",&num);
	if(num <= qnty) {
	qnty -= num;
	break;}
	else {
	printf("货物不足，剩%d件货物。是否重新选择货物数量？\n退出购买请输入END；继续购买，输入任意值。",qnty);
	scanf("%s",&i);
	if(strcmp(i, "END") == 0) goto exit;
	else continue;
	}
    }
    sum = price * num;
	printf("总价%d元，请付款",sum);
	while(1){
	scanf("%d",&pay);
	amount += pay;
	if((pay == 1 || pay == 2 || pay == 5) && amount >= sum){
		printf("成功付款，找您%d元。\n",amount - sum);
		amount = 0;
		break;}
	else if((pay == 1 || pay == 2 || pay == 5) && amount < sum){
	    printf("金额不足，剩%d元未付清，请继续付款\n",sum - amount);
	    continue;}		
	else{
		printf("您只能一次支付一元、二元或五元，请重新支付。\n");
		amount -= pay;	
	    }
}
printf("是否再次购买？\n退出购买请输入END；继续购买，输入任意值。");
scanf("%s",&ii);
if(strcmp(ii, "END") == 0)break;
else continue;
}
exit:
printf("谢谢惠顾！");
return 0;
}
