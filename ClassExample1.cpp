#include "gmock/gmock.h"

using namespace std;

class Class1 {
	public:
		virtual bool TwoStringFunction(string param1, string param2){
			if (param1.compare(param2) != 0){
				return false;
			}
			return true;
		}
		bool CallTwoStringFunctionTwice(){
			Class1::TwoStringFunction("a", "a");
			Class1::TwoStringFunction("a", "a");
			return true;
		}
		virtual int IntParamFunction(int param1){
			return param1;
		}
		void BoolParamFunction(bool param1, bool param2, bool param3){}
};

class MockClass1 : public Class1 {
	public:
		MOCK_METHOD(bool, TwoStringFunction, (string, string));
		MOCK_METHOD(bool, CallTwoStringFunctionTwice, ());
		MOCK_METHOD(int, IntParamFunction, (int));
		MOCK_METHOD(void, BoolParamFunction, (bool, bool, bool));
};