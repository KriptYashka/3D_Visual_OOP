#ifndef NORMALIZATIONPARAMETERS_H
#define NORMALIZATIONPARAMETERS_H


class NormalizationParameters
{
public:
    NormalizationParameters();
    NormalizationParameters(float _min, float _max, float _dxStep, float _dyStep);

    float min;
    float max;
    float dxStep;
    float dyStep;
};

#endif // NORMALIZATIONPARAMETERS_H
