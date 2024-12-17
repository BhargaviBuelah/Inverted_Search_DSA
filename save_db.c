/*
Description: This function saves the current state of the database to a specified output file, 
         allowing for persistence of word occurrences and their associated file information.
*/
#include"header.h"

status Save_DB(main_node **arr,file_Slist **head,FILE * fp)
{
    if (*head == NULL) // Check if the list is empty
    { 
       
        printf("\033[0;31mError ❌:No files available.\033[0m\n");
        return FAILURE; // Return an appropriate failure status
    }
    int flag=0;

    for(int i=0;i<INDEX;i++)
    {
        
        if(arr[i]!=NULL)        //traversing through each node and storing in file
        {
            flag=1;
            main_node *main_temp=arr[i];
           
            while(main_temp!=NULL)         //traversing through main  node and storing in file
            {
                sub_node *sub_temp=main_temp->sub_link;
                
                while(sub_temp!=NULL)       //traversing through sub  node upto file count times and storing in file
                {
                    fprintf(fp,"#%d;%s;%d;%s;%d;",i,main_temp->word,main_temp->file_count,sub_temp->file_name,sub_temp->word_count);
                    int count=main_temp->file_count;
                    while(count>1)
                    {
                        sub_temp=sub_temp->slink;
                        fprintf(fp,"%s;%d;",sub_temp->file_name,sub_temp->word_count);   
                        count--;
                    }
                    fprintf(fp,"%s\n","#");
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
