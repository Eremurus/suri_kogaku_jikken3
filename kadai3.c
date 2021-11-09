#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//Ψ の定義
double psai(double x){
    return sqrt(2)*exp(-2*(x-5)*(x-5)) / pow(M_PI, 1.0/4);
}

int main(){
    //ハイパーパラメータ
    int N = 400;
    double dx = 0.05;
    double dt = 0.001;
    double R[N+2], I[N+2], I_kari[N+2],x[N+2];
    double time_limit = 10;
    int step_num = (int)time_limit/dt;
    double L = 20;
    double t=0;
    FILE *fp;

    //xを定義
    for(int i=1; i<=N; i++){
        x[i] = (i-1/2)*dx - L/2;
    }
    //R の初期条件
    for(int i=1; i<=N; i++){
        R[i] = (psai((i-1)*dx-L/2) + psai(i*dx-L/2)) / 2;
    }
    //R の境界を初期化
    R[0] = R[N];
    R[N+1] = R[1];

    //I の初期条件
    for(int i=1; i<=N; i++){
        I[i] = -dt * (-(R[i-1] - 2*R[i] + R[i+1])/(2*dx*dx) + x[i]*x[i]*R[i]/2);
    }

    //I の境界を初期化
    I[0] = I[N];
    I[N+1] = I[1];

    //出力対象のt によって出力ファイルを変更する
    for(int i=1; i<=8; i++){
        //ファイルを開く
        if(i==1) fp = fopen("kadai3_1.txt","w");
        if(i==2) fp = fopen("kadai3_2.txt","w");
        if(i==3) fp = fopen("kadai3_3.txt","w");
        if(i==4) fp = fopen("kadai3_4.txt","w");
        if(i==5) fp = fopen("kadai3_5.txt","w");
        if(i==6) fp = fopen("kadai3_6.txt","w");
        if(i==7) fp = fopen("kadai3_7.txt","w");
        if(i==8) fp = fopen("kadai3_8.txt","w");

        //次の出力対象のt まで更新を行う
        for(int k=1; k<=1000; k++){
            t += dt;
            //R の更新
            for(int j=1; j<=N; j++){
                R[j] = R[j] + dt*(-(I[j-1]-2*I[j]+I[j+1]) / (2*dx*dx) + x[j]*x[j]*I[j]/2);            
            }
            //R の境界を更新
            R[0] = R[N];
            R[N+1] = R[1];
            //I の更新.確率密度を求めるのに一つ前の時刻のI が必要なのでI_kariに格納.
            for(int j=1; j<=N; j++){
                I_kari[j] = I[j];
                I[j] = I[j] - dt*(-(R[j-1]-2*R[j]+R[j+1]) / (2*dx*dx) + x[j]*x[j]*R[j]/2); 
            }
            //I の境界を更新
            I[0] = I[N];
            I[N+1] = I[1];       
        }
        //出力
        for(int j=1; j<=N; j++){
            double X = dx*((double)j-0.5)-L/2;
            double mitudo = R[j]*R[j] + I[j]*I_kari[j];//確率密度
            fprintf(fp,"%.8f %.8f \n", X, mitudo);
        }
        fclose(fp);
    }
}