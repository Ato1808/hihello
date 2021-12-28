#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct student
{
    char student_id[MAX][10];
    char name[MAX][50];
    int age[MAX];
    char gender[MAX][5];
    float score_math[MAX];
    float score_physics[MAX];
    float score_chemistry[MAX];
    float gpa[MAX];
    char acedemic_ranking[MAX][50];
}stu;
typedef struct student_modify
{
    char student_id_m[10];
    char name_m[50];
    int age_m;
    char gender_m[5];
    float score_math_m;
    float score_physics_m;
    float score_chemistry_m;
}stu_m;
typedef struct student_addition
{
    char student_id_a[10];
    char name_a[50];
    int age_a;
    char gender_a[5];
    float score_math_a;
    float score_physics_a;
    float score_chemistry_a;
}stu_a;
typedef struct student_recycle
{
    char student_id_r [MAX][10];
    char name_r [MAX][50];
    int age_r[MAX];
    char gender_r [MAX][5];
    float score_math_r[MAX];
    float score_physics_r[MAX];
    float score_chemistry_r[MAX];
}stu_r;
typedef struct student_sort
{
    char student_id_s[MAX][10];
    char name_s[MAX][50];
    int age_s[MAX];
    char gender_s[MAX][5];
    float gpa_s[MAX];
    char acedemic_ranking_s[MAX][50];
}stu_s;
void infor_default ( stu *infor )
{
                    /*Student ID*/
    strcpy ((*infor).student_id[0], "SE001");
    strcpy ((*infor).student_id[1], "SS002");
    strcpy ((*infor).student_id[2], "SS003");
                    /*Name*/
    strcpy ((*infor).name[0], "Nguyen Tran Gia Bao");
    strcpy ((*infor).name[1], "Pham Mai Bao Tran");
    strcpy ((*infor).name[2], "Huong Tra");
                    /*Age*/
    (*infor).age[0] = 18;
    (*infor).age[1] = 16;
    (*infor).age[2] = 17;
                    /*Gender*/
    strcpy ((*infor).gender[0], "Nam");
    strcpy ((*infor).gender[1], "Nu");
    strcpy ((*infor).gender[2], "Nu");
                    /*Score*/
    (*infor).score_math[0] = 5; (*infor).score_physics[0] = 4.5; (*infor).score_chemistry[0] = 3;
    (*infor).score_math[1] = 6.5; (*infor).score_physics[1] = 8; (*infor).score_chemistry[1] = 8;
    (*infor).score_math[2] = 9; (*infor).score_physics[2] = 8.5; (*infor).score_chemistry[2] = 9.5;
}
void menu ()
{
    printf ("\n%76s\n", "===== Menu =====");
    printf ("\n\t%s", "[=== #1 ===]");
    printf ("%54s", "[=== #2 ===]");
    printf ("%48s", "[=== #3 ===]");
    printf ("\n%s", "Printing the list of students");
    printf ("%48s", "Adding new student");
    printf ("%50s", "Modifying student data");
    printf ("\n");

    printf ("\n\t%s", "[=== #4 ===]");
    printf ("%54s", "[=== #5 ===]");
    printf ("%48s", "[=== #6 ===]");
    printf ("\n%s", "   Deleting student data");
    printf ("%55s", "Restoring student data");
    printf ("%42s", "Recycle Bin");
    printf ("\n");

    printf ("\n\t%s", "[=== #7 ===]");
    printf ("%54s", "[=== #8 ===]");
    printf ("%48s", "[=== #0 ===]");
    printf ("\n%s", "   Searching student data");
    printf ("%60s", "Academic Ranking and Sort by GPA");
    printf ("%38s", "Ending program");
    printf ("\n");    
}
void input_student ( stu *infor, int *num_new_student )
{
    int serial = 0;
    if ((*num_new_student) > MAX)
    {
        printf ("\nStorage of data is not enough (MAX is 100 )");
    }
    else
    {
        for (int i = 3; i < (*num_new_student) + 3; i++)
        {
            ++serial;
            printf ("\n%d - Student information\n", serial);
            printf ("Enter Student ID: ");
            scanf ("%s", &(*infor).student_id[i]);
            strupr ((*infor).student_id[i]);
            int check_0 = strcmp((*infor).student_id[i], (*infor).student_id[0]);
            int check_1 = strcmp((*infor).student_id[i], (*infor).student_id[1]);
            int check_2 = strcmp((*infor).student_id[i], (*infor).student_id[2]);
            while (check_0 == 0 || check_1 == 0 || check_2 == 0)
            {
                printf ("*** Student ID is already in the list ***\n");
                printf ("Please enter another Student ID: ");
                scanf ("%s", &(*infor).student_id[i]);
                strupr ((*infor).student_id[i]);
                check_0 = strcmp((*infor).student_id[i], (*infor).student_id[0]);
                check_1 = strcmp((*infor).student_id[i], (*infor).student_id[1]);
                check_2 = strcmp((*infor).student_id[i], (*infor).student_id[2]);
            }
            fflush(stdin);
            printf ("Enter Name: ");
            gets((*infor).name[i]); 
            printf ("Enter Age: ");
            scanf ("%d", &(*infor).age[i]);
            printf ("Enter Gender: ");
            scanf ("%s", &(*infor).gender[i]);
            printf ("Enter Math score: ");
            scanf ("%f", &(*infor).score_math[i]);
            printf ("Enter Physics score: ");
            scanf ("%f", &(*infor).score_physics[i]);
            printf ("Enter Chemistry score: ");
            scanf ("%f", &(*infor).score_chemistry[i]);
        }
    }
}
void output_student ( stu infor, int num_new_student )
{
    printf ("\n%82s\n", "===== List of students =====");
    printf ("\n%-13s", "[Serial]");
    printf ("%-23s", "[Student ID]"); 
    printf ("%9s", "[Name]"); 
    printf ("%23s", "[Age]"); 
    printf ("%12s", "[Gender]");
    printf ("%16s", "[Math score]"); 
    printf ("%19s", "[Physics score]"); 
    printf ("%21s", "[Chemistry score]"); 
    for (int j = 0; j < num_new_student + 3; j++)
    {   
        printf ("\n   %-13d", j);
        printf ("%-17s", infor.student_id[j]); 
        printf ("%-31s", infor.name[j]); 
        printf ("%-10d", infor.age[j]); 
        printf ("%-14s", infor.gender[j]);
        printf ("%-18.1f", infor.score_math[j]); 
        printf ("%-20.1f", infor.score_physics[j]);
        printf ("%-15.1f", infor.score_chemistry[j]);  
        printf ("\n%s", "**********************************");
        printf ("%s", "**********************************");
        printf ("%s", "**********************************");
        printf ("%s", "**********************************");                  
    }
}
void add_input_student (stu *infor, int *num_new_student, int *pos_add, stu_a *add_infor)
{
    for (int i = ((*num_new_student) + 3) + 1; i > *pos_add; i--)
    {
        strcpy ((*infor).student_id[i], (*infor).student_id[i - 1]);
        strcpy ((*infor).name[i], (*infor).name[i - 1]);
        (*infor).age[i] = (*infor).age[i - 1];
        strcpy ((*infor).gender[i], (*infor).gender[i - 1]);
        (*infor).score_math[i] = (*infor).score_math[i - 1];
        (*infor).score_physics[i] = (*infor).score_physics[i - 1];
        (*infor).score_chemistry[i] = (*infor).score_chemistry[i - 1];
    }
    strcpy ((*infor).student_id[*pos_add], (*add_infor).student_id_a);
    strcpy ((*infor).name[*pos_add], (*add_infor).name_a);
    (*infor).age[*pos_add] = (*add_infor).age_a;
    strcpy ((*infor).gender[*pos_add], (*add_infor).gender_a);
    (*infor).score_math[*pos_add] = (*add_infor).score_math_a; 
    (*infor).score_physics[*pos_add] = (*add_infor).score_physics_a;
    (*infor).score_chemistry[*pos_add] = (*add_infor).score_chemistry_a;                   
    ++(*num_new_student);
}
void modify_input_student ( stu *infor, stu_m *mod_infor, int *pos_mod )
{   
    strcpy ((*infor).student_id[*pos_mod], (*mod_infor).student_id_m);
    strcpy ((*infor).name[*pos_mod], (*mod_infor).name_m);
    (*infor).age[*pos_mod] = (*mod_infor).age_m;
    strcpy ((*infor).gender[*pos_mod], (*mod_infor).gender_m);
    (*infor).score_math[*pos_mod] = (*mod_infor).score_math_m;
    (*infor).score_physics[*pos_mod] = (*mod_infor).score_physics_m;
    (*infor).score_chemistry[*pos_mod] = (*mod_infor).score_chemistry_m;
}
void modify_output_student_search ( stu infor, int pos_search, char search_student[10] )
{
	printf ("\n\t\t\t\t\t\t=====Data of %s after modify=====\n", search_student);
    printf ("%-23s", "[Student ID]"); 
    printf ("%9s", "[Name]"); 
    printf ("%23s", "[Age]"); 
    printf ("%12s", "[Gender]");
    printf ("%16s", "[Math score]"); 
    printf ("%19s", "[Physics score]"); 
    printf ("%21s", "[Chemistry score]"); 
    printf ("\n");
    printf ("   %-17s", infor.student_id[pos_search]); 
    printf ("%-31s", infor.name[pos_search]); 
    printf ("%-10d", infor.age[pos_search]); 
    printf ("%-14s", infor.gender[pos_search]);
    printf ("%-18.1f", infor.score_math[pos_search]); 
    printf ("%-20.1f", infor.score_physics[pos_search]);
    printf ("%-15.1f", infor.score_chemistry[pos_search]); 
    printf ("\n%s", "**********************************");
    printf ("%s", "**********************************");
    printf ("%s", "**********************************");
    printf ("%s", "**********************************");     
}
void delete_input_student ( stu *infor, int *num_new_student, int *pos_del)
{
    for (int i = (*pos_del); i < ((*num_new_student) + 3) - 1; i++)
    {
        strcpy ((*infor).student_id[i], (*infor).student_id[i + 1]);
        strcpy ((*infor).name[i], (*infor).name[i + 1]);
        (*infor).age[i] = (*infor).age[i + 1];
        strcpy ((*infor).gender[i], (*infor).gender[i + 1]);
        (*infor).score_math[i] = (*infor).score_math[i + 1];
        (*infor).score_physics[i] = (*infor).score_physics[i + 1];
        (*infor).score_chemistry[i] = (*infor).score_chemistry[i + 1];
    }
    --(*num_new_student);
}
void input_recycle ( stu *infor, stu_r *infor_r, int *pos_del, int *recycle_student, int *num_recycle_student)
{
    (*num_recycle_student) += 1;
    (*recycle_student) += 1;
    for (int j = *num_recycle_student; j < *recycle_student; j++)
    {
        strcpy ((*infor_r).student_id_r[j], (*infor).student_id[*pos_del]);
        strcpy ((*infor_r).name_r[j], (*infor).name[*pos_del]);
        (*infor_r).age_r[j] = (*infor).age[*pos_del];
        strcpy ((*infor_r).gender_r[j], (*infor).gender[*pos_del]);
        (*infor_r).score_math_r[j] = (*infor).score_math[*pos_del];
        (*infor_r).score_physics_r[j] = (*infor).score_physics[*pos_del];
        (*infor_r).score_chemistry_r[j] = (*infor).score_chemistry[*pos_del];
    }
}
void output_recycle ( stu_r infor_r, int recycle_student)
{     
    printf ("\n\t\t\t\t=====List of students in Recycle Bin=====\n");
    printf ("\n%-13s", "[Serial]");
    printf ("%-23s", "[Student ID]"); 
    printf ("%9s", "[Name]"); 
    printf ("%23s", "[Age]"); 
    printf ("%12s", "[Gender]");
    printf ("%16s", "[Math score]"); 
    printf ("%19s", "[Physics score]"); 
    printf ("%21s", "[Chemistry score]");
    for (int j = 0; j < recycle_student; j++)
    {   
        printf ("\n   %-13d", j);
        printf ("%-17s", infor_r.student_id_r[j]); 
        printf ("%-31s", infor_r.name_r[j]); 
        printf ("%-10d", infor_r.age_r[j]); 
        printf ("%-14s", infor_r.gender_r[j]);
        printf ("%-18.1f", infor_r.score_math_r[j]); 
        printf ("%-20.1f", infor_r.score_physics_r[j]);
        printf ("%-15.1f", infor_r.score_chemistry_r[j]);   
        printf ("\n%s", "**********************************");
        printf ("%s", "**********************************");
        printf ("%s", "**********************************");
        printf ("%s", "**********************************");                 
    }
}
void add_input_student_r (stu *infor, stu_r *infor_r, int *num_new_student, int *pos_add, int *pos_add_r, int *recycle_student)
{
    for (int i = ((*num_new_student) + 3) + 1; i > *pos_add; i--)
    {
        strcpy ((*infor).student_id[i], (*infor).student_id[i - 1]);
        strcpy ((*infor).name[i], (*infor).name[i - 1]);
        (*infor).age[i] = (*infor).age[i - 1];
        strcpy ((*infor).gender[i], (*infor).gender[i - 1]);
        (*infor).score_math[i] = (*infor).score_math[i - 1];
        (*infor).score_physics[i] = (*infor).score_physics[i - 1];
        (*infor).score_chemistry[i] = (*infor).score_chemistry[i - 1];
    }
    strcpy ((*infor).student_id[(*pos_add)], (*infor_r).student_id_r[(*pos_add_r)]);
    strcpy ((*infor).name[(*pos_add)], (*infor_r).name_r[(*pos_add_r)]);
    (*infor).age[(*pos_add)] = (*infor_r).age_r[(*pos_add_r)];
    strcpy ((*infor).gender[(*pos_add)], (*infor_r).gender_r[(*pos_add_r)]);
    (*infor).score_math[(*pos_add)] = (*infor_r).score_math_r[(*pos_add_r)];
    (*infor).score_physics[(*pos_add)] = (*infor_r).score_physics_r[(*pos_add_r)];
    (*infor).score_chemistry[(*pos_add)] = (*infor_r).score_chemistry_r[(*pos_add_r)];
    ++(*num_new_student);

    /*Deleting function in Recycle Bin*/
    for (int i = *pos_add_r; i < (*recycle_student) - 1; i++)
    {
        strcpy ((*infor_r).student_id_r[i], (*infor_r).student_id_r[i + 1]);
        strcpy ((*infor_r).name_r[i], (*infor_r).name_r[i + 1]);
        (*infor_r).age_r[i] = (*infor_r).age_r[i + 1];
        strcpy ((*infor_r).gender_r[i], (*infor_r).gender_r[i + 1]);
        (*infor_r).score_math_r[i] = (*infor_r).score_math_r[i + 1];
        (*infor_r).score_physics_r[i] = (*infor_r).score_physics_r[i + 1];
        (*infor_r).score_chemistry_r[i] = (*infor_r).score_chemistry_r[i + 1];
    }
    --(*recycle_student);
}   
void search_input (stu *infor, int *num_new_student, char search_student [10], int *pos_search, int *search_x)
{
    for (int i = 0; i < *num_new_student + 3; i++)
    {
        int search_xf = strcmp((*infor).student_id [i], search_student);
        if (search_xf == 0)
        {
            *pos_search = i;
            *search_x = search_xf + 1;
        }
    }
}
void search_output (stu infor, char search_student [10], int pos_search)
{
    printf ("\n\t\t\t\t\t\t=====Data of %s=====\n", infor.student_id[pos_search]); 
    
    printf ("%-23s", "[Student ID]"); 
    printf ("%9s", "[Name]"); 
    printf ("%23s", "[Age]"); 
    printf ("%12s", "[Gender]");
    printf ("%16s", "[Math score]"); 
    printf ("%19s", "[Physics score]"); 
    printf ("%21s", "[Chemistry score]"); 
    printf ("\n");
    printf ("   %-17s", infor.student_id[pos_search]); 
    printf ("%-31s", infor.name[pos_search]); 
    printf ("%-10d", infor.age[pos_search]); 
    printf ("%-14s", infor.gender[pos_search]);
    printf ("%-18.1f", infor.score_math[pos_search]); 
    printf ("%-20.1f", infor.score_physics[pos_search]);
    printf ("%-15.1f", infor.score_chemistry[pos_search]);  
    printf ("\n%s", "**********************************");
    printf ("%s", "**********************************");
    printf ("%s", "**********************************");
    printf ("%s", "**********************************");
}
void copy_student (stu *infor, int *num_new_student, stu_s *infor_s)
{
    for (int i = 0; i < (*num_new_student) + 3; i++)
    {
        strcpy ((*infor_s).student_id_s[i], (*infor).student_id[i]);
        strcpy ((*infor_s).name_s[i], (*infor).name[i]);
        (*infor_s).age_s[i] = (*infor).age[i];
        strcpy ((*infor_s).gender_s[i], (*infor).gender[i]);
        (*infor_s).gpa_s[i] = (*infor).gpa[i];
        strcpy ((*infor_s).acedemic_ranking_s[i], (*infor).acedemic_ranking[i]);
    }
}
void swap_student (stu_s *infor_s, int *i, int *j)
{
    char tempid [10];
    strcpy (tempid, (*infor_s).student_id_s[*i]);
    strcpy ((*infor_s).student_id_s[*i], (*infor_s).student_id_s[*j]);
    strcpy ((*infor_s).student_id_s[*j], tempid);

    char tempname [50];
    strcpy (tempname, (*infor_s).name_s[*i]);
    strcpy ((*infor_s).name_s[*i], (*infor_s).name_s[*j]);
    strcpy ((*infor_s).name_s[*j], tempname);

    int tempage;
    tempage = (*infor_s).age_s[*i];
    (*infor_s).age_s[*i] = (*infor_s).age_s[*j]; 
    (*infor_s).age_s[*j] = tempage;

    char tempgender [5];
    strcpy (tempgender, (*infor_s).gender_s[*i]);
    strcpy ((*infor_s).gender_s[*i], (*infor_s).gender_s[*j]);
    strcpy ((*infor_s).gender_s[*j], tempgender);

    float tempgpa;
    tempgpa = (*infor_s).gpa_s[*i];
    (*infor_s).gpa_s[*i] = (*infor_s).gpa_s[*j]; 
    (*infor_s).gpa_s[*j] = tempgpa;

    char tempacedmic_ranking [50];
    strcpy (tempacedmic_ranking, (*infor_s).acedemic_ranking_s[*i]);
    strcpy ((*infor_s).acedemic_ranking_s[*i], (*infor_s).acedemic_ranking_s[*j]);
    strcpy ((*infor_s).acedemic_ranking_s[*j], tempacedmic_ranking);
}
void gpa_input ( stu *infor, int *num_new_student )
{
    for (int j = 0; j < (*num_new_student) + 3; j++)
    {   
        float math = (*infor).score_math[j];  
        float physics = (*infor).score_physics[j]; 
        float chemistry = (*infor).score_chemistry[j];     
        float gpa = ( math + physics + chemistry ) / 3;
        (*infor).gpa[j] = gpa;
        if (gpa >= 8.5 && gpa <= 10)
        {
            strcpy ((*infor).acedemic_ranking[j], "Excellent ( A )");
        }      
        else if (gpa >= 7 && gpa <= 8.4)
        {
            strcpy ((*infor).acedemic_ranking[j], "Good ( B )");
        }    
        else if (gpa >= 5.5 && gpa <= 6.9)
        {
            strcpy ((*infor).acedemic_ranking[j], "Average ( C )");
        }  
        else if (gpa >= 4 && gpa <= 5.4)
        {
            strcpy ((*infor).acedemic_ranking[j], "Below Average ( D )");
        }  
        else if (gpa < 4)
        {
            strcpy ((*infor).acedemic_ranking[j], "Weak ( F )");
        }    
    }
}
void gpa_output ( stu infor, int num_new_student )
{
    printf ("\n%70s\n", "===== List of students =====");
    printf ("\n%-13s", "[Serial]");
    printf ("%-23s", "[Student ID]"); 
    printf ("%9s", "[Name]"); 
    printf ("%23s", "[Age]"); 
    printf ("%12s", "[Gender]");
    printf ("%9s", "[GPA]"); 
    printf ("%25s", "[Academic Ranking]");  
    for (int j = 0; j < num_new_student + 3; j++)
    {   
        printf ("\n   %-13d", j);
        printf ("%-17s", infor.student_id[j]); 
        printf ("%-31s", infor.name[j]); 
        printf ("%-10d", infor.age[j]); 
        printf ("%-11s", infor.gender[j]);
        printf ("%-15.1f", infor.gpa[j]); 
        printf ("%-20s", infor.acedemic_ranking[j]);
        printf ("\n%s", "*****************************");
        printf ("%s", "******************************");
        printf ("%s", "******************************");
        printf ("%s", "******************************");             
    }
}
void sort_ascending_input_student (stu_s *infor_s, int *num_new_student)
{
    for (int i = 0; i < (*num_new_student) + 3; i++)
    {
        for (int j = 1 + i; j < (*num_new_student) + 3; j++)
        {
            if ((*infor_s).gpa_s[i] > (*infor_s).gpa_s[j])
            {
                swap_student (infor_s, &i, &j);
            }
        } 
    }
}
void sort_descending_input_student (stu_s *infor_s, int *num_new_student)
{
    for (int i = 0; i < (*num_new_student) + 3; i++)
    {
        for (int j = 1 + i; j < (*num_new_student) + 3; j++)
        {
            if ((*infor_s).gpa_s[i] < (*infor_s).gpa_s[j])
            {
                swap_student (infor_s, &i, &j);
            }
        } 
    }
}
void sort_output_student (stu_s infor_s, int num_new_student)
{
    printf ("\n%75s\n", "===== List of students after sort =====");
    printf ("\n%-13s", "[Serial]");
    printf ("%-23s", "[Student ID]"); 
    printf ("%9s", "[Name]"); 
    printf ("%23s", "[Age]"); 
    printf ("%12s", "[Gender]");
    printf ("%9s", "[GPA]"); 
    printf ("%25s", "[Academic Ranking]");  
    for (int j = 0; j < num_new_student + 3; j++)
    {   
        printf ("\n   %-13d", j);
        printf ("%-17s", infor_s.student_id_s[j]); 
        printf ("%-31s", infor_s.name_s[j]); 
        printf ("%-10d", infor_s.age_s[j]); 
        printf ("%-11s", infor_s.gender_s[j]);
        printf ("%-15.1f", infor_s.gpa_s[j]); 
        printf ("%-20s", infor_s.acedemic_ranking_s[j]);  
        printf ("\n%s", "*****************************");
        printf ("%s", "******************************");
        printf ("%s", "******************************");
        printf ("%s", "******************************");           
    }
}
int main ()
{
   /*Big variables*/
    stu infor;
    int num_new_student = 0;
    
   /* Variables for modifying */
    stu_m mod_infor;
    int pos_mod = 0;

    /* Variable for deleting */
    int pos_del = 0; 

    /* Variables for inputting & outputting recycle */
    stu_r infor_r;
    int num_recycle_student = -1; 
    int recycle_student = 0; 

    /* Variables for adding from recycle */
    int pos_add = 0; 
    int pos_add_r = 0;

    /* Variables for adding */
    stu_a add_infor;

    /* Variables for searching */
    char search_student[10];
    int pos_search = 0;
    int search_x = 0;

    /* Variables for sortting */
    stu_s infor_s;

    char account[31], password[31];
    infor_default (&infor);
    printf ("===== Please enter your account and password to access the program =====\n");
    printf ("Account: ");
    scanf ("%s", &account);
    printf ("Password: ");
    scanf ("%s", &password);    
    int check_account = strcmp(account, "backendlv1");
    int check_password = strcmp(password, "dsc@3012");
    while (check_account != 0 || check_password != 0)
    {
        printf ("*** User account or password incorrect! ***\n");
        printf ("*** Please retype! ***\n");
        printf ("Account: ");
        scanf ("%s", &account);
        printf ("Password: ");
        scanf ("%s", &password);
        check_account = strcmp(account, "backendlv1");
        check_password = strcmp(password, "dsc@3012");
    }
    output_student (infor, num_new_student);
    
    char select_input[5];
    printf ("\n");
    printf ("\n%98s", "===== Would you like to add the number of new students? =====");
    printf ("\n%83s", "Your choice ( Type Y or N ): ");
    scanf ("%s", &select_input);
    int select_input_x1 = strcmp(select_input, "y");
    int select_input_x2 = strcmp(select_input, "Y");
    if (select_input_x1 == 0 || select_input_x2 == 0)
    {
        printf ("\nAdding the number of new students: ");
        scanf ("%d", &num_new_student);
        input_student (&infor, &num_new_student);
        output_student (infor, num_new_student);
    }
    int select_menu = 0;
    do 
    {   
        menu ();
        printf ("\n%90s", "Select function ( Enter 1 or 2 or ... ): ");
        scanf ("%d", &select_menu);
        switch (select_menu)
        {
            case 1:
            {
                output_student (infor, num_new_student);
            }break;
            case 2:
            {
                printf ("\nLocation of adding: ");
                scanf ("%d", &pos_add);
                printf ("Enter New Student ID: ");
                scanf ("%s", &add_infor.student_id_a);
                strupr (add_infor.student_id_a);
                strcpy (search_student, add_infor.student_id_a);
                search_input (&infor, &num_new_student, search_student, &pos_search, &search_x);
                int check = strcmp (add_infor.student_id_a, infor.student_id[pos_search]);
                while (check == 0)
                {
                    printf ("\n*** Student ID is already in the list ***");
                    printf ("\nPlease enter another New Student ID: ");
                    scanf ("%s", &add_infor.student_id_a); 
                    strupr (add_infor.student_id_a);
                    strcpy (search_student, add_infor.student_id_a);
                    search_input (&infor, &num_new_student, search_student, &pos_search, &search_x);
                    check = strcmp (add_infor.student_id_a, infor.student_id[pos_search]);                   
                }
                fflush(stdin);
                printf ("Enter New Name: ");
                gets (add_infor.name_a);
                printf ("Enter New Age: ");
                scanf ("%d", &add_infor.age_a);
                printf ("Enter New Gender: ");
                scanf ("%s", &add_infor.gender_a);
                printf ("Enter New Math score: ");
                scanf ("%f", &add_infor.score_math_a); 
                printf ("Enter New Physics score: ");
                scanf ("%f", &add_infor.score_physics_a);
                printf ("Enter New Chemistry score: ");
                scanf ("%f", &add_infor.score_chemistry_a);                                                              
                add_input_student (&infor, &num_new_student, &pos_add, &add_infor);
                output_student (infor, num_new_student);      
            }break;
            case 3:
            {
                printf ("\n");
                printf ("Location of modifying: ");
                scanf ("%d", &pos_mod);
                printf ("\n");
                printf ("Modifying Student ID to: ");
                scanf ("%s", &mod_infor.student_id_m); 
                strupr (mod_infor.student_id_m);
                fflush (stdin); 
                printf ("Modifying Name to: ");
                gets(mod_infor.name_m);   
                printf ("Modifying Age to: ");
                scanf ("%d", &mod_infor.age_m);   
                printf ("Modifying Gender to: ");
                scanf ("%s", &mod_infor.gender_m); 
                printf ("Modifying Math score to: ");
                scanf ("%f", &mod_infor.score_math_m);   
                printf ("Modifying Physics score to: ");
                scanf ("%f", &mod_infor.score_physics_m); 
                printf ("Modifying Chemistry score to: ");
                scanf ("%f", &mod_infor.score_chemistry_m);                          
                modify_input_student (&infor, &mod_infor, &pos_mod);
                output_student (infor, num_new_student);
            }break;
            case 4:
            {
                printf ("\nLocation of deleting: ");
                scanf ("%d", &pos_del);   
                input_recycle (&infor, &infor_r, &pos_del, &recycle_student, &num_recycle_student);
                delete_input_student (&infor, &num_new_student, &pos_del);
            }break;      
            case 5:
            {
                for (int j = 0; j < recycle_student; j++)
                {
                    if (infor_r.student_id_r[j] == NULL)
                    {
                        printf ("*** No data in Recycle ***");
                    }
                    else 
                    {
                        printf ("\nLocation of adding in list of students: ");
                        scanf ("%d", &pos_add);
                        printf ("\nStudent data's added in recycle bin: ");
                        scanf ("%d", &pos_add_r);
                        if (pos_add_r > recycle_student - 1)
                        {
                            printf ("*** No data that you want in Recycle ***");
                            break;
                        }
                        else 
                        {
                            add_input_student_r (&infor, &infor_r, &num_new_student, &pos_add, &pos_add_r, &recycle_student);
                        }
                    }
                }
            }break;  
            case 6:
            {
                output_recycle (infor_r, recycle_student);
            }break;                  
            case 7:
            {
                char select_search[10];
                printf ("\nSearching Student ID: ");
                scanf ("%s", &search_student);
                strupr (search_student);
                search_input (&infor, &num_new_student, search_student, &pos_search, &search_x);
                if (search_x == 1)
                {
                    search_output (infor, search_student, pos_search);
                    char select_search_sua[10];
                    printf ("\nWould you like to MODIFY student data that you searched? ( Type Y or N )");
                    scanf ("%s", &select_search_sua);
                    int select_search_sua_x1 = strcmp(select_search_sua, "y");
                    int select_search_sua_x2 = strcmp(select_search_sua, "Y");
                    if (select_search_sua_x1 == 0 || select_search_sua_x2 == 0)
                    {
                        printf ("\nModifying Student ID to: ");
                        scanf ("%s", &mod_infor.student_id_m);
                        fflush (stdin);
                        printf ("Modifying New Name to: ");
                        gets(mod_infor.name_m);
                        printf ("Modifying New Age to: ");
                        scanf ("%d", &mod_infor.age_m);   
                        printf ("Modifying New Gender to: ");
                        scanf ("%s", &mod_infor.gender_m); 
                        printf ("Modifying New Math score to: ");
                        scanf ("%f", &mod_infor.score_math_m); 
                        printf ("Modifying New Physics score to: ");
                        scanf ("%f", &mod_infor.score_physics_m);
                        printf ("Modifying New Chemistry score to: ");
                        scanf ("%f", &mod_infor.score_chemistry_m);
						pos_mod = pos_search;
                        modify_input_student (&infor, &mod_infor, &pos_mod);
                        modify_output_student_search (infor, pos_search, search_student);                         
                    }   
                    char select_search_xoa[10];
                    printf ("\nWould you like to DELETE student data that you searched? ( Type Y or N )");
                    scanf ("%s", &select_search_xoa);
                    int select_search_xoa_x1 = strcmp(select_search_xoa, "y");
                    int select_search_xoa_x2 = strcmp(select_search_xoa, "Y");
                    if (select_search_xoa_x1 == 0 || select_search_xoa_x2 == 0)
                    {
                        pos_del = pos_search;
                        input_recycle (&infor, &infor_r, &pos_del, &recycle_student, &num_recycle_student);
                        delete_input_student (&infor, &num_new_student, &pos_del);
                    }
                    break;
                }
                else
                {
                    printf ("\nNo data");
                    printf ("\nNote: Capitalize first 2 letters");
                }
            }break;
            case 8:
            {
                gpa_input (&infor, &num_new_student);
                gpa_output (infor, num_new_student);     
                char select_sort_1[5];
                char select_sort_2[5];
                printf ("\n");
                printf ("\n%78s", "===== Would you like to sort by GPA? =====");
                printf ("\n%72s", "Your choice ( Type Y or N ): ");
                scanf ("%s", &select_sort_1);
                int select_sort_x1 = strcmp(select_sort_1, "y");
                int select_sort_x2 = strcmp(select_sort_1, "Y");
                if (select_sort_x1 == 0 || select_sort_x2 == 0)
                {
                    printf ("\n%88s", "===== Would you like to sort ascending or descending? =====");
                    printf ("\n%72s", "Your choice ( Type A or D ): ");
                    scanf ("%s", &select_sort_2);
                    int select_sort_y1 = strcmp (select_sort_2, "A");
                    int select_sort_y2 = strcmp (select_sort_2, "a");
                    int select_sort_y3 = strcmp (select_sort_2, "D");
                    int select_sort_y4 = strcmp (select_sort_2, "d");
                    if (select_sort_y1 == 0 || select_sort_y2 == 0)
                    {
                        copy_student (&infor, &num_new_student, &infor_s);
                        sort_ascending_input_student (&infor_s, &num_new_student);                   
                    }
                    else
                    {
                        copy_student (&infor, &num_new_student, &infor_s);
                        sort_descending_input_student (&infor_s, &num_new_student);                    
                    }
                    sort_output_student (infor_s, num_new_student);
                }   
            }break;
        }
    }while(select_menu != 0);
    return 0;
}