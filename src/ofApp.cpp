#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui = std::shared_ptr<ofxDatGui>(new ofxDatGui());
	gui->addHeader("Controles");
	gui->addFooter();
	auto btnClear = gui->addButton("Clear Line");
	btnClear->onButtonEvent(this, &ofApp::onButtonClear);

	auto btnSave = gui->addButton("Save Mask");
	btnSave->onButtonEvent(this, &ofApp::onButtonSave);

	auto btnExit = gui->addButton("Exit");
	btnExit->onButtonEvent(this, &ofApp::onButtonExit);

	ofBackground(ofColor::black);
}

//--------------------------------------------------------------
void ofApp::update(){
	gui->update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	gui->draw();
	shape.draw();
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
	shape.lineTo(x, y);
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

void ofApp::onButtonClear(ofxDatGuiButtonEvent event)
{
	std::cout << "button clear" << std::endl;
	shape.clear();
}

void ofApp::onButtonSave(ofxDatGuiButtonEvent event)
{
	std::cout << "button save" << std::endl;
	gui->setVisible(false);
	ofSaveScreen("mask.png");
	gui->setVisible(true);

	pixels.allocate(ofGetWidth(), ofGetHeight(), ofImageType::OF_IMAGE_GRAYSCALE);
	ofFbo fbo;

	fbo.allocate(ofGetWidth(), ofGetHeight());
	fbo.begin();
	ofBackground(ofColor::black);
	shape.draw();
	fbo.end();
	auto texture = fbo.getTexture();
	texture.readToPixels(pixels);
	ofSaveImage(pixels, "mask.png");
}

void ofApp::onButtonExit(ofxDatGuiButtonEvent event)
{
	std::cout << "Exiting. Good-bye!";
	ofExit();
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
