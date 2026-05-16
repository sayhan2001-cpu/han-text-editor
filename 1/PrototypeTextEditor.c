#include<stdio.h>
#include<string.h>
#define SIZE 50000 //Size of the array which will store 50000 characters
//function prototype
void instructions();
void writeText();
void readText();
void changeName();

int main(){

    instructions();

    int choice=0;

    while(choice !=EOF){
        puts("1.Write a text\n2.Read a text\n3.Change text file name\n4.Press -1 to end program\n");
        scanf("%i",&choice);
        switch(choice){
            case 1:
                writeText();
                break;
            case 2:
                readText();
                break;
            case 3:
                changeName();
                break;
            case -1:
                puts("Program terminated\n");
                break;
            default:
                puts("Invalid input\n");
                break;
        }
    }
    return 0;
}

//function defintion
void instructions(){
    puts("========Welcome to the Han editor========\n");
    puts("========This is a prototype text editor========\n");
    puts("========Which will be very similar to Notepad or Vim========\n");
    puts("========It is still a work in progress========\n");
    puts("========So hopefully I can make a good text editor soon========\n");
}

//Allows you to write the text file
void writeText(){
    FILE*fPtr=fopen("sourcefile.txt","w");
    if(fopen!=NULL){
        char text[SIZE];
        puts("You may write your text. Press enter twice and Ctrl+Z to stop:\n");
        while(!feof(stdin)){
            fgets(text,SIZE,stdin); //Takes the text input
            fputs(text,fPtr);
        }
    }
    else{
        puts("We cannot open your file.\n");
    }
    fclose(fPtr);
}

//Reads the text written
void readText(){
    FILE*fPtr=fopen("sourcefile.txt","r");
    if(fopen!=NULL){
        char text[SIZE];

        while((fgets(text,SIZE,fPtr))!='\0'){
            printf("%s",text); // Reads the text inputted in a file

        }
    }
    else{
        puts("We cannot open your file.\n");
    }
    fclose(fPtr);
}

void changeName(){
    char filename[100]; //Allow user to change their filename
    char extension[6]; //Allow user to write their file extension
    puts("What would you like your file to be named (max of 100 characters) ?\n");
    scanf("%s",filename);
    puts("What would you like your file extension to be as (max of 6 characters) ?");
    scanf("%s",extension);

    //new file name created
    int successName=rename("sourcefile.txt",strcat(filename,extension));

    //Checks if successful or not
    if (successName==0){
        puts("Your file has been named successfully\n");
    }
    else{
        puts("File couldn't be renamed\n");
    }
}

