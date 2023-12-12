#include<stdio.h>
#include<math.h>

int main()
{
    int batch, stu, sub, f1, f2, f3, marks, mode, count, i, p;
    double sum=0, mean=0, variance=0, std_deviation=0, var_sum=0,j;
    printf("Enter Number of batch, student in each Batch and Subject:\n");
    scanf("%d%d%d",&batch,&stu,&sub);
    int student[batch][stu];

// Mean:
    for(f1=0 ; f1<batch ; f1++)
    {
        for(f2=0 ; f2<stu ; f2++)
        {
            marks = 0;
            for(f3=0 ; f3<sub ; f3++)
            {
                printf("Enter num in sub:%d of batch:%d, roll:%d is: ",f3+1,f1+1,f2+1);
                scanf("%d",&i);
                marks = marks + i;
            }
            student[f1][f2] = marks;
            sum = sum + student[f1][f2];                                                                                                                                                                                                                                                                                                                              
        }
    }

    mean = sum/(batch*stu);

// variance & Standart deviation :
    for(f1=0 ; f1<batch ; f1++)
    {
        for(f2=0 ; f2<stu ; f2++)
        {
            j=0;
            j=pow((student[f1][f2]-mean),2);
            var_sum = var_sum + j;
        }
    }
    variance = var_sum / (batch*stu-1);    
    
    std_deviation=sqrt(variance);

    printf("Mean : %.2lf\n",mean);
    printf("Variance : %.2lf\n",variance);
    printf("Standard Deviation : %.2lf\n",std_deviation);

// Mode :
    f3=0, mode=0;
    for(f1=0 ; f1<batch ; f1++)
    {
        for(f2=0 ; f2<stu ; f2++)
        {
            count = 0;
            for(i=0 ; i<batch ; i++)
            {
                for(p=0 ; p<stu ; p++)
                {
                    if( student[f1][f2] == student[i][p] )
                    {
                        count = count+1;
                    }
                }   
            }
            if(f3<count) 
            {
                f3=count;
                mode=student[f1][f2];
            }        
        }
    }
    
    printf("Most students got : %d marks.( %d people.)\n",mode,f3);

// Warning students :
    printf("Send warning letter to these students:\n");
    i=0;
    for(f1=0 ; f1<batch ; f1++)
    {
        for(f2=0 ; f2<stu ; f2++)
        {
            if(student[f1][f2] < mean-std_deviation)
            {
                printf("Std ID-Bat:%d Roll:%d ; Who got : %d.\n",f1+1,f2+1, student[f1][f2]);
                printf("\nYour Son/Daughter,\nStd. ID-B:%d R:%d got %d number in Course-C which is below standard. It is a fair warning to the student. We will take severe action if this repeats.\nFrom,\nThe Office,\nIIT.\n",f1+1,f2+1,student[f1][f2]);
                i++;
            }
        }
    }
    if(i==0)
    {
        printf("No one got warning letter.\n");
    }
}