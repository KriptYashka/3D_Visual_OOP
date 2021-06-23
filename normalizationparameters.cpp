#include "normalizationparameters.h"

NormalizationParameters::NormalizationParameters(){}

NormalizationParameters::NormalizationParameters(double _min, double _max, double _dxStep, double _dyStep){
    min = _min;
    max = _max;
    dxStep = _dxStep;
    dyStep = _dyStep;
}
