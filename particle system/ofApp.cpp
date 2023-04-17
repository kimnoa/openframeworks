#include "ofApp.h"

//--------------------------------------------------------------
void ofApp_Kim::setup(){

}

//--------------------------------------------------------------
void ofApp_Kim::update() {

	for (int i = 0; i < particles.size(); i++) {
		particles[i].update();
	}
}
//--------------------------------------------------------------
void ofApp_Kim::draw(){
	
		ofSetColor(255); //white

		for (int i = 0; i < particles.size(); i++) {
			particles[i].draw();
		}
		
		

}

//--------------------------------------------------------------
void ofApp_Kim::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp_Kim::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp_Kim::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp_Kim::mouseDragged(int x, int y, int button){

		particle newParticle(mouseX, mouseY, hue);

		particles.push_back(newParticle); //newparticle¿¡ ´ëÇÑ º¤ÅÍ ÀÔ·Â


}

//--------------------------------------------------------------
void ofApp_Kim::mousePressed(int x, int y, int button){

		hue = ofRandom(255); //»ö ·£´ý

}

//--------------------------------------------------------------
void ofApp_Kim::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp_Kim::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp_Kim::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp_Kim::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp_Kim::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp_Kim::dragEvent(ofDragInfo dragInfo){ 

}

particle::particle(int start_x, int start_y, int hue) {
	position = glm::vec2(start_x, start_y);

	direction = glm::vec2(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0));

	size = 20;

	color.setHsb(hue, 255, 255, 200); //hue, saturation, brightness
}

particle::~particle() {
	//¼Ò¸êÀÚ
}

void particle::update() {
	position += direction;

	if (size > 1) {
		size -= 0.05;
	}
}

void particle::draw() {
	ofSetColor(color);
	ofDrawCircle(position, size);
}