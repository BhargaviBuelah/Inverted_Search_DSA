#include "header.h"


status Display_DB(main_node **arr)
{
    int flag=0;
        printf("\t\t\t\033[0;30m<------------------------------------------------------------------------------------------------->\033[0m\n");
        printf("\t\t\t\033[0;33m| %-10s | %-25s | %-10s  | %-25s  | %-10s  |\033[0m\n","INDEX", "WORD", "FILE COUNT","FILE NAME","WORD COUNT");
        printf("\t\t\t\033[0;30m<------------------------------------------------------------------------------------------------->\033[0m\n");
    for(int i=0;i<INDEX;i++)
    {
        
        if(arr[i]!=NULL)
        {
            flag=1;
            main_node *main_temp=arr[i];
           
            while(main_temp!=NULL)
            {
                sub_node *sub_temp=main_temp->sub_link;
                while(sub_temp!=NULL)
                {        
                    printf("\t\t\t\033[0;34m| \033[0;35m%-10d |\033[0;36m %-25s |\033[0;31m %-10d  |\033[0;32m %-25s  |\033[38;5;214m %-10d  \033[0;34m|\033[0m\n",i,main_temp->word,main_temp->file_count,sub_temp->file_name,sub_temp->word_count);
                    int count=main_temp->file_count;
                    while(count>1)
                    {
                        sub_temp=sub_temp->slink;
                         printf("\t\t\t\033[0;34m|\033[0;35m %-10s | \033[0;36m%-25s |\033[0;31m %-10s  |\033[0;32m %-25s  | \033[38;5;214m%-10d  \033[0;34m|\033[0m\n","", "","", sub_temp->file_name, sub_temp->word_count);
                         count--;
                    }
                    printf("\t\t\t\033[0;30m<------------------------------------------------------------------------------------------------->\033[0m\n");          
                    sub_temp=sub_temp->slink;
                }
                main_temp=main_temp->main_link;
            }
            
        }
        

    }
    if(flag )
    {
        return SUCCESS;
    }
    else
        return FAILURE;
}