#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//student's basic data.
struct student_data
{
    char name[100];
    char id[100];
    char score_math[100];
    char score_English[100];
};

//function of start menu.
void menu();

int main()
{
    struct student_data student[100];
    int i = 0, choose, student_num, flag = 1;
    char what_txt[100], input_data[100], test[100], another_txt[100];
    FILE *fp, *fo;

    printf("輸入所要開啟之檔案名稱\n");

    //input your file's name.
    scanf("%s",what_txt);
    fp = fopen(what_txt,"r");

    if(fp == NULL)
    {
        printf("error!!\n");
    }


    while(1)
    {
        printf("\n");
        menu();

        //input what you want to do.
        scanf("%d",&choose);
        switch(choose)
        {

        //choose 1 :read student's data.
        case 1:
            while(fgets(input_data,50,fp)!=NULL)
            {
                //using string to save integer like id or scores.
                sscanf(input_data,"%s,%s,%s,%s",student[i].id ,student[i].name ,student[i].score_math ,student[i].score_English);
                printf("%s%s%s%s\n",student[i].id ,student[i].name ,student[i].score_math ,student[i].score_English);
                i++;
            }
            student_num = i;
            break;

        //choose 2 :present student's data.
        case 2:
            for(i = 0; i < student_num; i++)
                printf("%s%s%s%s\n",student[i].id ,student[i].name ,student[i].score_math ,student[i].score_English);
            break;

        //choose 3 :save the initial data ,but has another name.
        case 3:
            printf("Input the name of file you want.\n");
            scanf("%s",another_txt);

            //open another file.
            fo = fopen(another_txt,"w");
            for(i = 0; i < student_num; i++)
            {
                //save  the file you name.
                fprintf(fo, "%s%s%s%s\n",student[i].id ,student[i].name ,student[i].score_math ,student[i].score_English);
            }
            break;

        case 0:
            flag = 0;
            break;
        }
        if(flag == 0)
        break;
    }
    fclose(fo);
    fclose(fp);
    return 0;
}
void menu()
{
    printf("What do you want to do?\n");
    printf("1) Read data from file.\n");
    printf("2) Show data.\n");
    printf("3) Write data to file.\n");
    printf("\n");
    printf("0) Exit the program.\n");
}
