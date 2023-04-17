#pragma once

#include "ofMain.h"

class particle {
public:
	float size;
	ofColor color;

	glm::vec2 force, position, direction;

	particle(int x, int y, int hue);
	~particle();

	void update();
	void draw();
};


class ofApp_Kim : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	vector<particle> particles; //particle에 대한 백터 리스트 생성
	int hue=0;


};

