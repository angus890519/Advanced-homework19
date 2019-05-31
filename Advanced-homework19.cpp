/* 計算機概論實務-進階練習作業-作業19*/
/* 製作人：郭柏鋒 */
/* 完成時間：2019/05/24 10:00 */
#include <stdio.h>  //函示庫 
#include <stdlib.h> //函示庫
#include <conio.h>  //函示庫
#include <time.h>   //函示庫
#define SIZE 5      //5次 
int compare(int, int); //比較大小的函式
int main(void)
{
	printf("計算機概論實務-進階練習作業-作業19\n");
    printf("製作人：郭柏鋒\n");
	printf("完成時間：2019/05/24 10:00\n");
	printf("-----------------------------------\n");
    int array[SIZE];  //儲存多少組數值
    int i, option, result; //迴圈變數、遊戲者選項、猜測結果
    char GoOn;      //是否繼續下一關的判斷字元

    srand(time(NULL));     //取得亂數種子

    for (i=0; i<SIZE; i++)  //控制產生多少組數值的迴圈
    { 
       array[i]=rand()%14+1;
       if (array[i]==7)  //如果產生的亂數是 7 
           i--;        // i倒退 1, 回去重新產生亂數
    }
   
    i=0;
    do
    {
       if (i<=5)  //斷是否已過全部關卡 
       {
          printf("第%d關：", i+1);
          printf("請選擇(1)比7大，(2)比7小：");
          scanf("%d", &option);
          result=compare(option, array[i]);
          
          if (result==1)  //猜對了
          {
              printf("恭喜您過關了，繼續挑戰下一關(y/n)：");
              GoOn=getche();
              printf("\n");
          }
          else  /* 猜錯了 */
          {
              printf("對不起您猜錯了，挑戰失敗\n");
              GoOn='n';
          }
          i++;
       }
       else 
	   {
           printf("恭喜您全部過關了...\n");
           GoOn='n';
       }
    } while(GoOn=='y');
    system("pause");//暫停視窗 
    return 0;//回傳值 0 
}

int compare(int option, int number)  /* 判斷比 7 大或小的函式 */
{ 
    switch(option)
    {
        case 1:  /* 選擇比 7 大的判斷 */
            if (number>7)
            {
                printf("結果是%d比7大\n", number);
                return 1;
            }
            else
            {
                printf("結果是%d比7小\n", number);
                return 0;
            }
        case 2:  /* 選擇比 7 小的判斷 */
            if (number<7)
            {
                printf("結果是%d比7小\n", number);
                return 1;
            }
            else
            {
                printf("結果是%d比7大\n", number);
                return 0;
            }
            default:
                return 0;
    }
}

