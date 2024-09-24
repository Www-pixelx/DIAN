#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX 50// 一个通道最多的货物数量
int NUMBER[5] = {0}; // 每个通道的货物数量
char NAME[5][5]; // 储存通道里的货物的名称
int UNIT[5]; // 每种货物的单价
int sum = 0; // 购买货物的总金额
char goods[4];//摆放的货物名（检验END）
int channel, qnty, price;//通道、购买数量、单价
char item[4];//购买时检验货物名（检验END）

// 定义函数 货物摆放

void LAYOUT() {
	printf("请依次输入摆放货物的名称、通道、单价和数量(用空格隔开)\n输入END结束摆放\n");
    while (1) { // 重新摆放货物的循环
        scanf(" %3s",goods);
        if (strcmp(goods, "END") == 0) break;//输入END就结束
        scanf(" %d %d %d",&channel, &price, &qnty);
        while (getchar() != '\n'); // 清空缓存区
        int mark;//case里的数
		if (channel < 1 || channel > 5) {
            mark = 1; // 通道输入错误
        } else if (NUMBER[channel - 1] != 0 && strcmp(NAME[channel - 1], goods) != 0) {
            mark = 2; // 放的货物与通道原有货物不同
        } else if (NUMBER[channel - 1] != 0 && strcmp(NAME[channel - 1], goods) == 0 && price != UNIT[channel - 1]) {
            mark = 3; // 货物单价输入不同
        } else if ((NUMBER[channel - 1] != 0 && strcmp(NAME[channel - 1], goods) == 0 && price == UNIT[channel - 1]) || NUMBER[channel - 1] == 0) {
            mark = 4; // 正确摆放
        } else {
            mark = 5; // 有人乱输
        }
        switch (mark) {
            case 1:
                printf("通道号必须在1到5之间。\n");
                break;
            case 2:
                printf("该通道已被占用\n");
                break;
            case 3:
                printf("单价输入有误。\n");
                break;
            case 4://正确摆放
                NUMBER[channel - 1] += qnty;
                if (NUMBER[channel - 1] > MAX) {//检验第n次摆放后货物是否过多
                    printf("一个通道最多容纳50个货物。\n");
                    NUMBER[channel - 1] -= qnty;
                } else {
                    UNIT[channel - 1] = price;//记录单价
                    strcpy(NAME[channel - 1], goods);//记录该通道里的货物名
                }
                break;
            case 5:
                printf("请正确输入\n");
                break;
        }
    }
    printf("最终摆放情况:\n");//遍历显示摆放情况
    for (int t = 0; t < 5; t++) {
        if (NUMBER[t] != 0) printf("%d: %s * %d 单价%d元\n", t + 1, NAME[t], NUMBER[t], UNIT[t]);
    }
}

// 定义函数 货物购买

int PURCHASE() {
	printf("请依次输入购买货物的名称、通道和个数(用空格隔开)\n输入END结束购买\n");
    while (1) {
        scanf(" %3s",item);
        if (strcmp(item, "END") == 0) break;//检验END
        scanf(" %d %d", &channel,&qnty);
        while (getchar() != '\n');
        if (channel < 1 || channel > 5) {
            printf("通道号必须在1到5之间\n");
        } // 检验通道
        else if (strcmp(NAME[channel - 1], item) != 0) {
            printf("此通道无该货品\n");
        } // 检验货物
        else if (qnty > NUMBER[channel - 1]) {
            printf("货物不足,该通道剩货品%d件\n", NUMBER[channel-1]);
        } // 检验数量
        else {
            sum += UNIT[channel - 1] * qnty; // 计算总价
            NUMBER[channel - 1] -= qnty; // 减去相应通道的货物数量
        }
    }
    return sum;
}

// 定义函数 付款

void PAYMENT() {
	int num, pay, amount = 0;//购买数量、一次付的款、付款总额
    printf("总价%d元，请付款\n", sum);
    while (1) {
        scanf("%d", &pay);//一次付款
        while (getchar() != '\n');
        amount += pay;//把付的款加入付款总额
        if ((pay == 1 || pay == 2 || pay == 5) && amount >= sum) {//付款完成
            printf("成功付款，找您%d元。\n", amount - sum);
            amount = 0;//总额清零，避免影响回购
            break;
        } else if ((pay == 1 || pay == 2 || pay == 5) && amount < sum) {//付款不足
            printf("剩%d元未付清，请继续付款\n", sum - amount);
        } else {
            printf("您只能一次支付一元、二元或五元，请重新支付。\n");//付款不正确
            amount -= pay;
        }
    }
}

int main() {
	
    #define CP_UTF8 65001
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    //先摆放，再购买，再付款，最后询问是否回购
    LAYOUT();
    while (1) {//回购的循环
        sum = PURCHASE();
        if(sum == 0) break;//假如并未购买货物，直接退出，不再询问是否再次购买（售货机货物不足或顾客不想买了）
        PAYMENT();
        printf("是否再次购买？\n退出购买请输入END；继续购买，输入任意值。\n"); // 是否回购
        char i[4];
        scanf("%3s", i);
        while (getchar() != '\n');
        if (strcmp(i, "END") == 0) break; // 检验输入END
    }
    printf("谢谢惠顾！");
    return 0;
	}
