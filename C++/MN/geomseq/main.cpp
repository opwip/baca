//Yaroslav Kolesnik
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    while(n--){
        float P, S;
        scanf("%e %e", &P, &S);

        float x2 = cbrtf(P);
        float x1, x3;
        bool ok = true;

        if(fabsf(x2) < 1e-20f){
            x2 = 0.0f;
            x1 = S;
            x3 = 0.0f;
            if(fabsf(S) < 1e-30f){
                x1 = 0.0f; ok = true;
            } else if(x1 < x3){
                ok = false;
            }
        } else {
            float R = S / x2;
            float u = R - 1.0f;
            float disc = u * u - 4.0f;

            if(disc < 0.0f){
                float rel = fabsf(disc) / (u * u + 4.0f + 1e-30f);
                if(rel < 1e-4f)
                    disc = 0.0f;
                else
                    ok = false;
            }

            if(ok){
                float sq = sqrtf(disc);

                float q1, q2;
                if(u >= 0.0f){
                    q1 = (u + sq) * 0.5f;
                    q2 = (q1 != 0.0f) ? 1.0f / q1 : 0.0f;
                } else {
                    q1 = (u - sq) * 0.5f;
                    q2 = (q1 != 0.0f) ? 1.0f / q1 : 0.0f;
                }

                float q_small = (fabsf(q1) <= fabsf(q2)) ? q1 : q2;
                float q_large = (fabsf(q1) <= fabsf(q2)) ? q2 : q1;
                float q_use = (x2 > 0.0f) ? q_small : q_large;

                if(fabsf(q_use) < 1e-30f){
                    x1 = 0.0f; x3 = 0.0f;
                } else {
                    x1 = x2 / q_use;
                    x3 = x2 * q_use;
                }

                if(x1 < x3){
                    float q_alt = (q_use == q_small) ? q_large : q_small;
                    if(fabsf(q_alt) < 1e-30f){
                        x1 = 0.0f; x3 = 0.0f;
                    } else {
                        x1 = x2 / q_alt;
                        x3 = x2 * q_alt;
                    }
                }

                float R_check = x1 / x2 + 1.0f + x3 / x2;
                float err = fabsf(R_check - R) / (fabsf(R) + fabsf(R_check) + 1e-30f);
                if(err > 1e-3f) ok = false;
            }
        }

        if(!ok){
            printf("0.0000000000e+00 0.0000000000e+00 0.0000000000e+00\n");
        } else {
            printf("%.10e %.10e %.10e\n", x1, x2, x3);
        }
    }
    return 0;
}