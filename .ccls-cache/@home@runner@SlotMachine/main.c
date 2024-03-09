#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];

void printBoard() {
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

void resetBoard() {
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      board[i][j] = ' ';
    }
  }
}

void randomNumbers() {
  srand(time(NULL));
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      int num = rand() % 5 + 1;
      board[i][j] = num + '0'; 
    }
  }
}

int checkWinnings(int row, int money, int totalMoney) {
  if(totalMoney < money) {
    printf("You can't bet more than you have!\n");
    return totalMoney;
  }
  switch(row) {
    case 1:
      if(board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
        totalMoney = totalMoney + (money*3);
      } else {
        totalMoney = totalMoney - (money*3);
      }
      break;
    case 2:
    if(board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
      totalMoney = totalMoney + (money*3);
    } else {
      totalMoney = totalMoney - (money*3);
    }
    break;
    case 3:
    if(board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
      totalMoney = totalMoney + (money*3);
    } else {
      totalMoney = totalMoney - (money*3);
    }
    break;
  }
  return totalMoney;
}

int main()
{
  char response = ' ';
  int deposit, row, money,totalMoney;
  printf("Enter your deposit: ");
  scanf("%d",&deposit);
  printf("Enter how much you enter for 1 row: ");
  scanf("%d",&money);
  do{
    printf("Which row do you pick(1-3): ");
    scanf("%d",&row);
    while(row > 3 || row < 1) {
      printf("Invalid row!\n");
      scanf("%d",&row);
    }
    resetBoard();
    randomNumbers();
    printBoard();
    totalMoney = checkWinnings(row, money, deposit);
    deposit = totalMoney;
    if(totalMoney == 0){
      break;
    }
    printf("Your total money is: %d\n", totalMoney);
    printf("Do you want to continue?(y-n)\n");
    printf("Response: ");
    scanf("%s",&response);
  }while(response == 'y' || response == 'Y');
  printf("You ended up with %d money", totalMoney);
}