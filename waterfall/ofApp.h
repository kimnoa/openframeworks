#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

//Line, Dot coordinates variables

protected:
	class Line {
	public:
		int x1;
		int x2;
		int y1;
		int y2;
	};

	class Dot {
	public:
		int x1;
		int y1;
	};



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
    
    /* WaterFall-related member variables Regions */
    
    // flag variables
    int draw_flag;
    int load_flag;
    
    // Line segment and dot related variables
    int num_of_line, num_of_dot;
    float dot_diameter;
	int dot_now;
    
    /* WaterFall-related member functions */
    
    void processOpenFileSelection(ofFileDialogResult openFileResult);
    void initializeWaterLines(); // 2nd week portion.

	 //structure array
	Line* L = NULL;
	Dot* D = NULL;
		
};




