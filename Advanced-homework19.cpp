/* �p������׹��-�i���m�ߧ@�~-�@�~19*/
/* �s�@�H�G���f�W */
/* �����ɶ��G2019/05/24 10:00 */
#include <stdio.h>  //��ܮw 
#include <stdlib.h> //��ܮw
#include <conio.h>  //��ܮw
#include <time.h>   //��ܮw
#define SIZE 5      //5�� 
int compare(int, int); //����j�p���禡
int main(void)
{
	printf("�p������׹��-�i���m�ߧ@�~-�@�~19\n");
    printf("�s�@�H�G���f�W\n");
	printf("�����ɶ��G2019/05/24 10:00\n");
	printf("-----------------------------------\n");
    int array[SIZE];  //�x�s�h�ֲռƭ�
    int i, option, result; //�j���ܼơB�C���̿ﶵ�B�q�����G
    char GoOn;      //�O�_�~��U�@�����P�_�r��

    srand(time(NULL));     //���o�üƺؤl

    for (i=0; i<SIZE; i++)  //����ͦh�ֲռƭȪ��j��
    { 
       array[i]=rand()%14+1;
       if (array[i]==7)  //�p�G���ͪ��üƬO 7 
           i--;        // i�˰h 1, �^�h���s���Ͷü�
    }
   
    i=0;
    do
    {
       if (i<=5)  //�_�O�_�w�L�������d 
       {
          printf("��%d���G", i+1);
          printf("�п��(1)��7�j�A(2)��7�p�G");
          scanf("%d", &option);
          result=compare(option, array[i]);
          
          if (result==1)  //�q��F
          {
              printf("���߱z�L���F�A�~��D�ԤU�@��(y/n)�G");
              GoOn=getche();
              printf("\n");
          }
          else  /* �q���F */
          {
              printf("�藍�_�z�q���F�A�D�ԥ���\n");
              GoOn='n';
          }
          i++;
       }
       else 
	   {
           printf("���߱z�����L���F...\n");
           GoOn='n';
       }
    } while(GoOn=='y');
    system("pause");//�Ȱ����� 
    return 0;//�^�ǭ� 0 
}

int compare(int option, int number)  /* �P�_�� 7 �j�Τp���禡 */
{ 
    switch(option)
    {
        case 1:  /* ��ܤ� 7 �j���P�_ */
            if (number>7)
            {
                printf("���G�O%d��7�j\n", number);
                return 1;
            }
            else
            {
                printf("���G�O%d��7�p\n", number);
                return 0;
            }
        case 2:  /* ��ܤ� 7 �p���P�_ */
            if (number<7)
            {
                printf("���G�O%d��7�p\n", number);
                return 1;
            }
            else
            {
                printf("���G�O%d��7�j\n", number);
                return 0;
            }
            default:
                return 0;
    }
}

