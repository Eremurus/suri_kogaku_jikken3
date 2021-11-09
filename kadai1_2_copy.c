#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double u_0(double x){
    return exp(-(x-5)*(x-5)/2) / sqrt(2*M_PI);
}

int main(){
    //ハイパーパラメータの定義
    int N = 20;
    double dt = 0.01;
    double dx = 0.5;
    double u[N+2], u_tmp[N+2];
    double time_limit = 6.0;
    double step_num = (int)time_limit/dt;
    double t = 0;
    double J_L = 0, J_R = 0;
    bool recorded_1=false, recorded_2=false, recorded_3=false, recorded_4=false, recorded_5=false;

    FILE *fp1_1_1;//ファイルに値を出力
    FILE *fp1_1_2;
    FILE *fp1_1_3;
    FILE *fp1_1_4;
    FILE *fp1_1_5;
    fp1_1_1= fopen("kadai1_2_1.txt", "w");
    fp1_1_2 = fopen("kadai1_2_2.txt", "w");
    fp1_1_3 = fopen("kadai1_2_3.txt", "w");
    fp1_1_4 = fopen("kadai1_2_4.txt", "w");
    fp1_1_5 = fopen("kadai1_2_5.txt", "w");


    //境界条件
    double u_L = 0, u_R = 0;
    u[0] = u_L; u[N+1] = u_R; u_tmp[0] = u_L; u_tmp[N+1] = u_R;

    //uの初期条件
    for(int j=1; j<=N; j++){
        u[j] = (u_0((j-1)*dx) + u_0(j*dx)) / 2;
        u_tmp[j] = 0;
    }

    for(int i=1; i<=step_num; i++){
        for(int j=1; j<=N; j++){
            u_tmp[j] = u[j] + dt*(u[j-1]-2*u[j]+u[j+1])/(dx*dx);
        }
        
        for(int j=1; j<=N; j++){
            u[j] = u_tmp[j];
        }
        //境界条件の更新
        u_tmp[0] = u[1] - J_L*dx;
        u_tmp[N+1] = u[N] + J_R*dx;
        u[0] = u_tmp[0];
        u[N+1] = u_tmp[N+1];

        t += dt;

        //ファイルに出力
        if(i==100){
            recorded_1 = true;
            printf("%.8f", t);
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_1,"%.8f %.8f \n", x, u[j]);
            }
        } 
        else if(i==200){
            recorded_2 = true;
            printf("%.8f", t);
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_2,"%.8f %.8f \n", x, u[j]);
            }        
        }
        else if(i==300){
            recorded_3 = true;
            printf("%.8f", t);
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_3,"%.8f %.8f \n", x, u[j]);
            }       
        }
        else if(i==400){
            recorded_4 = true;
            printf("%.8f", t);
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_4,"%.8f %.8f \n", x, u[j]);
            }           
        }
        else if(i==500){
            recorded_5 = true;
            printf("%.8f", t);
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_5,"%.8f %.8f \n", x, u[j]);
            }           
        }
    }

    fclose(fp1_1_1);
    fclose(fp1_1_2);
    fclose(fp1_1_3);
    fclose(fp1_1_4);
    fclose(fp1_1_5);   
}