#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#ifndef HEADER_H
#define HEADER_H
#define INDEX 28

// Structure to represent a file information node in a linked list
typedef struct file_Info
{
    char name[25];
    struct  file_Info *link;
}file_Slist;

// Enum to represent the status of operations
typedef enum
{
    FAILURE,
    SUCCESS
}status;

// Structure for sub-node to represent word occurrence in files
typedef struct sub_node
{
    char file_name[20];
    int word_count;
    struct sub_node *slink;
}sub_node;

// Structure for main-node to represent a word and its occurrences in multiple files
typedef struct main_node
{
    char word[20];
    int file_count;
    sub_node *sub_link;
    struct main_node *main_link;
}main_node;


/* Function Prototypes */

// Function to read input from command line arguments and validate them
status read_and_validate(int argc, char *argv[], file_Slist **head);

// Function to create a new file_Slist node with the given file name
file_Slist* create_node(const char *name);

// Function to print the linked list of file names
void print(file_Slist **head);

// Function to create the database for word counts and files
status create_DB(file_Slist **head, main_node **arr);

// Function to create a new main_node for the given word and its file count
main_node* create_main_node(char *buffer, int count); 

// Function to create a new sub_node for the given file name and word count
sub_node* create_sub_node(char *str, int count);

// Function to display the database contents
status Display_DB(main_node **arr);

// Function to search for a word in the database
status Search_DB(main_node **arr, char *str);

// Function to save the database to a file
status Save_DB(main_node **arr, file_Slist **head, FILE *fp);

// Function to update the database from a file
status update_data(FILE *fp, main_node **arr, file_Slist **head);

// Function to delete a node from the file linked list based on the file name
void delete_node(file_Slist **head, const char *file_name);

#endif 