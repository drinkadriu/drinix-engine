#include "stdafx.h"
#include "Initialization.h"

void Initialize(){
	RunWorld(&TestLevel::testlevel);
	TestLevel::Initialize();
	// Initialize Created Worlds Here
}
void GlobalUpdate(){

}