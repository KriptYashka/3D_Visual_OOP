#include "normalizationparameters.h"

NormalizationParameters::NormalizationParameters(){}

NormalizationParameters::NormalizationParameters(float _min, float _max, float _dxStep, float _dyStep){
    min = _min;
    max = _max;
    dxStep = _dxStep;
    dyStep = _dyStep;
}
