#include<stdio.h>
#include<string.h>

struct let {
    char nam[20];
    int id;
    double cgpa;
};
void input(struct let *student){
    int i;
    printf(".... Input ....\n");
    for(i = 0;i<10;i++) scanf("%s%d%lf",student[i].nam,&student[i].id,&student[i].cgpa);
    return;

}
void output(struct let *student){
    int i;
    printf(".... Output ....\n");
    for(i = 0;i<10;i++) printf("%d %s %.2lf\n",student[i].id,student[i].nam,student[i].cgpa);
    return;
}
void sort(struct let *student, int ck){
    int i,j;
    struct let temp;
    for(i = 0;i<10;i++){
        for(j = i;j<10;j++){
            if((ck==1 && strcmp(student[i].nam,student[j].nam)>0)||
               (ck==2 && student[i].id>student[j].id            )||
               (ck==3 && student[i].cgpa<student[j].cgpa        )){
                temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }
}

int main()
{
    struct let student[10];

    input(student);
    //output(student);

    sort(student,1);
    output(student);

    return 0;
}
