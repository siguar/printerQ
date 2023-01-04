#pragma once
//g³ówna klasa deletera z funkcj¹ do usuwania tasków z kolejki 
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <map>
#include <Windows.h>
#include "printQ.h"

class Deleter {
public:
	//printQ commandWriter;
	std::string printername="1";

	void taskDeleter() {
		
		//std::cout << commandWriter.exec("powershell Get-Printer -Name \"1\" |powershell Get-PrintJob |powershell Remove-PrintJob");
		system(("powershell \"Get-Printer -Name '" + printername + "' | Get-PrintJob | Remove-PrintJob\"").c_str());
	}

};