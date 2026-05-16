#include<stdio.h>
#include<string.h>
#define SIZE 50000 //Size of the array which will store 50000 characters
//function prototype
void instructions();
void writeText();
void readText();
void editText();
void changeName();
void appendText();

int main(){

    instructions();

    int choice=0;

    while(choice !=EOF){
        puts("1.Write a text\n"
             "2.Read a text\n"
             "3.Change text file name\n"
             "4.Edit your file\n"
             "5.Append your file\n"
             "6.Press -1 to end program\n");
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
            case 4:
                editText();
                break;
            case 5:
                appendText();
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

//instructions of text editor
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
    if(fPtr!=NULL){
        char text[SIZE];
        puts("You may write your text. Press enter once and Ctrl+Z to stop:");
        while(fgets(text,SIZE,stdin)!=NULL){
            fputs(text,fPtr);
        }
        fclose(fPtr);
    }
    else{
        puts("We cannot open your file.\n");
    }
}

//Reads the text written
void readText(){
    char fullFileName[106];
    puts("What is your filename ? Please type it down including the file extension: ");
    scanf("%s",fullFileName);
    FILE*fPtr=fopen(fullFileName,"r");
    if(fPtr!=NULL){
        char text[SIZE];

        while(fgets(text,SIZE,fPtr)!='\0'){
            printf("%s",text); // Reads the text inputted in a file
        }
        puts("");
        fclose(fPtr);
    }
    else{
        puts("We cannot open your file.\n");
    }
}

//Changing file name and extension
void changeName(){
    char oldFileName[106]; //Stores user old filenmae including extension
    char filename[100]; //Allow user to change their filename
    char extension[6]; //Allow user to write their file extension
    puts("What was your old filename ? Please type including the file extension: ");
    scanf("%s",oldFileName);
    puts("What would you like your file to be named (max of 100 characters) ?\n");
    scanf("%s",filename);
    puts("What would you like your file extension to be as (max of 6 characters) ?");
    scanf("%s",extension);

    //new file name created
    int successName=rename(oldFileName,strcat(filename,extension));

    //Checks if successful or not
    if (successName==0){
        puts("Your file has been named successfully\n");
    }
    else{
        puts("File couldn't be renamed\n");
    }
}

//Allowing user to edit text
void editText(){
    char fullFileName[106];
    puts("What is the file name you want to edit ? Please type it including file extension: ");
    scanf("%s",fullFileName);
    FILE*fPtr=fopen(fullFileName,"r+");
    if(fPtr!=NULL){
        char phrase[SIZE];
        long index=0;//Which file index
        puts("Which index do you want to edit your file ?\n");
        scanf("%ld",&index);

        fseek(fPtr,index,SEEK_SET); //Moves file pointer offset from the start

        puts("You may edit your text with the phrase:"); //takes the phrase
        scanf("%s",phrase);


        fputs(phrase,fPtr);
        fclose(fPtr);
    }
    else{
        puts("We cannot open your file.\n");
    }
}

//Appending a text file


