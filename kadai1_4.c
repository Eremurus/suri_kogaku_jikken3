#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//u の初期条件
double u_0(double x){
    return exp(-(x-5)*(x-5)/2) / sqrt(2*M_PI);
}

int main(){
    //ハイパーパラメータの定義
    int N = 200;
    double dx = 0.05;
    double dt = 0.01;
    double t = 0;
    double time_limit = 6.0;
    double c_const = dt/(dx*dx);
    double J_L = 0, J_R = 0;
    double a[N+2], b[N+1],c[N+1],alpha[N+2],beta[N+2],z[N+2],u[N+2],y[N+2];
    a[0] = 0; a[N+1] = 0; b[0] = 0;  c[0] = 0;  
    alpha[0] = 0; alpha[N+1] = 0; beta[0] = 0; beta[N+1] = 0; u[N+1] = 0;
    int step_num = (int)time_limit/dt;

    FILE *fp1_1_1;//ファイルに値を出力
    FILE *fp1_1_2;
    FILE *fp1_1_3;
    FILE *fp1_1_4;
    FILE *fp1_1_5;
    fp1_1_1= fopen("kadai1_4_1.txt", "w");
    fp1_1_2 = fopen("kadai1_4_2.txt", "w");
    fp1_1_3 = fopen("kadai1_4_3.txt", "w");
    fp1_1_4 = fopen("kadai1_4_4.txt", "w");
    fp1_1_5 = fopen("kadai1_4_5.txt", "w");

    //u の初期条件
    for(int j=1; j<=N; j++){
        u[j] = (u_0((j-1)*dx) + u_0(j*dx)) / 2;
    }

    //Ax=z におけるA からa,b,c を求める
    for(int j=1; j<=N; j++){
        a[j] = 1+c_const;
        b[j] = -c_const/2;
        c[j] = -c_const/2;
    }
    a[1] = 1+c_const/2;
    a[N] = 1+c_const/2;

    //LU 分解
    for(int j=1; j<=N; j++){
        alpha[j] = a[j] - c[j-1]*beta[j-1];
        beta[j] = b[j]/alpha[j];
    }
    beta[N] = 0.0;

    for(int i=1; i<=step_num; i++){
        t += dt;
        //z を計算
        z[1] = (1-c_const/2)*u[1] + c_const*J_L*dx + c_const*u[2]/2;
        for(int j=2; j<=N-1; j++){
            z[j] = (1-c_const)*u[j] + c_const*u[j-1]/2 + c_const*u[j+1]/2;
        }
        z[N] = (1-c_const/2)*u[N] + c_const*J_R*dx + c_const*u[N-1]/2;

        //y を計算
        for(int j=1; j<=N; j++){
            y[j] = (z[j]-c[j-1]*y[j-1])/alpha[j];
        }

        //u を計算
        for(int j=N; j>=1; j--){
            u[j] = y[j] - beta[j]*u[j+1];
        }

        //ファイル出力
        if(i==100){
            printf("%.8f", t);
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_1,"%.8f %.8f \n", x, u[j]);
            }
        } 
        else if(i==200){
            printf("%.8f", t);
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_2,"%.8f %.8f \n", x, u[j]);
            }        
        }
        else if(i==300){
            printf("%.8f", t);
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_3,"%.8f %.8f \n", x, u[j]);
            }             
        }
        else if(i==400){
            printf("%.8f", t);
            for(int j=1; j<=N; j++){
                double x = dx*((double)j-0.5);
                fprintf(fp1_1_4,"%.8f %.8f \n", x, u[j]);
            }          
        }
        else if(i==500){
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