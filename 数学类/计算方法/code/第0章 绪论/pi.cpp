#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_INT 2147483647

void Caculate_pi()
{
	double x = 2, z = 2;
	int a = 1, b = 3;
	while (z > 1e-15)
	{
		z = z*a / b;
		x += z;
		a++;
		b += 2;
	}

	printf("PI = %.16f\n", x);
}

/* function: 计算任意位数pi值 */
void Caculate_pi_symbol()
{
	int len, i;                                      //len为小数长度  
	int numberator = 1, denominator = 3, result, carry;
	int flag = 1, count = 0;                         //继续循环的标志及循环的次数  
	char *pi, *temp;                                 //指向保存pi值和临时计算结果的数据  
	printf("Please input the number of decimal digits: ");
	scanf("%d", &len);

	len += 2;                                       //增加两位  
	if (!(pi = (char*)malloc(sizeof(char)*len)))     //分配保存pi值的内存  
	{
		printf("malloc memeory failed！\n");
		exit(0);
	}
	if (!(temp = (char*)malloc(sizeof(char)*len)))   //分配保存呢临时值的内存  
	{
		printf("malloc memeory failed！\n");
		exit(0);
	}

	for (i = 0; i < len; i++)                        //初始化数组  
	{
		pi[i] = temp[i] = 0;
	}
	pi[1] = 2;                                      //置初值  
	temp[1] = 2;

	while (flag && (++count < MAX_INT))             //int的最大值 2147483647  
	{
		carry = 0;
		for (i = len - 1; i > 0; i--)                  //从低位到高位相乘  
		{
			result = temp[i] * numberator + carry;    //用每一位去乘，再加上进位  
			temp[i] = result % 10;                  //保存个数  
			carry = result / 10;                    //进位  
		}

		carry = 0;
		for (i = 0; i < len; i++)                    //有高位到低位进行除法运算  
		{
			result = temp[i] + carry * 10;            //当前位加上前一位的余数  
			temp[i] = result / denominator;         //当前位的整数部分  
			carry = result % denominator;           //当前位的余数，累加到下一位的运算  
		}
		flag = 0;                                   //清除标志  

		for (i = len - 1; i > 0; i--)
		{
			result = pi[i] + temp[i];               //将计算结果累加到result中  
			pi[i] = result % 10;                    //保留一位  
			pi[i - 1] += result / 10;                 //向高位进位  
			flag |= temp[i];                        //若temp中的数全为0,退出循环  
		}
		numberator++;                               //累加分子  
		denominator += 2;                           //累加分母  
	}

	printf("Computed %d times\n\n", count);         //输出循环次数  
	printf("PI = ");
	printf("%d.", pi[1]);
	for (i = 2; i < len; i++)
	{
		if ((i>2) && (i - 2) % 10 == 0)                  //每10位小数间加一个空格  
			printf(" ");
		if ((i>2) && (i - 2) % 50 == 0)                  //每50位小数换行  
			printf("\n");

		printf("%d", (int)pi[i]);                    //输出一位小数  
	}
	printf("\n");
}

void main()
{
	Caculate_pi();
	Caculate_pi_symbol();
}