#pragma once


#include "ofMain.h"
#include <atomic>
#include "printQ.h"
#include <chrono>

/// This is a simple example of a ThreadedObject created by extending ofThread.
/// It contains data (count) that will be accessed from within and outside the
/// thread and demonstrates several of the data protection mechanisms (aka
/// mutexes).

struct JobData
{
    int taskNumber;
    std::string printerName;

};

class ListenerThreadObject : public ofThread
{

public:

    JobData jobDataStructObj;

    printQ xi;

    
    std::string printerVar; //tutaj trzeba wbiæ siê z zewn¹trz referencj¹ z nazw¹ drukarki
    //std::string printerVar = xi.exec("asd");
    void start() {
        startThread();
    }
    printQ x;
    void setup() {
        
        start();
    }

    void threadedFunction() {
        while (isThreadRunning()) {

            jobDataStructObj.printerName = printerVar;
            jobDataStructObj.taskNumber = x.printerQuee(jobDataStructObj.printerName);
            std::cout << "\n" << x.printerQuee(printerVar);
            ofSleepMillis(10000);

        }

    }
    int getQueue() {


        return jobDataStructObj.taskNumber;
    }

    
};