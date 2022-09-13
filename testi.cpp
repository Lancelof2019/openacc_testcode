tream>
#include<openacc.h>
#define N 50

using namespace std;

int main(){

	int a[N][N];
  int i,j,temp=0;
#pragma acc data copyin(a[:N][:N],temp) //copyout(a[:N][:N],temp)//present(i,j)
{

        #pragma acc kernels present(a[:N][:N],temp)  //reduction(+:a[:N])//copyout(a[:N],i,j)
	{
 
	     	
	     for(int i=0;i<N;i++){
	
	    	for(int j=0;j<N;j++){
                 a[i][j]=j*2+i;         
                  
		}
	
)
          }
      

	}

        

        #pragma acc update self(a[:N],temp)


}
cout<<"a[N][N]"<<a[N-1][N-1]<<endl;
//cout<<i<<endl;
//cout<<j<<endl;
cout<<temp<<endl;
}
