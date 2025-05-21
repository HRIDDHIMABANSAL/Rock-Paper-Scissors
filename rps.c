#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rnumber(int n){
    srand(time(NULL));
    return rand() % n ;
} 

int greater(char c1, char c2){
    if(c1==c2){
        return -1;
    }
    else if((c1=='r')&&(c2=='s')){
        return 1;
    }
    else if((c1=='p')&&(c2=='r')){
        return 1;
    }
    else if((c1=='s')&&(c2=='p')){
        return 1;
    }
    else if((c1=='s')&&(c2=='r')){
        return 0;
    }
    else if((c1=='r')&&(c2=='p')){
        return 0;
    }
    else if((c1=='p')&&(c2=='s')){
        return 0;
    }

}

int main(){
    int playerScore = 0, compScore = 0, temp;
    char playerChar,compChar;
    char dict[]={'r','p','s'};
    printf("Welcome to the Rock,Paper, Scissors\n");
    printf("\n");
    for(int i=0; i<3; i++){
        printf("\n");
        printf("Round %d:\n", i+1);
        //Take players input
        printf("Player 1's Turn:\n");
        printf("Choose 1 for for Rock, 2 for Paper and 3 for Scissors:");
        scanf("%d",&temp);
        getchar();
        playerChar = dict[temp-1];
        printf("You chose %c\n",playerChar);

        //Generate computers input
        printf("Computer's Turn:\n");
        temp = rnumber(3)+1;
        compChar = dict[temp-1];
        printf("Computer chose %c\n",compChar);

        //Compare the scores
        if(greater(compChar,playerChar)==1){
            compScore++;
            printf("Computer got it!\n");
        }
        else if(greater(compChar,playerChar)== -1){
            printf("Its a draw!!\n");
        }
        else{
            playerScore++;
            printf("You got it!\n");
        }
        printf("YOU:%d\t Computer:%d\n",playerScore,compScore);
    }
   
    if(playerScore>compScore){
        printf("You won the game\n");
    }
    else if(playerScore<compScore){
        printf("Computer Won the game\n");
    }
    else{
        printf("Its a draw\n");
    }
    return 0;
}