#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct student
{
    char student_id[MAX][10];
    char name[MAX][50];
    int age[MAX];
    char gender[MAX][5];
    float score[MAX];
}stu;
typedef struct student_modify
{
    char student_id_m[10];
    char name_m[50];
    int age_m;
    char gender_m[5];
    float score_m;
}stu_m;
typedef struct student_addition
{
    char student_id_a[10];
    char name_a[50];
    int age_a;
    char gender_a[5];
    float score_a ;
}stu_a;
typedef struct student_recycle
{
    char student_id_r [MAX][10];
    char name_r [MAX][50];
    int age_r[MAX];
    char gender_r [MAX][5];
    float score_r[MAX];
}stu_r;
typedef struct student_sort
{
    char student_id_s [10];
    char name_s [50];
    int age_s;
    char gender_s [5];
    float score_s;
}stu_s;

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
            printf ("Enter Name: ");
            scanf ("%s", &(*infor).name[i]);  
            printf ("Enter Age: ");
            scanf ("%d", &(*infor).age[i]);
            printf ("Enter Gender: ");
            scanf ("%s", &(*infor).gender[i]);
            printf ("Enter Score: ");
            scanf ("%f", &(*infor).score[i]);
        }
    }
}
void output_student ( stu infor, int num_new_student )
{
    printf ("\n\t\t\t\t\t=====List of students=====\n");
    printf ("\n%-15s", "[Serial]");
    printf ("%-17s", "[Student ID]"); 
    printf ("%9s", "[Name]"); 
    printf ("%37s", "[Age]"); 
    printf ("%12s", "[Gender]");
    printf ("%14s", "[Score]"); 
    for (int j = 0; j < num_new_student + 3; j++)
    {   
        printf ("\n%-15d", j);
        printf ("%-20s", infor.student_id[j]); 
        printf ("%-38s", infor.name[j]); 
        printf ("%-9d", infor.age[j]); 
        printf ("%-15s", infor.gender[j]);
        printf ("%-15.1f", infor.score[j]);                    
    }
}
void modify_input_student ( stu *infor, stu_m *mod_infor, int *pos_mod )
{   
    strcpy ((*infor).student_id[*pos_mod], (*mod_infor).student_id_m);
    strcpy ((*infor).name[*pos_mod], (*mod_infor).name_m);
    (*infor).age[*pos_mod] = (*mod_infor).age_m;
    strcpy ((*infor).gender[*pos_mod], (*mod_infor).gender_m);
    (*infor).score[*pos_mod] = (*mod_infor).score_m;
}
void delete_input_student ( stu *infor, int *num_new_student, int *pos_del)
{
    for (int i = (*pos_del); i < ((*num_new_student) + 3) - 1; i++)
    {
        strcpy ((*infor).student_id[i], (*infor).student_id[i + 1]);
        strcpy ((*infor).name[i], (*infor).name[i + 1]);
        (*infor).age[i] = (*infor).age[i + 1];
        strcpy ((*infor).gender[i], (*infor).gender[i + 1]);
        (*infor).score[i] = (*infor).score[i + 1];
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
        (*infor_r).score_r[j] = (*infor).score[*pos_del];
    }
}
void output_recycle ( stu_r infor_r, int recycle_student)
{     
    printf ("\n\t\t\t\t=====List of students in Recycle Bin=====\n");
    printf ("\n%-15s", "[Serial]");
    printf ("%-17s", "[Student ID]"); 
    printf ("%9s", "[Name]"); 
    printf ("%37s", "[Age]"); 
    printf ("%12s", "[Gender]");
    printf ("%14s", "[Score]");
    for (int j = 0; j < recycle_student; j++)
    {   
        printf ("\n%-15d", j);
        printf ("%-20s", infor_r.student_id_r[j]); 
        printf ("%-38s", infor_r.name_r[j]); 
        printf ("%-9d", infor_r.age_r[j]); 
        printf ("%-15s", infor_r.gender_r[j]);
        printf ("%-15.1f", infor_r.score_r[j]);                    
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
        (*infor).score[i] = (*infor).score[i - 1];
    }
    strcpy ((*infor).student_id[(*pos_add)], (*infor_r).student_id_r[(*pos_add_r)]);
    strcpy ((*infor).name[(*pos_add)], (*infor_r).name_r[(*pos_add_r)]);
    (*infor).age[(*pos_add)] = (*infor_r).age_r[(*pos_add_r)];
    strcpy ((*infor).gender[(*pos_add)], (*infor_r).gender_r[(*pos_add_r)]);
    (*infor).score[(*pos_add)] = (*infor_r).score_r[(*pos_add_r)];
    ++(*num_new_student);

    /*Deleting function in Recycle Bin*/
    for (int i = *pos_add_r; i < (*recycle_student) - 1; i++)
    {
        strcpy ((*infor_r).student_id_r[i], (*infor_r).student_id_r[i + 1]);
        strcpy ((*infor_r).name_r[i], (*infor_r).name_r[i + 1]);
        (*infor_r).age_r[i] = (*infor_r).age_r[i + 1];
        strcpy ((*infor_r).gender_r[i], (*infor_r).gender_r[i + 1]);
        (*infor_r).score_r[i] = (*infor_r).score_r[i + 1];
    }
    --(*recycle_student);
}   
void add_input_student (stu *infor, int *num_new_student, int *pos_add, stu_a *add_infor)
{
    for (int i = ((*num_new_student) + 3) + 1; i > *pos_add; i--)
    {
        strcpy ((*infor).student_id[i], (*infor).student_id[i - 1]);
        strcpy ((*infor).name[i], (*infor).name[i - 1]);
        (*infor).age[i] = (*infor).age[i - 1];
        strcpy ((*infor).gender[i], (*infor).gender[i - 1]);
        (*infor).score[i] = (*infor).score[i - 1];
    }
    strcpy ((*infor).student_id[*pos_add], (*add_infor).student_id_a);
    strcpy ((*infor).name[*pos_add], (*add_infor).name_a);
    (*infor).age[*pos_add] = (*add_infor).age_a;
    strcpy ((*infor).gender[*pos_add], (*add_infor).gender_a);
    (*infor).score[*pos_add] = (*add_infor).score_a;                    
    ++(*num_new_student);
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
    printf ("\n\t\t\t=====Data of %s=====\n", infor.student_id[pos_search]);  
    printf ("\n%-10s", infor.student_id[pos_search]); 
    printf ("%-20s", infor.name[pos_search]); 
    printf ("%20d", infor.age[pos_search]); 
    printf ("%10s", infor.gender[pos_search]);
    printf ("%15.1f", infor.score[pos_search]);
}
void copy_student (stu *infor, int *num_new_student, stu_s *infor_s)
{
    for (int i = 0; i < (*num_new_student) + 3; i++)
    {
        strcpy ((*infor_s).student_id_s[i], (*infor).student_id[i]);
        strcpy ((*infor_s).name_s[i], (*infor).name[i]);
        (*infor_s).age_s[i] = (*infor).age[i];
        strcpy ((*infor_s).gender_s[i], (*infor).gender[i]);
        (*infor_s).score_s[i] = (*infor).score[i];
    }
}
void swap_student 
( 
    stu_sort string_studentid[][10], 
    stu_sort string_name[][50],
    int *num1_age,  
    int *num2_age,
    stu_sort string_gender[][5],
    float *num1_score,  
    float *num2_score,
    int *i, 
    int *j
)
{
    stu_sort tempid[MAX][10];
    strcpy (tempid[*i]->student_id_sort, string_studentid[*i]->student_id_sort);
    strcpy (string_studentid[*i]->student_id_sort, string_studentid[*j]->student_id_sort);
    strcpy (string_studentid[*j]->student_id_sort, tempid[*i]->student_id_sort);

    stu_sort tempname[MAX][50];
    strcpy (tempname[*i]->name_sort, string_name[*i]->name_sort);
    strcpy (string_name[*i]->name_sort, string_name[*j]->name_sort);
    strcpy (string_name[*j]->name_sort, tempname[*i]->name_sort);

    int tempage;
    tempage = *num1_age;
    *num1_age = *num2_age; 
    *num2_age = tempage;

    stu_sort tempgender[MAX][5];
    strcpy (tempgender[*i]->gender_sort, string_gender[*i]->gender_sort);
    strcpy (string_gender[*i]->gender_sort, string_gender[*j]->gender_sort);
    strcpy (string_gender[*j]->gender_sort, tempgender[*i]->gender_sort);

    float tempscore;
    tempscore = *num1_score;
    *num1_score = *num2_score; 
    *num2_score = tempscore;
}
void sort_ascending_input_student
(
    stu_sort arr_infor_studentid_sort[][10],
    stu_sort arr_infor_name_sort[][50],
    stu_sort infor_age_sort[],
    stu_sort arr_infor_gender_sort[][5],
    stu_sort infor_score_sort[],
    int *num_new_student
)
{
    for (int i = 0; i < *num_new_student + 3; i++)
    {
        for (int j = 1 + i; j < *num_new_student + 3; j++)
        {
            if (infor_score_sort[i].score_sort > infor_score_sort[j].score_sort)
            {
                swap_student 
                (
                    arr_infor_studentid_sort, 
                    arr_infor_name_sort,
                    &infor_age_sort[i].age_sort, &infor_age_sort[j].age_sort,
                    arr_infor_gender_sort,
                    &infor_score_sort[i].score_sort, &infor_score_sort[j].score_sort,  
                    &i, &j
                );
            }
        } 
    }
}
void sort_descending_input_student
(
    stu_sort arr_infor_studentid_sort[][10],
    stu_sort arr_infor_name_sort[][50],
    stu_sort infor_age_sort[],
    stu_sort arr_infor_gender_sort[][5],
    stu_sort infor_score_sort[],
    int *num_new_student
)
{
    for (int i = 0; i < *num_new_student + 3; i++)
    {
        for (int j = 1 + i; j < *num_new_student + 3; j++)
        {
            if (infor_score_sort[i].score_sort < infor_score_sort[j].score_sort)
            {
                swap_student 
                (
                    arr_infor_studentid_sort, 
                    arr_infor_name_sort,
                    &infor_age_sort[i].age_sort, &infor_age_sort[j].age_sort,
                    arr_infor_gender_sort,
                    &infor_score_sort[i].score_sort, &infor_score_sort[j].score_sort,  
                    &i, &j
                );
            }
        } 
    }
}
void sort_output_student 
(
    stu_sort arr_infor_studentid_sort[][10], 
    stu_sort arr_infor_name_sort[][50], 
    stu_sort infor_age_sort[], 
    stu_sort arr_infor_gender_sort[][5],
    stu_sort infor_score_sort[], 
    int num_new_student
)
{
    printf ("\n\t\t=====List of students after sort=====\n");
    printf ("\n%-15s", "[Serial]");
    printf ("%-17s", "[Student ID]"); 
    printf ("%9s", "[Name]"); 
    printf ("%37s", "[Age]"); 
    printf ("%12s", "[Gender]");
    printf ("%14s", "[Score]");
    for (int j = 0; j < num_new_student + 3; j++)
    {   
        printf ("\n%-15d", j);
        printf ("%-20s", arr_infor_studentid_sort[j]->student_id_sort); 
        printf ("%-38s", arr_infor_name_sort[j]->name_sort); 
        printf ("%-9d", infor_age_sort[j].age_sort); 
        printf ("%-15s", arr_infor_gender_sort[j]->gender_sort);
        printf ("%-15.1f", infor_score_sort[j].score_sort);                    
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

                    /*Student ID*/
    strcpy (infor.student_id[0], "SE001");
    strcpy (infor.student_id[1], "SE002");
    strcpy (infor.student_id[2], "SS003");
                    /*Name*/
    strcpy (infor.name[0], "Duong Xuan Truong");
    strcpy (infor.name[1], "Pham Mai Bao Tran");
    strcpy (infor.name[2], "Nguyen Tran Gia Bao");
                    /*Age*/
    infor.age[0] = 18;
    infor.age[1] = 16;
    infor.age[2] = 15;
                    /*Gender*/
    strcpy (infor.gender[0], "Nam");
    strcpy (infor.gender[1], "Nu");
    strcpy (infor.gender[2], "Nam");
                    /*Score*/
    infor.score[0] = 9;
    infor.score[1] = 7;
    infor.score[2] = 9.5;
    output_student (infor, num_new_student);
    
    char select_input[5];
    printf ("\nWould you like to add the number of new students? ( Type Y or N )");
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
        printf ("\n\t=====Menu=====\n");
        printf ("\n1. Printing the list of students");
        printf ("\n2. Adding new student");
        printf ("\n3. Modifying student data");
        printf ("\n4. Deleting student data");
        printf ("\n5. Restoring student data");
        printf ("\n6. Recycle Bin");
        printf ("\n7. Searching student data");
        printf ("\n8. Sorting student data by score");
        printf ("\n0. Ending program");
        printf ("\nSelect function: ");
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
                printf ("\nNew Student ID: ");
                scanf ("%s", &add_infor.student_id_a);
                strcpy (search_student, add_infor.student_id_a);
                search_input (&infor, &num_new_student, search_student, &pos_search, &search_x);
                int check = strcmp (add_infor.student_id_a, infor.student_id[pos_search]);
                while (check == 0)
                {
                    printf ("\nWrong Student ID format");
                    printf ("\nEnter new Student ID again: ");
                    scanf ("%s", &add_infor.student_id_a); 
                    strcpy (search_student, add_infor.student_id_a);
                    search_input (&infor, &num_new_student, search_student, &pos_search, &search_x);
                    check = strcmp (add_infor.student_id_a, infor.student_id[pos_search]);                   
                }
                printf ("\nNew Name: ");
                scanf ("%s", &add_infor.name_a);
                printf ("\nNew Age: ");
                scanf ("%d", &add_infor.age_a);
                printf ("\nNew Gender: ");
                scanf ("%s", &add_infor.gender_a);
                printf ("\nNew Score: ");
                scanf ("%f", &add_infor.score_a);                                                               
                add_input_student (&infor, &num_new_student, &pos_add, &add_infor);
                output_student (infor, num_new_student);       
            }break;
            case 3:
            {
                printf ("\n");
                printf ("Location of modifying: ");
                scanf ("%d", &pos_mod);
                printf ("\n");
                printf ("Modifying Student ID: ");
                scanf ("%s", &mod_infor.student_id_m);   
                printf ("Modifying Name: ");
                scanf ("%s", &mod_infor.name_m);   
                printf ("Modifying Age: ");
                scanf ("%d", &mod_infor.age_m);   
                printf ("Modifying Gender: ");
                scanf ("%s", &mod_infor.gender_m); 
                printf ("Modifying Score: ");
                scanf ("%f", &mod_infor.score_m);                            
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
                printf ("\nLocation of adding in list of students: ");
                scanf ("%d", &pos_add);
                printf ("\nStudent data's added in recycle bin: ");
                scanf ("%d", &pos_add_r);
                add_input_student_r (&infor, &infor_r, &num_new_student, &pos_add, &pos_add_r, &recycle_student);
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
                        printf ("\nNew Student ID: ");
                        scanf ("%s", &mod_infor.student_id_m);
                        printf ("New Name: ");
                        scanf ("%s", &mod_infor.name_m);
                        printf ("New Age: ");
                        scanf ("%d", &mod_infor.age_m);   
                        printf ("New Gender: ");
                        scanf ("%s", &mod_infor.gender_m); 
                        printf ("New Score: ");
                        scanf ("%f", &mod_infor.score_m); 
						pos_mod = pos_search;
                        modify_input_student (&infor, &mod_infor, &pos_mod);
						printf ("\n\t\t\t\t=====Student data after modify=====\n");
						printf ("%-17s", "[Student ID]"); 
						printf ("%9s", "[Name]"); 
						printf ("%37s", "[Age]"); 
						printf ("%12s", "[Gender]");
						printf ("%14s", "[Score]");
						printf ("\n");
						printf ("%-20s", infor.student_id[pos_search]); 
						printf ("%-38s", infor.name[pos_search]); 
						printf ("%-9d", infor.age[pos_search]); 
						printf ("%-15s", infor.gender[pos_search]);
						printf ("%-15.1f", infor.score[pos_search]);                                  
                    }   
                    char select_search_xoa[10];
                    printf ("\nWould you like to DELETE student data that you searched? ( Type Y or N )");
                    scanf ("%s", &select_search_xoa);
                    int select_search_xoa_x1 = strcmp(select_search_xoa, "y");
                    int select_search_xoa_x2 = strcmp(select_search_xoa, "Y");
                    if (select_search_xoa_x1 == 0 || select_search_xoa_x2 == 0)
                    {
                        pos_del = pos_search;
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
            // case 8:
            // {
            //     copy_student 
            //     (
            //         arr_infor_studentid, 
            //         arr_infor_name, 
            //         infor_age, 
            //         arr_infor_gender,
            //         infor_score,
            //         &num_new_student,
            //         arr_infor_studentid_sort, 
            //         arr_infor_name_sort, 
            //         infor_age_sort, 
            //         arr_infor_gender_sort,
            //         infor_score_sort
            //     );
            //     char select_sort[5];
            //     printf ("Would you like to sort ascending or descending? ( Type A or D )");
            //     scanf ("%s", &select_sort);
            //     int select_sort_x1 = strcmp (select_sort, "A");
            //     int select_sort_x2 = strcmp (select_sort, "a");
            //     int select_sort_x3 = strcmp (select_sort, "D");
            //     int select_sort_x4 = strcmp (select_sort, "d");
            //     if (select_sort_x1 == 0 || select_sort_x2 == 0)
            //     {
            //         sort_ascending_input_student 
            //         (
            //             arr_infor_studentid_sort, 
            //             arr_infor_name_sort, 
            //             infor_age_sort,
            //             arr_infor_gender_sort,
            //             infor_score_sort, 
            //             &num_new_student
            //         );                    
            //     }
            //     else
            //     {
            //         sort_descending_input_student 
            //         (
            //             arr_infor_studentid_sort, 
            //             arr_infor_name_sort, 
            //             infor_age_sort,
            //             arr_infor_gender_sort,
            //             infor_score_sort, 
            //             &num_new_student
            //         );                    
            //     }
            //     sort_output_student 
            //     (
            //         arr_infor_studentid_sort, 
            //         arr_infor_name_sort, 
            //         infor_age_sort, 
            //         arr_infor_gender_sort,
            //         infor_score_sort,
            //         num_new_student
            //     );
            // }break;
        }
    }while(select_menu != 0);
    return 0;
}