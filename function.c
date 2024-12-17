#include"header.h"

// Function to delete a node from the singly linked list
void delete_node(file_Slist **head, const char *file_name) 
{
    if (head == NULL || *head == NULL) {
        return; // List is empty or head pointer is NULL
    }

    file_Slist *temp = *head; // Start from the head
    file_Slist *prev = NULL;   // Previous pointer

    // Traverse the list
    while (temp != NULL) 
    {
        // Check if the current node matches the file_name
        if (strcmp(temp->name, file_name) == 0) 
        {
            // If the node to delete is the head
            if (prev == NULL) 
            {
                *head = temp->link; // Move head pointer to next node
            } 
            else 
            {
                prev->link = temp->link; // Bypass the node to delete
            }

            // Free the memory allocated for the node
            free(temp);       // Free the node itself
            return;          // Node deleted, exit function
        }

        // Move to the next node
        prev = temp;       // Update previous pointer
        temp = temp->link; // Move to the next node
    }
    return;
}


main_node* create_main_node(char *buffer,int count)
{
    main_node *main=malloc(sizeof(main_node));       //creating main node;
    if(main==NULL)
    {
        printf("\033[0;31mError ❌: Unable to Create main node.\033[0m\n");
        return NULL;
    }
    strcpy(main->word,buffer);
    main->file_count=count;
    main->sub_link=NULL;
    main->main_link=NULL;
    return main;
}
sub_node* create_sub_node(char * str,int count)
{
    sub_node *sub=malloc(sizeof(sub_node));
    if(sub==NULL)
    {
        printf("\033[0;31mError ❌: Unable to Create sub node.\033[0m\n");
        return NULL;
    }
    strcpy(sub->file_name,str);
    sub->word_count=count;
    sub->slink=NULL;
    return sub;
}


void  print(file_Slist **head)
{
    if (*head == NULL) 
    {
        printf("\033[0;31mINFO  : List is empty.\033[0m\n");
        return;
    }

    printf("head-> ");
    file_Slist *temp = *head;
    
    // Traverse through the list
    while (temp != NULL) {  // Continue until temp is NULL
        printf("%s -> ", temp->name); // Print the name followed by an arrow
        temp = temp->link; // Move to the next node
    }
     printf("null \n");
}

file_Slist* create_node(const char *name)
{
    file_Slist *new=malloc(sizeof(file_Slist));
    if(new==NULL)
    {
        printf("\033[0;31mError ❌: Memory is not allocated.\033[0m\n");
        return 0;
    }
    strcpy(new->name,name);
    // printf("--->%s\n",new->name);
    new->link=NULL;
    return new;
}
status read_and_validate(int argc,char *argv[],file_Slist **head)
{
   FILE *fp[argc - 1];  // Declare an array of file pointers, size based on the number of files

    for(int i=1;i<argc;i++)
    {
        int len=strlen(argv[i]);
        if (strstr(argv[i], ".txt") != NULL && len > 4 && strcmp(argv[i] + len - 4, ".txt") == 0)  //checking extension .txt or not
        {
             
           fp[i -1]=fopen(argv[i],"r+");        //opening and checking file is availaable or not
            if(fp[i-1]==NULL)
            {
                printf("\033[0;32m%s\033[0;31m File is not available \033[0m\n",argv[i]);
                continue;
            }
            long int len=ftell(fp[i-1]);
            fseek(fp[i-1],0,SEEK_END);    //moving pointer at tthe end of file
            len=ftell(fp[i-1]);
          //  printf("length-------->%ld",len);
            if(len)        //checking file is empty or not
            {
                int flag=0;
                for(int j=1;j<i;j++)    //checking for duplicate files
                {
                    if(!strcmp(argv[i],argv[j]))
                    {
                        flag=1;
                        printf("\033[0;31mError ❌: Duplicate file found :\033[0;32m %s\033[0m\n",argv[i]);
                        break;
                    }
                }
                if(!flag)
                {
                    char str[25];
                    //printf("file names--------->%s\n",str);
                    strcpy(str,argv[i]);
                    //printf("file names--------->%s\n",str);
                    file_Slist *new=create_node(str);
                   // printf("---->Added to the node %s\n",new->name);
                    if(*head==NULL)
                    {
                        *head=new;
                    }
                    else
                    {
                        file_Slist *temp=*head;              //insert at last
                        while(temp->link!=NULL)
                        {
                            temp=temp->link;
                        }
                        temp->link=new;
                    }

                    fclose(fp[i -1]);
                }
            }
            else
            {
                printf("\033[0;31mError ❌:File is empty :\033[0;32m %s\033[0m\n",argv[i]);
            }

        }
        else
        {
            printf("\033[0;31mError ❌:Provide valid extension file:\033[0;32m %s\033[0m\n",argv[i]);
        }
    }
    return SUCCESS;

}