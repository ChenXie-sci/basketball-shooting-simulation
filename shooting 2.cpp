//
//  main.cpp
//  shooting-2
//
//  Created by Chen Xie on 2019/11/20.
//  Copyright © 2019 Chen Xie. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <random>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::default_random_engine e;
    std::normal_distribution<double> d(0,0.0001);
    const double pai = 3.1415926;
    const double g = -9.8;
    double Rball = 0.123;
    double Rbask = 0.225;
    double Hbask = 3.05;
    double Hboard = 1.05;
    double r = 0.15;
    double L = 5.8;
    double v = 9;
    double dt = 0.00002;
    double e1 = 0.8;
    double R[2]={0,2};
    double angle[90];
    double anglest[90];
    double Rst;
    double step = 1000001;
    double vx , vy ,t , vdis;
    int i,j,k;
    for(i = 0;i < 90;i++){
        angle[i] = 0;
        anglest[i] =0;
    }
    for(i = 0;i < 90;i++){
      angle[i] = i;
      vx = v * cos(angle[i]*pai/180);
      vy = v * sin(angle[i]*pai/180);
      for (j = 1;j < step;j++){
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
       if ((R[0] <= (L + 0.001)) && (R[0] >= (L - 0.001)) && (R[1] >= Hbask) && (R[1] <= (Hbask + Hboard))){
                   vx = -e1 * vx;
       }
               if ((R[0] >= (L - r - 2 * Rbask + Rball)) && (R[0] <= (L - r - Rball)) && (R[1] <= (Hbask+0.00001)) && (R[1] >= (Hbask-0.00001)) && (Rst > R[1])){
                   anglest[i] = angle[i];
                //   printf("%f\n",anglest[i]);
               }
      }
    }
    // probability
    double count = 0;
    for(i = 0;i < 90;i++){
        if(anglest[i] != 0){
            for(j = 0;j < 100000;j++){
                srand(time(0));
                vdis = d(e);
                v -= vdis;
                vx = v * cos(angle[i]*pai/180);
                     vy = v * sin(angle[i]*pai/180);
                     for (k = 1;k < step;k++){
                     Rst = R[1];
                     R[0] += vx * dt;
                     R[1] += vy * dt + 0.5 * g * dt * dt;
                     vy += g * dt;
                       t = k * dt;
                       if((R[1] < 2) || (R[0] > L) || (R[0] < 0)){
                           R[0] = 0;
                           R[1] = 2;
                           vy = 0;
                           v = 9;
                           break;
                       }
                      if ((R[0] <= (L + 0.001)) && (R[0] >= (L - 0.001)) && (R[1] >= Hbask) && (R[1] <= (Hbask + Hboard))){
                                  vx = -e1 * vx;
                      }
                              if ((R[0] >= (L - r - 2 * Rbask + Rball)) && (R[0] <= (L - r - Rball)) && (R[1] <= (Hbask+0.00001)) && (R[1] >= (Hbask-0.00001)) && (Rst > R[1])){
                                  count++;
                              }
                     }
            }
            printf("%f, %f\n",anglest[i],count/100000);
            count = 0;
        }
    }
    return 0;
}
