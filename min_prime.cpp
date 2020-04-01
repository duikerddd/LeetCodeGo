#include<math.h>
int getN(int n)
{

    int result=0;

    int leftNum=0;

    int rightNum=0;

    //判断左侧最近的素数

    for(int j=n+1;j>n;j++){

        if(isSushu(j)){

           rightNum=j;

           break;

        }                

     }

    //判断右侧最近的素数

    for(int i=n;i>=0;i--){

        if(isSushu(i)){

           leftNum=I;

           break;

        }                

     }

   //判断最近距离

    if((n-leftNum)>(rightNum-n)){

       result=rightNum;

    }else{

      result=leftNum;     

    }

  return result;

}


bool isSushu(int n)
{

    if(n<=1){
        return false;
    }

    int max = sqrt(n);
    for(int i=2;i<max;i++){

        if(n%i==0){
          return false;
       }

   }    

   return true;

 }
