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

    FILE *fp1_1_1;//ファイルに値を出力
    FILE *fp1_1_2;
    FILE *fp1_1_3;
    FILE *fp1_1_4;
    FILE *fp1_1_5;
    fp1_1_1= fopen("kadai1_1_1.txt", "w");
    fp1_1_2 = fopen("kadai1_1_2.txt", "w");
    fp1_1_3 = fopen("kadai1_1_3.txt", "w");
    fp1_1_4 = fopen("kadai1_1_4.txt", "w");
    fp1_1_5 = fopen("kadai1_1_5.txt", "w");


    //境界条件
    double u_L = 0, u_R = 0;
    u[0] = u_L; u[N+1] = u_R; u_tmp[0] = u_L; u_tmp[N+1] = u_R;

    //uの初期条件
    for(int j=1; j<=N; j++){
        u[j] = (u_0((j-1)*dx) + u_0(j*dx)) / 2;
        u_tmp[j] = 0;
    }

    //更新
    for(int i=1; i<=step_num; i++){
        t += dt;
        for(int j=1; j<=N; j++){
            u_tmp[j] = u[j] + dt*(u[j-1]-2*u[j]+u[j+1])/(dx*dx);
        }
        
        for(int j=1; j<=N; j++){
            u[j] = u_tmp[j];
        }

        //出力
        if(i==100){
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_1,"%.8f %.8f \n", x, u[j]);
            }
        } 
        else if(i==200){
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_2,"%.8f %.8f \n", x, u[j]);
            }          
        }
        else if(i==300){
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_3,"%.8f %.8f \n", x, u[j]);
            }          
        }
        else if(i==400){
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_4,"%.8f %.8f \n", x, u[j]);
            }         
        }
        else if(i==500){
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_5,"%.8f %.8f \n", x, u[j]);
            }              
        }
    }

    //ファイルを閉じる
    fclose(fp1_1_1);
    fclose(fp1_1_2);
    fclose(fp1_1_3);
    fclose(fp1_1_4);
    fclose(fp1_1_5);   
}