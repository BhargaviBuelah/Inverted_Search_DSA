/*
Description: This function initializes and constructs the database for storing word occurrences 
         across multiple text files. It reads the filenames from a linked list and processes 
         each file to extract words and their respective counts.
*/
#include "header.h"

status create_DB(file_Slist **head, main_node *arr[])
{
    if (*head == NULL) 
    {
        printf("\033[0;31mError ❌:No files available.\033[0m\n");
        return FAILURE; // Return an appropriate failure status
    }
    static int flag=1;
    if(flag)
    {
        file_Slist *temp = *head; // Temporary pointer for traversing the file list
        while (temp != NULL)
        {
            int ind; // To calculate index
            char buffer[25]; // Temporary array to store the data from the file
            FILE *fp = fopen(temp->name, "r"); // Open the current file         
        /// printf("----------------------->%s\n", temp->name);          //for checking
            if (fp == NULL) 
            {
                printf("\033[0;31mError ❌: Unable to open file:\033[0;32m%s \033[0m\n",temp->name);
                return FAILURE;                 // Return failure if file cannot be opened
            }

            // Read file until EOF
            while (fscanf(fp, "%s", buffer) != EOF)         //read word by word
            { 
                if (isalpha(buffer[0]))     //if found word 
                {
                    char ch = tolower(buffer[0]);
                    ind = ch - 'a'; // Calculate index of the word

                    main_node *main_temp = arr[ind]; // Temporary pointer to traverse main nodes

                    while (main_temp != NULL) 
                    {
                        // Check if the word matches
                        if (strcmp(buffer, main_temp->word) == 0) 
                        {
                            // Word found, now check for the file in sub_nodes
                            sub_node *sub_temp = main_temp->sub_link;       //take one temp pointer to traverse through sub nodes

                            while (sub_temp != NULL) 
                            {
                                if (strcmp(temp->name, sub_temp->file_name) == 0)
                                {
                                    // File already counted, increment word count
                                    sub_temp->word_count++;
                                    break; // Exit the sub_node loop
                                }
                                sub_temp = sub_temp->slink; // Move to the next sub_node
                            }

                            // If the file was not found in sub_nodes, create a new sub_node
                            if (sub_temp == NULL) 
                            {
                                sub_node *sub = create_sub_node(temp->name, 1);
                                if (sub == NULL)
                                {
                                    printf("\033[0;31mError ❌: Unable to create sub node.\033[0m\n");
                                    fclose(fp);
                                    return FAILURE;
                                }
                                main_temp->file_count++; // Increase file count
                                sub->slink = main_temp->sub_link; // Link the new sub_node
                                main_temp->sub_link = sub; // Attach to main_node
                            }
                            break; // Exit the main_node loop
                        }
                        main_temp = main_temp->main_link; // Move to the next main_node
                    }
                    // If the word is not found in the main_node list, create a new main_node
                    if (main_temp == NULL) 
                    {
                        main_node *main = create_main_node(buffer, 1); // File count is 1 initially
                        sub_node *sub = create_sub_node(temp->name, 1); // file name and  in File count word count 1  initially

                        if (sub == NULL || main == NULL) 
                        {
                            printf("\033[0;31mError ❌: Unable to create main or sub node.\033[0m\n");
                            fclose(fp);
                            return FAILURE;
                        }

                        main->sub_link = sub; // Link the new sub_node
                        main->main_link = arr[ind]; // Link to existing main nodes
                        arr[ind] = main; // Insert the new main_node into the array
                    }
                }
                else if(isdigit(buffer[0]))       //checking for digits and storing in array index 26 reserved for numbers
                {
                    int digit = atoi(buffer);
                    //printf("------------>>%d\n",digit);
                    main_node *main_temp = arr[26];
                    while (main_temp != NULL) 
                    {
                        // Check if the word matches
                        if (strcmp(buffer, main_temp->word) == 0) 
                        {
                            // Word found, now check for the file in sub_nodes
                            sub_node *sub_temp = main_temp->sub_link;       //take one temp pointer to traverse through sub nodes

                            while (sub_temp != NULL) 
                            {
                                if (strcmp(temp->name, sub_temp->file_name) == 0)
                                {
                                    // File already counted, increment word count
                                    sub_temp->word_count++;
                                    break; // Exit the sub_node loop
                                }
                                sub_temp = sub_temp->slink; // Move to the next sub_node
                            }

                            // If the file was not found in sub_nodes, create a new sub_node
                            if (sub_temp == NULL) 
                            {
                                sub_node *sub = create_sub_node(temp->name, 1);
                                if (sub == NULL)
                                {
                                    printf("\033[0;31mError ❌: Unable to create sub node.\033[0m\n");
                                    fclose(fp);
                                    return FAILURE;
                                }
                                main_temp->file_count++; // Increase file count
                                sub->slink = main_temp->sub_link; // Link the new sub_node
                                main_temp->sub_link = sub; // Attach to main_node
                            }
                            break; // Exit the main_node loop
                        }
                        main_temp = main_temp->main_link; // Move to the next main_node
                    }
                    if (main_temp == NULL) 
                    {
                        main_node *main = create_main_node(buffer, 1); // File count is 1 initially
                        sub_node *sub = create_sub_node(temp->name, 1); // file name and  in File count word count 1  initially

                        if (sub == NULL || main == NULL) 
                        {
                            printf("\033[0;31mError ❌: Unable to create main or sub node.\033[0m\n");
                            fclose(fp);
                            return FAILURE;
                        }

                        main->sub_link = sub; // Link the new sub_node
                        main->main_link = arr[26]; // Link to existing main nodes
                        arr[26] = main; // Insert the new main_node into the array
                    }
                }
                else        //checking for special charecters and storing in array index 26 reserved for special charecters
                {
                    
                    main_node *main_temp = arr[27];
                    while (main_temp != NULL) 
                    {
                        // Check if the word matches
                        if (strcmp(buffer, main_temp->word) == 0) 
                        {
                            // Word found, now check for the file in sub_nodes
                            sub_node *sub_temp = main_temp->sub_link;       //take one temp pointer to traverse through sub nodes

                            while (sub_temp != NULL) 
                            {
                                if (strcmp(temp->name, sub_temp->file_name) == 0)
                                {
                                    // File already counted, increment word count
                                    sub_temp->word_count++;
                                    break; // Exit the sub_node loop
                                }
                                sub_temp = sub_temp->slink; // Move to the next sub_node
                            }

                            // If the file was not found in sub_nodes, create a new sub_node
                            if (sub_temp == NULL) 
                            {
                                sub_node *sub = create_sub_node(temp->name, 1);
                                if (sub == NULL)
                                {
                                    printf("\033[0;31mError ❌: Unable to create sub node.\033[0m\n");
                                    fclose(fp);
                                    return FAILURE;
                                }
                                main_temp->file_count++; // Increase file count
                                sub->slink = main_temp->sub_link; // Link the new sub_node
                                main_temp->sub_link = sub; // Attach to main_node
                            }
                            break; // Exit the main_node loop
                        }
                        main_temp = main_temp->main_link; // Move to the next main_node
                    }
                    if (main_temp == NULL) 
                    {
                        main_node *main = create_main_node(buffer, 1); // File count is 1 initially
                        sub_node *sub = create_sub_node(temp->name, 1); // file name and  in File count word count 1  initially

                        if (sub == NULL || main == NULL) 
                        {
                            printf("\033[0;31mError ❌: Unable to create main or sub node.\033[0m\n");
                            fclose(fp);
                            return FAILURE;
                        }

                        main->sub_link = sub; // Link the new sub_node
                        main->main_link = arr[27]; // Link to existing main nodes
                        arr[27] = main; // Insert the new main_node into the array
                    }

                }
            }
            fclose(fp); // Close the file after processing
            temp = temp->link; // Move to the next file in the list
        // printf("=========Processed file: %s\n", temp ? temp->name : "None");      //for checking
        }
        flag =0;
        return SUCCESS; // Return success at the end of processing
    }
    else
    {
        printf("\033[0;31mError ❌: Database Already created.\033[0m\n");
        return FAILURE;
    }
}
