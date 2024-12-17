/*
Description: This function updates the existing database by reading new data from a specified 
         file and incorporating any changes into the existing word occurrences and file 
         associations.
*/

#include "header.h"

status update_data(FILE *fp, main_node **arr,file_Slist **head)
{
    char buffer[100];
    for(int i=0;i<INDEX;i++) // Initialize the main_node list checking array is empty or not
    {                       //If not empty return faillure
        if(arr[i]!=NULL)
            return FAILURE;
    }
    while (fscanf(fp, "%s", buffer) != EOF)     //read the file until reaches end of line
    {
        // Skip the initial part up to the first semicolon
        char *token = strtok(buffer, "#;");
      //  printf("------------->%s\n",token); //for checking
        int index = atoi(token);  // Get index

        token = strtok(NULL, ";"); // Get the word  
        char *word = token;

        token = strtok(NULL, ";");  // Get file count
        int file_count = atoi(token);
        
        if (arr[index] == NULL)         // If main node does not exist
        { 
            main_node *new_main = create_main_node(word, file_count);
            if (new_main == NULL)
            {
                printf("\033[0;31mError ❌:Memory not allocated for main_node.\033[0m\n");
                return FAILURE;
            }
            arr[index] = new_main;

            while (file_count--)        // Run loop up to file count times
            { 
                token = strtok(NULL, ";"); // Get the file name 
               // printf("--------->File name: %s\n", token); // For checking 
                char *file_name = token;
                

                token = strtok(NULL, ";"); // Get word count 
                int word_count = atoi(token); // Store word count

                sub_node *new_sub = create_sub_node(file_name, word_count); // Create sub node
                /*Delete the file names from Single link list while  updating   of data  """if you want to create data 
                base after updation""" .if same file found duplicate data will be update So, we need to delete that 
                file name from Single linked list
                */
              delete_node(head,file_name);
                if (new_sub == NULL)
                {
                    printf("\033[0;31mError ❌:Memory not allocated forsub_node.\033[0m\n");
                    return FAILURE; // Handle memory allocation failure
                }
                // Link the new sub node
                if (new_main->sub_link == NULL)
                {
                    new_main->sub_link = new_sub; // First sub node
                } 
                else 
                {
                    sub_node *current = new_main->sub_link;
                    while (current->slink != NULL)
                    {
                        current = current->slink; // Traverse to the end
                    }
                    current->slink = new_sub; // Link the new sub node
                }
            }
        } 
        else    //If array having main nodes 
        {
            /*take one temparray pontinter and traverse until main node link reaches null*/
            main_node *main_temp = arr[index];
            while (main_temp->main_link != NULL)
            {
            main_temp = main_temp->main_link; // Move to the next main node
            }
            //after reaching last main node create node and attach main node and attach sub nodes also
            //reapeat the above process
            main_node *new_main = create_main_node(word, file_count);
            if (new_main == NULL)
            {
                printf("\033[0;31mError ❌:Memory not allocated for main_node.\033[0m\n");
                return FAILURE;
            }
            main_temp->main_link = new_main;

            while (file_count--)        // Run loop up to file count times
            { 
                token = strtok(NULL, ";"); // Get the file name 
               // printf("--------->File name: %s\n", token); // For checking 
                char *file_name = token;

                token = strtok(NULL, ";"); // Get word count 
                int word_count = atoi(token); // Store word count

                sub_node *new_sub = create_sub_node(file_name, word_count); // Create sub node
                if (new_sub == NULL)
                { 
                    printf("\033[0;31mError ❌:Memory not allocated for sub_node.\033[0m\n");
                    return FAILURE; // Handle memory allocation failure
                }
                // Link the new sub node
                if (new_main->sub_link == NULL)
                {
                    new_main->sub_link = new_sub; // First sub node
                } 
                else 
                {
                    sub_node *current = new_main->sub_link;
                    while (current->slink != NULL)
                    {
                        current = current->slink; // Traverse to the end
                    }
                    current->slink = new_sub; // Link the new sub node
                }
            }

            
        }
    }

    return SUCCESS; // Return status indicating success
}
