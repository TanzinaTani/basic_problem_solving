#include <stdio.h>
#include <stdlib.h>

void min_coins(int coin_value[],int n,int amount)
{
    int i,count=0,num;
  for(  i=0; i< n; i++ )
  {

    while(amount >= coin_value[i])
    {
        num=amount/coin_value[i];
      amount= amount - num*coin_value[i];
      count=count+num;
    }
  }
  printf("The total note:%d",count);
}
int main()
{
  int i,j,n=9,amount;
  printf( "Enter amount to be paid: ");
  scanf( "%d",&amount);
    printf( "Enter total kinds of currency: ");
  scanf("%d",&n);
  int coin_value[n]; //stores coins' values as per the user
  printf( "Enter all currency values: ");
  for(i = 0;i< n; i++)//
    scanf("%d",&coin_value[i]);
  printf( "The selected currecy values are: \n");
  min_coins(coin_value,n,amount);
  return 0;
}
