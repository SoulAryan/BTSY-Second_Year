// Write a C program to implement insertion and searching in a dictionary using linear list representation.

#include <stdio.h>
#include <string.h>
# define MAX 100

char key[MAX][100];
char value[MAX][100];
int count=0;

int main()
{
    int choice;
    char key1[100];
    int i;

    do
    {
        printf("\n\n---DICTIONARY---");
        printf("\n1> Insert");
        printf("\n2> Search");
        printf("\n3> Exit");
        
        printf("\nEnter the choice = ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
            {
                if(count==MAX)
                {
                    printf("Dictionary Overflow");
                }
                
                printf("Enter the word to be inserted = ");
                scanf("%s",key[count]);

                printf("Enter the value to be inserted = ");
                scanf(" %[^\n]s",value[count]);

                count++;
                printf("Added to dictionary");
                break;
            }
            case 2:
            {
                int found=0;
                printf("Enter the word to be searched = ");
                scanf("%s",key1);
                for(i=0;i<count;i++)
                {
                    if(strcmp(key[i],key1)==0)
                    {
                        printf("Word Found\n");
                        printf("Meaning is %s",value[i]);
                        found=1;
                        break;
                    }
                }

                if(!found)
                {
                    printf("Key not found in the dictionary");          
                }
                break;
            }    
            case 3:
            {
                printf("\nExiting The Program....");
                break;
            }    
            
            default:
                printf("\nInvalid input");  
                break;  
        
        }
    }while(choice!=3);

       
    return 0;
}