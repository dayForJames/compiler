#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void 
mse(float *w, float* X, float* y, float* result, int feature_count, int samples_count)
{
    for (int sample = 0; sample < samples_count; sample++)
    {
        float y_pred = 0;
        for (int i = 0; i < feature_count; i++)
        {
            y_pred += w[i] * X[sample * feature_count + i];
        }

        result[sample] = y[sample] - y_pred;
    }
}

float
d_mse(float* X, float *loss, float* d_loss, int feature_count, int samples_count)
{
    for (int sample = 0; sample < samples_count; sample++)
    {
        for (int j = 0; j < feature_count; j++)
        {
            d_loss[sample * feature_count + j] = -2.f * X[sample * feature_count + j] * loss[sample * feature_count + j];
        }
    }
}

void 
init_weights(float* w, int feature_count)
{
    srand(time(NULL));

    for (int i = 0; i < feature_count; i++)
    {
        w[i] = (-1.f + 2.f) * rand() / ((float)feature_count * RAND_MAX); 
    }
}

void
GD(float *w, float* X, float* y, int feature_count, int samples_count)
{
    
}

int
main(int argc, char const *argv[])
{
    float X[] = {1, 2, 3, 1, 9, 7, 3, 1, 0};
    float y[] = {3, 1, 4};
    float w[3] = {0};
    float loss_arr[3] = {0}, d_loss[9] = {0};

    int feature_count = 3, samples_count = 3;
    
    init_weights(w, feature_count);
    mse(w, X, y, loss_arr, feature_count, samples_count);
    d_mse(X, loss_arr, d_loss, feature_count, samples_count);

    for (int i = 0; i < samples_count; i++)
    {
        for (int j = 0; j < feature_count; j++)
        {
            printf("%f ", d_loss[i * feature_count + j]);
        }

        printf("\n");
    }

    return 0;
}
