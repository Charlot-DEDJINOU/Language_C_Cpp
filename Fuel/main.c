#include <stdio.h>
void main()
{
  int tour,ina,rest,i;
  scanf("%d",&tour);
  int res[tour];
  for(i=0;i<tour;i++)
  {
      scanf("%d %d",&ina,&rest);
      if(rest+60>=ina)
        res[i]=1500*ina;
      else
        res[i]=(rest+60)*1500+(ina-rest-60)*3000;
  }
  for(i=0;i<tour;i++)
   printf("\n%d",res[i]);
}
