#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double u_0(double x, double b){
    return 1/((1+exp(b*x-5))*(1+exp(b*x-5)));
}

double f(double u_){
    return u_*(1-u_);
}

int main(){
    //ハイパーパラメータの定義
    int N = 4000;
    double dt = 0.001;
    double dx = 0.05;
    double b;
    double time_limit = 50.0;
    double step_num = (int)time_limit/dt;

    for(int b_=0; b_<=2; b_++){
        FILE *fp1_1_1;//ファイルに値を出力
        FILE *fp1_1_2;
        FILE *fp1_1_3;
        FILE *fp1_1_4;
        double u[N+2], u_tmp[N+2];
        double t = 0;

        if(b_==0){
            b = 0.25;
            fp1_1_1= fopen("kadai2_b025_10.txt", "w");
            fp1_1_2 = fopen("kadai2_b025_20.txt", "w");
            fp1_1_3 = fopen("kadai2_b025_30.txt", "w");
            fp1_1_4 = fopen("kadai2_b025_40.txt", "w");
            printf("%d ",b_);
        }
        if(b_==1){
            b = 0.5;
            fp1_1_1= fopen("kadai2_b05_10.txt", "w");
            fp1_1_2 = fopen("kadai2_b05_20.txt", "w");
            fp1_1_3 = fopen("kadai2_b05_30.txt", "w");
            fp1_1_4 = fopen("kadai2_b05_40.txt", "w");
            printf("%d ",b_);
        }  
        if(b_==2){
            b = 1.0;
            fp1_1_1= fopen("kadai2_b10_10.txt", "w");
            fp1_1_2 = fopen("kadai2_b10_20.txt", "w");
            fp1_1_3 = fopen("kadai2_b10_30.txt", "w");
            fp1_1_4 = fopen("kadai2_b10_40.txt", "w");
            printf("%d ",b_);
        }      
        //境界条件
        double u_L = 1, u_R = 0;
        u[0] = u_L; u[N+1] = u_R; u_tmp[0] = u_L; u_tmp[N+1] = u_R;

        //初期条件
        for(int j=1; j<=N; j++){
            u[j] = (u_0((j-1)*dx,b) + u_0(j*dx,b)) / 2;
            u_tmp[j] = 0;
        }    

        //オイラー法
        for(int i=1; i<=step_num; i++){
            t += dt;
            for(int j=1; j<=N; j++){
                u_tmp[j] = u[j] + (f(u[j])+(u[j-1]-2*u[j]+u[j+1])/(dx*dx))*dt;
            }
            for(int j=1; j<=N; j++){
                u[j] = u_tmp[j];
            }

            if(i==10000){
            printf("%.8f ",t);
                for(int j=1; j<=N; j++){
                    double x = dx*((double)j-0.5);
                    fprintf(fp1_1_1,"%.8f %.8f \n", x, u[j]);
                }
            } 
            else if(i==20000){
            printf("%.8f ",t);
                for(int j=1; j<=N; j++){
                    double x = dx*((double)j-0.5);
                    fprintf(fp1_1_2,"%.8f %.8f \n", x, u[j]);
                }           
            }
            else if(i==30000){
            printf("%.8f ",t);
                for(int j=1; j<=N; j++){
                    double x = dx*((double)j-0.5);
                    fprintf(fp1_1_3,"%.8f %.8f \n", x, u[j]);
                }              
            }
            else if(i==40000){
            printf("%.8f ",t);
                for(int j=1; j<=N; j++){
                    double x = dx*((double)j-0.5);
                    fprintf(fp1_1_4,"%.8f %.8f \n", x, u[j]);
                }             
            }
        }
        fclose(fp1_1_1);
        fclose(fp1_1_2);  
        fclose(fp1_1_3);
        fclose(fp1_1_4);
    }
}