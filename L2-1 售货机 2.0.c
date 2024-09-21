#include <stdio.h>
#include <string.h>
#include <windows.h>
int main(){
	#define CP_UTF8 65001
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
	//摆放货物
	int p[5] = {0};//每个通道的货物数量
	int mark[5] = {0} ;//空通道标记为 0
	char goods;
	char g[5];//储存货物的名称
	int pr[5];//每种货物的单价
	int pass,qnty,price;
	const int MAX = 50;//一个通道最多的货物数量
	while(1){//回购的循环
	while(1){//重新选择货物的循环
	   printf("请输入摆放货物的名称、通道、单价和数量(用空格隔开)\n");
	   scanf(" %c %d %d %d",&goods,&pass,&price,&qnty);
	   while (getchar() != '\n');
	   if (pass < 1 || pass > 5) {
            printf("通道号必须在1到5之间。\n");//通道输入错误
			}
		else if(qnty > MAX){
			printf("一个通道最多容纳50个货物。\n");//一次摆放货物过多
		}
	    else if(mark[pass - 1] == 1 && goods != g[pass-1]) {
		printf("该通道已被占用\n");//放的货物与通道原有货物不同
	   }
	    else if((mark[pass-1] == 1 && goods == g[pass-1]) || mark[pass-1] == 0){//正确摆放
	   	p[pass-1] += qnty;//增加相应通道的货物数量
	   	if(p[pass-1] > MAX){
	   	printf("一个通道最多容纳50个货物。\n");//第二次摆放后货物过多
	   	p[pass-1]-=qnty;}
		else{
	   mark[pass - 1] = 1;//有货标记为 1
	   pr[pass - 1] = price;//储存货物价格
	   g[pass-1] = goods;//储存货物名称
	   printf("%d: %c * %d 单价%d元\n",pass,goods,p[pass-1],price);
	   char in[4];
	   printf("是否再次摆放？输入END结束摆放;输入任意值再次摆放。\n");
	   scanf("%3s",in);
	   while (getchar() != '\n');//清空缓存区
	   if(strcmp(in,"END") == 0) break;}//检验输入END
	   }
	   else {printf("请正确输入");}//有人乱输
}
	printf("最终摆放情况:\n");
	for(int t = 0;t <= 4;t++){
		if(mark[t] == 1) printf("%d: %c * %d 单价%d元\n",t+1,g[t],p[t],pr[t]);
	}
	//选择货物
	int sum = 0;
	while(1){
printf("输入购买货物的名称、通道和个数(用空格隔开)\n");
scanf(" %c %d %d",&goods,&pass,&qnty);
if (pass < 1 || pass > 5) {printf("通道号必须在1到5之间\n");}//检验通道
else if(goods != g[pass-1]) {printf("此通道无该货品\n");}//检验货物
else if (qnty > p[pass - 1]) {printf("货物不足\n");}//检验数量
else{sum += pr[pass - 1]*qnty;//计算总价
    p[pass - 1] -= qnty;//减去相应通道的货物数量
	printf("成功购买\n是否继续购买？结束购买输入END;继续购买输入任意值\n");
	char input[4];
	scanf("%3s",input);
	   while (getchar() != '\n');
	   if(strcmp(input,"END") == 0) break;
}
}
//付款
int num;//购买的数量
int pay;//每次付的钱
int amount;//总付款
printf("总价%d元，请付款",sum);
	while(1){
	scanf("%d",&pay);
	amount += pay;
	if((pay == 1 || pay == 2 || pay == 5) && amount >= sum){
		printf("成功付款，找您%d元。\n",amount - sum);
		amount = 0;
		break;}
	else if((pay == 1 || pay == 2 || pay == 5) && amount < sum){
	    printf("剩%d元未付清，请继续付款\n",sum - amount);
	    continue;}		
	else{
		printf("您只能一次支付一元、二元或五元，请重新支付。\n");
		amount -= pay;	
	    }
}
printf("是否再次购买？\n退出购买请输入END；继续购买，输入任意值。");//是否回购
char i[4];
scanf("%3s",i);
while (getchar() != '\n');
if(strcmp(i, "END") == 0)break;
}
exit:
printf("谢谢惠顾！");
		return 0;
	}
	
	
