#pragma once
// PrinterQueue.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <map>
#include <Windows.h>


class printQ {


public:
    std::string exec(const char* cmd) {
        char buffer[128];
        std::string result = "";
        FILE* pipe = _popen(cmd, "r");
        if (!pipe) throw std::runtime_error("popen() failed!");
        try {
            while (fgets(buffer, sizeof buffer, pipe) != NULL) {
                result += buffer;
            }
        }
        catch (...) {
            _pclose(pipe);
            throw;
        }
        _pclose(pipe);
        return result;


    }
    int printerQuee(const std::string& luuk) {
        std::map<std::string, int> counterDefaultMap;



            std::system("cls");

            std::string printerName = exec("wmic printjob get name");
            //const char* printerNameChar = printerName.c_str();
            //std::cout << printerNameChar;
            std::string delimiter = "\n";
            size_t pos = 0;
            std::vector <std::string> vectorOfPrinters;

            while ((pos = printerName.find(delimiter)) != std::string::npos) {
                std::string token = printerName.substr(0, pos);
                //   std::cout << token << std::endl;
                vectorOfPrinters.push_back(token);
                printerName.erase(0, pos + delimiter.length());
            }
            // std::cout << vectorOfPrinters[2];
            for (auto& item : vectorOfPrinters)
            {
                std::string delimiter2 = ",";
                std::string tempValue = item.substr(0, item.find(delimiter2));
                // std::cout << tempValue;

                if (counterDefaultMap.count(tempValue)) {
                    counterDefaultMap[tempValue]++;
                }
                else {
                    counterDefaultMap.insert({ tempValue, 0 });
                }
            }
            for (auto& element : counterDefaultMap) {
                std::cout << element.first << " -> " << element.second << '\n';
                if (element.second >= 4) {
                    std::cout << "!warning!\nPRINTER " << element.first << " OVERLOAD\n";
                }
            }
            
        

        /*char* ptr;
         ptr = strtok(printerNameChar, ",");
         //std::cout << exec("wmic printjob get jobid where name='1'");
         while (ptr != NULL) {
             std::cout << ptr << std::endl;
             ptr = strtok(NULL, ",");
         }
         */
            if (counterDefaultMap.count(luuk))
            {

                return counterDefaultMap[luuk]+1;
            }
            else {
                return -1;//nigdy nie bedzie ujemnej liczby tasków w queue dlatego -1 oznacza b³¹d
            }
    }
    
};