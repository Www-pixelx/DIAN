#include <stdio.h>
#include <string.h>
#include <windows.h>

int NUMBER[5] = {0}; // 每个通道的货物数量
char NAME[5][5]; // 储存货物的名称
int UNIT[5]; // 每种货物的单价
const int MAX = 50; // 一个通道最多的货物数量
int sum = 0; // 初始化sum

// 定义函数 货物摆放
void LAYOUT(char goods, int channel, int qnty, int price) {
    while (1) { // 重新摆放货物的循环
        printf("请输入摆放货物的名称、通道、单价和数量(用空格隔开)\n");
        scanf(" %c", &goods);
        scanf(" %d", &channel);
        scanf(" %d", &price);
        scanf(" %d", &qnty);
        while (getchar() != '\n'); // 清空缓存区
        int mark;
        if (channel < 1 || channel > 5) {
            mark = 1; // 通道输入错误
        } else if (NUMBER[channel - 1] != 0 && strcmp(NAME[channel - 1], &goods) != 0) {
            mark = 2; // 放的货物与通道原有货物不同
        } else if (NUMBER[channel - 1] != 0 && strcmp(NAME[channel - 1], &goods) == 0 && price != UNIT[channel - 1]) {
            mark = 3; // 货物单价输入不同
        } else if ((NUMBER[channel - 1] != 0 && strcmp(NAME[channel - 1], &goods) == 0 && price == UNIT[channel - 1]) || NUMBER[channel - 1] == 0) {
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
            case 4:
                NUMBER[channel - 1] += qnty;
                if (NUMBER[channel - 1] > MAX) {
                    printf("一个通道最多容纳50个货物。\n");
                    NUMBER[channel - 1] -= qnty;
                } else {
                    UNIT[channel - 1] = price;
                    strcpy(NAME[channel - 1], &goods);
                    printf("%d: %c * %d 单价%d元\n", channel, goods, NUMBER[channel - 1], price);
                    char in[4];
                    printf("是否再次摆放？输入END结束摆放;输入任意值再次摆放。\n");
                    scanf("%3s", in);
                    while (getchar() != '\n'); // 清空缓存区
                    if (strcmp(in, "END") == 0) return;
                }
                break;
            case 5:
                printf("请正确输入\n");
                break;
        }
    }
    printf("最终摆放情况:\n");
    for (int t = 0; t < 5; t++) {
        if (NUMBER[t] != 0) printf("%d: %s * %d 单价%d元\n", t + 1, NAME[t], NUMBER[t], UNIT[t]);
    }
}

// 定义函数 货物购买
int PURCHASE(char goods, int channel, int qnty, int price) {
    while (1) {
        printf("输入购买货物的名称、通道和个数(用空格隔开)\n");
        scanf(" %c", &goods);
        scanf(" %d", &channel);
        scanf(" %d", &qnty);
        while (getchar() != '\n');
        if (channel < 1 || channel > 5) {
            printf("通道号必须在1到5之间\n");
        } // 检验通道
        else if (strcmp(NAME[channel - 1], &goods) != 0) {
            printf("此通道无该货品\n");
        } // 检验货物
        else if (qnty > NUMBER[channel - 1]) {
            printf("货物不足\n");
        } // 检验数量
        else {
            sum += UNIT[channel - 1] * qnty; // 计算总价
            NUMBER[channel - 1] -= qnty; // 减去相应通道的货物数量
            printf("成功购买%d通道货物%c共%d个\n是否继续购买？结束购买输入END;继续购买输入任意值\n", channel, goods, qnty);
            char input[4];
            scanf("%3s", input);
            while (getchar() != '\n');
            if (strcmp(input, "END") == 0) break;
        }
    }
    return sum;
}

// 定义函数 付款
void PAYMENT(int num, int pay, int amount) {
    printf("总价%d元，请付款\n", sum);
    while (1) {
        scanf("%d", &pay);
        while (getchar() != '\n');
        amount += pay;
        if ((pay == 1 || pay == 2 || pay == 5) && amount >= sum) {
            printf("成功付款，找您%d元。\n", amount - sum);
            amount = 0;
            break;
        } else if ((pay == 1 || pay == 2 || pay == 5) && amount < sum) {
            printf("剩%d元未付清，请继续付款\n", sum - amount);
        } else {
            printf("您只能一次支付一元、二元或五元，请重新支付。\n");
            amount -= pay;
        }
    }
}

int main() {
    #define CP_UTF8 65001
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    char goods;
    int channel, qnty, price, num, pay, amount = 0;
    LAYOUT(goods, channel, qnty, price);
    while (1) {
        sum = PURCHASE(goods, channel, qnty, price);
        PAYMENT(num, pay, amount);
        printf("是否再次购买？\n退出购买请输入END；继续购买，输入任意值。\n"); // 是否回购
        char i[4];
        scanf("%3s", i);
        while (getchar() != '\n');
        if (strcmp(i, "END") == 0) break; // 检验输入END
    }
    printf("谢谢惠顾！");
    return 0;
}
