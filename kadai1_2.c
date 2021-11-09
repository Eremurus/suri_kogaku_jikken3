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

    while(t < 1){
        for(int j=1; j<=N; j++){
            u_tmp[j] = u[j] + dt*(u[j-1]-2*u[j]+u[j+1]);
        }
        
        for(int j=1; j<=N; j++){
            u[j] = u_tmp[j];
        }

        u_tmp[0] = u[1] - J_L*dx;
        u_tmp[N+1] = u[N] + J_R*dx;
        u[0] = u_tmp[0];
        u[N+1] = u_tmp[N+1];

        t += dt;
    }
    printf("%.8f",t);

    while(t < 2){
        for(int j=1; j<=N; j++){
            u_tmp[j] = u[j] + dt*(u[j-1]-2*u[j]+u[j+1]);
        }
        
        for(int j=1; j<=N; j++){
            u[j] = u_tmp[j];
        }

        u_tmp[0] = u[1] - J_L*dx;
        u_tmp[N+1] = u[N] + J_R*dx;
        u[0] = u_tmp[0];
        u[N+1] = u_tmp[N+1];

        t += dt;
    }
    printf("%.8f",t);
    while(t < 3){
        for(int j=1; j<=N; j++){
            u_tmp[j] = u[j] + dt*(u[j-1]-2*u[j]+u[j+1]);
        }
        
        for(int j=1; j<=N; j++){
            u[j] = u_tmp[j];
        }

        u_tmp[0] = u[1] - J_L*dx;
        u_tmp[N+1] = u[N] + J_R*dx;
        u[0] = u_tmp[0];
        u[N+1] = u_tmp[N+1];

        t += dt;
    }
    printf("%.8f",t);

    while(t < 4){
        for(int j=1; j<=N; j++){
            u_tmp[j] = u[j] + dt*(u[j-1]-2*u[j]+u[j+1]);
        }
        
        for(int j=1; j<=N; j++){
            u[j] = u_tmp[j];
        }

        u_tmp[0] = u[1] - J_L*dx;
        u_tmp[N+1] = u[N] + J_R*dx;
        u[0] = u_tmp[0];
        u[N+1] = u_tmp[N+1];

        t += dt;
    }
    printf("%.8f",t);

    while(t < 5){
        for(int j=1; j<=N; j++){
            u_tmp[j] = u[j] + dt*(u[j-1]-2*u[j]+u[j+1]);
        }
        
        for(int j=1; j<=N; j++){
            u[j] = u_tmp[j];
        }

        u_tmp[0] = u[1] - J_L*dx;
        u_tmp[N+1] = u[N] + J_R*dx;
        u[0] = u_tmp[0];
        u[N+1] = u_tmp[N+1];

        t += dt;
    }
    printf("%.8f",t);



    fclose(fp1_1_1);
    fclose(fp1_1_2);
    fclose(fp1_1_3);
    fclose(fp1_1_4);
    fclose(fp1_1_5);   
}