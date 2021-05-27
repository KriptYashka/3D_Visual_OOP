#ifndef FACADEOPERATIONRESULT_H
#define FACADEOPERATIONRESULT_H
#include <iostream>
using std::string;

class FacadeOperationResult
{
private:
    string _errorMessage;
    bool _isSuccess;
public:
    FacadeOperationResult();
    FacadeOperationResult(string errorMessage, bool isSuccess);
    string getErrorMessage();
    bool isSuccess();
    void setIsSuccess(bool flag);
    void setMessage(string errorMessage);
};

#endif // FACADEOPERATIONRESULT_H
