/*
Name: N.Bhargavi
Date: 24-10-24
Description: Inverted search program that enables users to search for specific words
             across multiple text files. This program constructs an inverted index,
             allowing for efficient searching by keeping track of the files in which 
             each word appears, as well as the count of occurrences.
*/


#include "header.h"

int main(int argc,char* argv[])
{
     printf("\n\t\t\t\t\033[48;2;128;0;128m\033[38;2;255;253;208m:::INVERTED SEARCH PROJECT:::\033[0m\n\n");

    if(argc<2)
    {
        printf("\033[0;31mError ❌:Provide Some files.\033[0m\n");
        return 0;
    }
    else
    {
        int opt=1;
        file_Slist *head=NULL;
        main_node *arr[INDEX]={NULL};      //create array for indexing
        if(read_and_validate(argc,argv,&head)==SUCCESS)
        { 
            while(opt)
            {
                printf("\n\t\t\t\t\033[4;33m📖 Choose option: \033[0m\n");
                printf("\033[0;36m");
                printf("\t\t\t\t<------------------------------------>\n");
                printf("\t\t\t\t| 1. 🗄️  \033[0;32mCreate Database.            \033[0;36m|\n");
                printf("\t\t\t\t| 2. 🔲  \033[0;33mDisplay Database.           \033[0;36m|\n");
                printf("\t\t\t\t| 3. 🔎  \033[0;34mSearch Database.            \033[0;36m|\n");
                printf("\t\t\t\t| 4. ✅  \033[0;31mSave Database.              \033[0;36m|\n");
                printf("\t\t\t\t| 5. 📝  \033[0;35mUpdate Database.            \033[0;36m|\n");
                printf("\t\t\t\t| 6. ➡️  \033[0;90m Exit                        \033[0;36m|\n");
                printf("\t\t\t\t<------------------------------------>\n");
                printf("\033[0;35mChoose Action To Perform...    \033[0m");
                scanf("%d",&opt);
            switch (opt)
            {
            case 1:
                /* creating Database */
                   // print(&head);
                if(create_DB(&head,arr)==SUCCESS)
                {
                     printf("\033[0;32mDatabase Created Successfully....\033[0m\n");
                }
                else
                {
                    printf("\033[0;31mError ❌: Unable to Create Database.\033[0m\n");
                }
                break;
            case 2:
                /* Display Database */
                if(Display_DB(arr)==SUCCESS)
                {
                    printf("\033[0;32mDatabase Displayed Successfully....\033[0m\n");
                }
                else
                {
                    printf("\033[0;31mError ❌: Empty  Database.\033[0m\n");
                }
                break;
            case 3:
                /* Search Database*/
                char str[100];
                printf("\033[0;35mPlease Enter the word to search : ✍ \033[0m\n");
                scanf("%s",str);
                if(Search_DB(arr,str)==SUCCESS)
                {
                    printf("\033[0;32mWord Displayed Successfully....\033[0m\n");
                }
                else
                {
                    printf("\033[0;31mError ❌: Unable to Display Database.\033[0m\n");
                }
                break;

            case 4:
                /* Save Database */
                char file_name[100];
                getchar();
                printf("\033[0;35mEnter the file name : ✍ \033[0m\n");
                scanf("%[^\n]",file_name);

                if(strstr(file_name,".txt"))
                { 
                    FILE *fp=fopen(file_name,"w");
                    if(Save_DB(arr,&head,fp)==SUCCESS)
                    {
                        printf("\033[0;32mData Saved Successfully....\033[0m\n");
                    }
                    else
                    {
                        printf("\033[0;31mError ❌: Unable to Save Database.\033[0m\n");
                    }
                    fclose(fp);
                }
                else
                {
                    printf("\033[0;32mError ❌:Please Provide Valid files.\033[0m\n");
                }
                break;
            case 5:
                /* Upadate Database */
                char update_file[100];
                getchar();
                printf("\033[0;35mEnter the updated file name : ✍ \033[0m\n");
                scanf("%s",update_file);
                int len=strlen(update_file);
                if(strstr(update_file,".txt")!= NULL && len > 4 && strcmp(update_file + len - 4, ".txt") == 0)
                {
                    FILE *fp=fopen(update_file,"r");
                    if(fp==NULL)
                    {
                        printf("\033[0;32mError ❌:File Not found.Please Provide Valid files.\033[0m\n");
                        break;
                    }
                    unsigned int var=ftell(fp);
                    char ch=fgetc(fp);  //reading 1st charecter if # means valid otherwise invalid
                    if(ch!='#')
                    {
                        printf("\033[0;32mError ❌:Please Provide Valid files.\033[0m\n");
                        break;
                    }
                    fseek(fp,0,SEEK_END);
                    var=ftell(fp);      //checking file contentes are present are not
                    if(var)
                    {
                        rewind(fp);
                        if(update_data(fp,arr,&head)==SUCCESS)
                        {
                            printf("\033[0;32mDatabase Updated Successfully....\033[0m\n");
                        }
                        else
                        {
                            printf("\033[0;31mError ❌:The database has already been updated.\033[0m\n");
                        }
                    }
                    else        //if file is empty
                    {
                        printf("\033[0;32mError ❌:File is Empty .Plese provide valid File.\033[0m\n");
                    }
                    fclose(fp);                   
                }
                else
                {
                    printf("\033[0;32mError ❌:Enter Proper valid file.\033[0m\n");   
                }             
                
                break;
            case 6:
                /* Exit from program*/
                 printf("\033[0;33mThank You for Contacting Us\v Visit Again 😊 ...\033[0m \n");
                exit(0);                
                break;
            default:
                printf("\033[0;32mError ❌:Entered Wrong option.\033[0m\n");  
                break;
            }

        }
                   
        }
        else
        {
            printf("\033[0;32mError ❌:Provide Valid Files.\033[0m\n");  
        }              
       
    }
}