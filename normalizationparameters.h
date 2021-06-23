#ifndef NORMALIZATIONPARAMETERS_H
#define NORMALIZATIONPARAMETERS_H


class NormalizationParameters{
public:
    NormalizationParameters();
    NormalizationParameters(double normalize_min, double normalize_max, double step_x, double step_y);

    double min;
    double max;
    double dxStep;
    double dyStep;
};

#endif // NORMALIZATIONPARAMETERS_H
