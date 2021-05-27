#include "facadeoperationresult.h"

FacadeOperationResult::FacadeOperationResult()
{
    _errorMessage = " ";
    _isSuccess = true;
}

FacadeOperationResult::FacadeOperationResult(std::string errorMessage, bool isSuccess)
{
    _errorMessage = errorMessage;
    _isSuccess = isSuccess;
}

std::string FacadeOperationResult::getErrorMessage()
{
    return _errorMessage;
}

bool FacadeOperationResult::isSuccess()
{
    return _isSuccess;
}

void FacadeOperationResult::setIsSuccess(bool flag)
{
    _isSuccess = flag;
}

void FacadeOperationResult::setMessage(std::string errorMessage)
{
    _errorMessage = errorMessage;
}
