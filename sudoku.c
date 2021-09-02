#include<stdio.h>
int main(){
    int s[9][9]={{5,3,4,6,7,8,9,1,2},
                {6,7,2,1,9,5,3,4,8},
                {1,9,8,3,4,2,5,6,7},
                {8,5,9,7,6,1,4,2,3},
                {4,2,6,8,5,3,7,9,1},
                {7,1,3,9,2,4,8,5,6},
                {9,6,1,5,3,7,2,8,4},
                {2,8,7,4,1,9,6,3,5},
                {3,4,5,2,8,6,1,7,9}};

     int i,a,c,p,q,v,d,w,g,b,r,t,f,n,row[9],col[9],l,m;


    for(a=0;a<9;a++)

    {
        printf("\n");

        for(b=0;b<9;b++){
        printf("%d\t",s[a][b]);

        }

    }

   for(a=0;a<9;a++)
    {
        row[a]=0;
        for(b=0;b<9;b++){
            row[a]=row[a]+s[a][b];
        }
    }


for(b=0;b<9;b++){
         col[b]=0;
        for(a=0;a<9;a++){
            col[b]=col[b]+s[a][b];
        }
    }
     c=0;
    for(a=0;a<9;a++){
    for(i=0;i<9;i++){
        if(s[a][i]>=1&&s[a][i]<=9){
                c=c+s[a][i];

        }
    }
    }
       p=0;
      for(a=0;a<3;a++){
    for(i=0;i<3;i++){
        if(s[a][i]>=1&&s[a][i]<=9){
                p=p+s[a][i];

        }
    }
      }
      q=0;
      for(a=0;a<3;a++){
    for(i=3;i<6;i++){
        if(s[a][i]>=1&&s[a][i]<=9){
                q=q+s[a][i];

        }
    }
      }

        r=0;
      for(a=0;a<3;a++){
    for(i=6;i<9;i++){
        if(s[a][i]>=1&&s[a][i]<=9){
                r=r+s[a][i];
        }
    }
      }

      t=0;
      for(a=3;a<6;a++){
    for(i=0;i<3;i++){
        if(s[a][i]>=1&&s[a][i]<=9){
                t=t+s[a][i];
        }
    }
      }

      b=0;
      for(a=3;a<6;a++){
    for(i=3;i<6;i++){
        if(s[a][i]>=1&&s[a][i]<=9){
                b=b+s[a][i];
        }
    }
      }

      w=0;
      for(a=3;a<6;a++){
    for(i=6;i<9;i++){
        if(s[a][i]>=1&&s[a][i]<=9){
                w=w+s[a][i];
        }
    }
      }

      v=0;
      for(a=6;a<9;a++){
    for(i=0;i<3;i++){
        if(s[a][i]>=1&&s[a][i]<=9){
                 v=v+s[a][i];
        }
    }
      }
      f=0;
      for(a=6;a<9;a++){
    for(i=3;i<6;i++){
        if(s[a][i]>=1&&s[a][i]<=9){
                f=f+s[a][i];
        }
    }
      }

      g=0;
      for(a=6;a<9;a++){
    for(i=6;i<9;i++){
        if(s[a][i]>=1&&s[a][i]<=9){
                 g=g+s[a][i];
        }
    }
      }

     l=((9*(9+1))/2);
     m=0;
for(n=0;n<9;n++){
if(l==row[n] && l==col[n] && row[n]==col[n] && v==45 && w==45 && p==45 && q==45 && r==45 && t==45 && g==45 && f==45 && b==45 && c==405){
        m++;
}
}
if(m==9){
      printf("\n\nyes, sudoku is valid\n");
     }

  else{
    printf("\n\nno, sudoku is not valid\n");
}
}


