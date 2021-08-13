#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<math.h>
#define E 0.001
#define F(x)  (x*x)-(4*x)-10
#define F1(x) (2*x)-4

int main() {
    double x0,x1,fx0,fx1;
    int step=1,count=0;
    printf("Enter your initial guess value :");
    scanf("%lf",&x0);

    while(1) {
        fx0=F(x0);
        fx1=F(x0);
        x1=x0-(fx0/fx1);
        printf("\nIteration step %d : %lf",step,x1);
        step++;
        count++;

        if(fabs((x1-x0)<=E)) {
            printf("\n\n The root is : %lf\n\n",x1);
            printf("\n\nTotal Iteration steps count : %d\n\n\n",count);
            break;
        } else
            x0=x1;
    }

    getch();
    return 0;
}
