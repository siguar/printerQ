#include "ofApp.h"
#include "printQ.h"
#include "listenerThread.h"
//#include "deleter.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//Deleter xi;
	//xi.printername = "1";// do uzycia deletera trzeba podac nazwe drukarki
	//xi.taskDeleter();  //testowa³em czy komenda dzia³a prawid³owo ale funkcja jest wystawiona przez klasê w¹tku deleterThread.h
	
	listenerObject.setup();
	listenerObject.lock();
	listenerObject.printerVar = "1"; //przekazanie do watku nazwy drukarki ktorej kolejke chcemy nasluchiwac
	listenerObject.unlock();
	listenerObject.lock();
	//std::cout << listenerObject.jobDataStructObj.taskNumber << "++++++++";         listenerObject.jobDataStructObj.taskNumber    //odebranie ilosci taskow z watku
	listenerObject.unlock();
}

//--------------------------------------------------------------
void ofApp::update(){
	
	listenerObject.getQueue();
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
