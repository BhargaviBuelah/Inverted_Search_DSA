/*
Description: Search program that enables users to search for specific words
             across multiple text files. This program constructs an inverted index,
             allowing for efficient searching by keeping track of the files in which 
             each word appears, as well as the count of occurrences.
*/

#include"header.h"
status Search_DB(main_node **arr,char *str)
{
    if (isalpha(str[0])) 
    {
        char ch = tolower(str[0]);
        int ind = ch - 'a'; // Calculate index of the word
        if(arr[ind]==NULL)
        {
             printf("\033[0;31mError ❌:Word Not Found.\033[0m\n");
            return FAILURE;
        }
        main_node *main_temp=arr[ind];
        while(main_temp!=NULL)
        {
            if(!strcmp(str,main_temp->word))
            {
                sub_node *sub_temp=main_temp->sub_link;
                int flag=1;
               printf("\t\t\t\033[0;30m<-------------------------------------------------------->\033[0m\n");
               printf("\t\t\t\033[0;33m| %-10s  | %-25s  | %-10s  |\033[0m\n", "FILE COUNT","FILE NAME","WORD COUNT");
                printf("\t\t\t\033[0;30m<-------------------------------------------------------->\033[0m\n");

                while(sub_temp!=NULL)
                {
                    if(flag)
                    {
                        printf("\t\t\t\033[0;36m|\033[0;35m %-10d  |\033[38;2;128;128;0m %-25s  |\033[1;31m %-10d  \033[0;36m|\033[0m\n", main_temp->file_count,sub_temp->file_name,sub_temp->word_count);
                        flag=0;
                    }    
                    else
                    {
                       printf("\t\t\t\033[0;36m| \033[0;35m%-10s  | \033[38;2;128;128;0m%-25s  |\033[1;31m %-10d  \033[0;36m|\033[0m\n", "",sub_temp->file_name,sub_temp->word_count);   
                    }
                          
                    sub_temp=sub_temp->slink;
                }
                 printf("\t\t\t\033[0;30m<-------------------------------------------------------->\033[0m\n");
                return SUCCESS;
            }
            main_temp=main_temp->main_link;
        }
    }
    else if(isdigit(str[0])) 
    {
        if(arr[26]==NULL)
        {
            printf("Digit Not Found\n");
            return FAILURE;
        }
        main_node *main_temp=arr[26];
        while(main_temp!=NULL)
        {
            if(!strcmp(str,main_temp->word))
            {
                sub_node *sub_temp=main_temp->sub_link;
                int flag=1;
                while(sub_temp!=NULL)
                {
                    if(flag)
                    {
                        printf("%d      %s        %d\n",main_temp->file_count,sub_temp->file_name,sub_temp->word_count);
                        flag=0;
                    }    
                    else
                        printf("        %s        %d\n",sub_temp->file_name,sub_temp->word_count);
                    sub_temp=sub_temp->slink;
                }
                return SUCCESS;
            }
            main_temp=main_temp->main_link;
        }
    }
    else
    {
        if(arr[27]==NULL)
        {
            printf("Digit Not Found\n");
            return FAILURE;
        }
        main_node *main_temp=arr[27];
        while(main_temp!=NULL)
        {
            if(!strcmp(str,main_temp->word))
            {
                sub_node *sub_temp=main_temp->sub_link;
                int flag=1;
                while(sub_temp!=NULL)
                {
                    if(flag)
                    {
                        printf("%d      %s        %d\n",main_temp->file_count,sub_temp->file_name,sub_temp->word_count);
                        flag=0;
                    }    
                    else
                        printf("        %s        %d\n",sub_temp->file_name,sub_temp->word_count);
                    sub_temp=sub_temp->slink;
                }
                return SUCCESS;
            }
            main_temp=main_temp->main_link;
        }
    }
     printf("\033[0;31mError ❌:Word Not Found.\033[0m\n");
    return FAILURE;
}