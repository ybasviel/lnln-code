#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int findint(int x,int *arr, int max) //配列の要素から整数を探す
{
    int t;

    for(t = 0; t < max; t++)
    {
        if(x == arr[t])
        {
            return t;
        }
    }

    return -1;
}


int findchar(char x,char *arr,int max) //配列の要素から文字を探す
{
    int t;
    for(t = 0; t < max; t++)
    {
        if(x == arr[t])
        {
            return t;
        }
    }

    return -1;
}

void nextint(int *arr, int size) //配列の要素を全体に1つずらす．最後尾は最前にもってくる．
{
    int keep;
    keep = arr[size-1];

    int i;
    for(i=size-2; i >= 0; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[0] = keep;
}


void shuffleint(int *arr, int size) //配列をシャッフルする
{
    int i,j,t;
    for(i = 0; i < size; i++)
    {
        j = rand()%size;
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

void encrypt(char *text, int s1, int s2,int s3, int s4, int *n1, int *n2, int *n3, char *alphabets)
{
    int key,i;
    int count = 0;

    srand(s4);
    shuffleint(n1,62);
    shuffleint(n2,62);
    shuffleint(n3,62);

    for(i = 0; i < s1; i++)
    {
        nextint(n1,62);
    }
    for(i = 0; i < s2; i++)
    {
        nextint(n2,62);
    }
    for(i = 0; i < s3; i++)
    {
        nextint(n3,62);
    }

    for(i = 0; i < strlen(text); i++)
    {
        if(findchar(text[i],alphabets,62) != -1)
        {
            key = findchar(text[i],alphabets,62);
            key = n1[key];
            key = n2[key];
            key = n3[key];

            key = 61 - key;

            key = findint(key,n3,62);
            key = findint(key,n2,62);
            key = findint(key,n1,62);

            text[i] = alphabets[key];
            count++;
        }

        nextint(n1,62);
        if(count%62 == 0) nextint(n2,62);
        if(count%(62*62) == 0) nextint(n3,62);
   
    }
}


int main(int argc, char *argv[])
{
    char alphabets[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};

    int n1[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61};
    int n2[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61};
    int n3[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61};

    srand(time(NULL));
    char text[4000];
    int set1 = -1;
    int set2 = -1;
    int set3 = -1;
    int set4 = -1;

    if(argc == 1)
    {

        printf("暗号化(復号)する文章を入力(英文100字以内，空白なし)\n");
        scanf("%s",text);

        printf("暗号化のプリセットを入力\n任意の自然数を4つ(-1でランダム)\n");
        printf("1つめ > "); scanf("%d",&set1);
        printf("2つめ > "); scanf("%d",&set2);
        printf("3つめ > "); scanf("%d",&set3);
        printf("4つめ > "); scanf("%d",&set4);

        if(set1 == -1)
        {
            set1 = rand()%62;
        }
        if(set2 == -1)
        {
            set2 = rand()%62;
        }
        if(set3 == -1)
        {
            set3 = rand()%62;
        }
        if(set4 == -1)
        {
            set4 = rand()%100;
        }

        encrypt(text,set1,set2,set3,set4,n1,n2,n3,alphabets);

        printf("%s",text);
    }
    else if(argc == 3)
    {
        FILE *fp;
        FILE *newfp;
        fp = fopen(argv[1],"r");
        newfp = fopen(argv[2], "w+");


        if(fp == NULL)
        {
            printf("ファイルが開けませんでした\n");
            return 0;
        }

            printf("暗号化のプリセットを入力\n任意の自然数を4つ(-1でランダム)\n");
            printf("1つめ > "); scanf("%d",&set1);
            printf("2つめ > "); scanf("%d",&set2);
            printf("3つめ > "); scanf("%d",&set3);
            printf("4つめ > "); scanf("%d",&set4);

            if(set1 == -1)
            {
                set1 = rand()%62;
            }
            if(set2 == -1)
            {
                set2 = rand()%62;
            }
            if(set3 == -1)
            {
                set3 = rand()%62;
            }
            if(set4 == -1)
            {
                set4 = rand()%100;
            }

            while(fgets(text, 4000, fp) != NULL)
            {
                encrypt(text,set1,set2,set3,set4,n1,n2,n3,alphabets);
                fprintf(newfp,"%s", text);
            }
        fclose(fp);
    }
    else if(argc != 3)
    {
        printf("引数が正しくありません．\n1-i.out filepath1 filepath2\n");
        return 0;
    }

    printf("(%d,%d,%d,%d)\n",set1,set2,set3,set4);
    return 0;
}