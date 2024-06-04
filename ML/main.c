#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


float 
mse(float *w, float* X, float* y, int feature_count, int samples_count)
{
    float result = 0;

    for (int sample = 0; sample < samples_count; sample++)
    {
        float y_pred = 0;

        for (int i = 0; i < feature_count; i++)
        {
            y_pred += w[i] * X[sample * feature_count + i];
        }

        result += (y[sample] - y_pred) * (y[sample] - y_pred);
    }

    return result / feature_count;
}

void
d_mse(float *w, float* X, float* y, float* d_loss, int feature_count, int samples_count)
{
    for (int d_j = 0; d_j < feature_count; d_j++)
    {
        for (int i = 0; i < samples_count; i++)
        {
            float tmp = 0;

            for (int j = 0; j < feature_count; j++)
            {
                tmp += w[j] * X[i * feature_count + j];
            }

            d_loss[d_j] += X[i * feature_count + d_j] * (y[i] - tmp);
        }

        d_loss[d_j] *= -2.f / (float)feature_count;
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
update_weights(float* w, float* d_loss, int feature_count, float alpha)
{
    for (int i = 0; i < feature_count; i++)
    {
        w[i] -= alpha * d_loss[i];
    }
}

float
L2(float* vector, int length)
{
    float size = 0;

    for (int i = 0; i < length; i++)
    {
        size += vector[i] * vector[i];
    }

    return sqrt(size);
}

void
GD(float* X, float* y, int feature_count, int samples_count)
{
    float w[3] = {0};
    float loss = 0, d_loss[3] = {0};
    float EPS = 0.3;

    init_weights(w, feature_count);

    do
    {
        loss = mse(w, X, y, feature_count, samples_count);
        d_mse(w, X, y, d_loss, feature_count, samples_count);

        update_weights(w, d_loss, feature_count, 0.001);

        printf("%f\n", loss);
    }
    while (loss > EPS);
}

void 
test(float* w, float* X, float* y, int feature_count, int samples_count)
{
    
}

int
main(int argc, char const *argv[])
{
    float X[] = {1, 2, 3, 1, 9, 7, 3, 1, 0};
    float y[] = {3, 1, 4};

    int feature_count = 3, samples_count = 3;
    
    GD(X, y, feature_count, samples_count);

    return 0;
}
