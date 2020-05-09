//
//  main.cpp
//  shooting
//
//  Created by Chen Xie on 2019/11/4.
//  Copyright © 2019 Chen Xie. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <random>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    const double pai = 3.1415926;
    double g = -9.8;
    double Rball = 0.123;
    double Rbask = 0.225;
    double Hbask = 3.05;
    double angle = 0;
    double Hboard = 1.05;
    double r = 0.15;
    double L = 5.8;
    double v = 10
    ;
    double dt = 0.00002;
    double e = 0.8;
    double R[2]={0,2};
    double Rst;
    double vx , vy ,t ;
    int i,j,k;
    for(i = 0;i <= 90;i++){
        angle = i;
        vx = v * cos(angle*pai/180);
        vy = v * sin(angle*pai/180);
      for (j = 1;j < 1000000001;j++){
        Rst = R[1];
        R[0] += vx * dt;
        R[1] += vy * dt + 0.5 * g * dt * dt;
        vy += g * dt;
          t = j * dt;
          if((R[1] < 2) || (R[0] > L) || (R[0] < 0)){
              R[0] = 0;
              R[1] = 2;
              vy = 0;
              break;
          }
        // printf("%f, %f, %f, %f\n",t,angle,R[0],R[1]);
          if ((R[0] <= (L + 0.001)) && (R[0] >= (L - 0.001)) && (R[1] >= Hbask) && (R[1] <= (Hbask + Hboard))){
              vx = -e * vx;
          }
          if ((R[0] >= (L - r - 2 * Rbask + Rball)) && (R[0] <= (L - r - Rball)) && (R[1] <= (Hbask+0.00001)) && (R[1] >= (Hbask-0.00001)) && (Rst > R[1])){
              R[0] = 0;
              R[1] = 2;
              vy = 0;
              vx = v * cos(angle*pai/180);
              vy = v * sin(angle*pai/180);
              for(k = 1;k < 1000000001;k++){
                  R[0] += vx * dt;
                  R[1] += vy * dt + 0.5 * g * dt * dt;
                  vy += g * dt;
                  t = k * dt;
                  if ((R[0] <= (L + 0.001)) && (R[0] >= (L - 0.001)) && (R[1] >= Hbask) && (R[1] <= (Hbask + Hboard))){
                            vx = -e * vx;
                        }
                  if(k % 100 == 0){
                  printf("%f, %f, %f, %f,\n",vx,angle,R[0],R[1]);
                  }
                  if((R[1] < 2) || (R[0] > L) || (R[0] < 0)){
                              R[0] = 0;
                              R[1] = 2;
                              k = 0;
                              break;
                  }
              }
        }
      }
    }
    return 0;
}
