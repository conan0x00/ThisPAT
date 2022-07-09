#include<stdio.h>
#include <stdlib.h>

#define Nmax 100000
typedef struct DeCai
{
  int ID;
  int Level; //level决定考生属于哪一类，德才兼备100，德胜才10，德才亡1，其它过线0
  int DeG;
  int CaiG;
}DC;

int cmp(const void *a, const void *b)
{
  if((*(DC*)a).Level != (*(DC*)b).Level)
    return (*(DC*)b).Level - (*(DC*)a).Level;
  else if ((*(DC*)a).DeG + (*(DC*)a).CaiG != (*(DC*)b).DeG + (*(DC*)b).CaiG)
    return (*(DC*)b).DeG + (*(DC*)b).CaiG - (*(DC*)a).DeG - (*(DC*)a).CaiG;
  else if ((*(DC*)a).DeG != (*(DC*)b).DeG)
    return (*(DC*)b).DeG - (*(DC*)a).DeG;
  else
    return (*(DC*)a).ID - (*(DC*)b).ID;
}

int main()
{
  int i=0,id=0,dg=0,cg=0;
  int N=0,L=0,H=100,M=0;
  struct DeCai *data,temp;

  scanf("%d %d %d",&N,&L,&H);
  if(N<1 || N >Nmax || L< 60|| H >= 100 || L > H)
    return -1;

  data = (struct DeCai *)malloc(sizeof(struct DeCai)*N);

  M = 0;
  for (i = 0; i < N; ++i)  //读入数据
  {
    scanf("%d %d %d",&temp.ID,&temp.DeG,&temp.CaiG);
    if (temp.DeG >= L && temp.CaiG >= L) //达到最低录取线
    {
      data[M]=temp;
      if(temp.DeG >= H && temp.CaiG >= H)
        data[M].Level = 100;
      else if(temp.DeG >= H && temp.CaiG < H)
        data[M].Level = 10;
      else if(temp.DeG < H && temp.CaiG < H && temp.DeG >= temp.CaiG)
        data[M].Level = 1;
      else
          data[M].Level = 0;
      M++;
    }
  }

  qsort(data,M,sizeof(struct DeCai),cmp);

  printf("%d\n",M);
  for (i = 0; i < M-1; ++i)
    printf("%d %d %d\n",data[i].ID,data[i].DeG,data[i].CaiG);

  if( M > 0) //有人达标
    printf("%d %d %d",data[M-1].ID,data[M-1].DeG,data[M-1].CaiG);

  free(data);
  return 0;
}
