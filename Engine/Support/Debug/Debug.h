#pragma once
#define Print(str) cout << str << endl
#define Get(func, var, val) cin >> func >> var >> val

#define Add(var, val) Funcs::Adds(#var, (val))
#define Sub(var, val) Funcs::Subs(#var, (val))
#define Mul(var, val) Funcs::Muls(#var, (val))
#define Div(var, val) Funcs::Divs(#var, (val))

namespace Funcs{
	void Adds(float num1, float num2){
		num1 += num2;
	}
	void Subs(float num1, float num2){
		num1 -= num2;
	}	
	void Muls(float num1, float num2){
		num1 *= num2;
	}	
	void Divs(float num1, float num2){
		num1 /= num2;
	}
}

#include "Component.h"
class Debug :
	public Component
{
private:
	string Input;
	string Function;
	string Var1;
	string Var2;

	bool GotInput;
public:
	Debug() : Component("Debug") {};
	virtual void Start(){
		Print("Enter Any Commands: ");
	};
	virtual void Update()
	{
		if (Get(Function, Var1, Var2))
			GotInput = true;
		else
			GotInput = false;
		if (GotInput)
		{
			//if (Function == "add")
				//Add(Var1, Var2);
		}
	}
	~Debug();
};

