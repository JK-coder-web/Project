#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Maxi_Word_Len 100 //maximum word length
#define Dict_Size 2000    //dictionary size

typedef struct Node
{
    char word[Maxi_Word_Len];
    struct Node* next;
}Node;

typedef struct Dictionary
{
    Node* hash_table[Dict_Size];
}Dictionary;

int hash_function(char* word)
{
    int sum=0;
    for(int i=0;word[i]!='\0';i++)
    {
        sum+=word[i];
    }
    return sum%Dict_Size;
}

int char_count(char ch[Maxi_Word_Len])
{
    int count=0;
    for(register int i=0;i<Maxi_Word_Len;i++)
    {
        if(ch[i]=='\0')
        {
            break;
        }
        count++;
    }
    return count;
}

void loading_data(Dictionary* dict,char* word)
{
    int index=hash_function(word);
    Node* new_node=(Node*)malloc(sizeof(Node));
    strcpy(new_node->word,word);
    new_node->next=dict->hash_table[index];
    dict->hash_table[index]=new_node;
}

int search_word(Dictionary* dict,char* word)
{
    int index=hash_function(word);
    Node* current=dict->hash_table[index];
    while(current!=NULL)
    {
        if(strcmp(current->word,word)==0)
        {
            return 1;   //word found in the dictionary
        }
        current=current->next;
    }
    return 0;
}

void free_dict(Dictionary* dict)
{
    for(int i=0;i<Dict_Size;i++)
    {
        Node* current=dict->hash_table[i];
        while(current!=NULL)
        {
            Node* temp=current;
            current=current->next;
            free(temp);
        }
    }
}

void check_spelling(Dictionary* dict,char* filename)
{
    FILE *file=fopen(filename,"r");
    if(file==NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char word[Maxi_Word_Len];
    while(!feof(file))
    {
        fscanf(file,"%s",word);
        int num=char_count(word);
        if(word[num-1]==',' || word[num-1]=='.')
        {
            word[num-1]='\0';
        }
        if(!search_word(dict,word))
        {
            printf("Misspelled word: %s\n",word);
        }
    }

    fclose(file);
}

int main()
{
    Dictionary dict;
    for(int i=0;i<Dict_Size;i++)
    {
        dict.hash_table[i]=NULL;
    }

    //Load the dictionary
    FILE *dict_file=fopen("dictionary.txt","r");
    if(dict_file==NULL)
    {
        printf("Error opeining dictionary file.\n");
        return 1;
    }

    char dict_word[Maxi_Word_Len];
    while(!feof(dict_file))
    {
        fscanf(dict_file,"%s",dict_word);
        loading_data(&dict,dict_word);
    }

    fclose(dict_file);

    //Check the text file
    check_spelling(&dict,"text.txt");

    //Free the dictionary memory
    free_dict(&dict);
    return 0;
}
