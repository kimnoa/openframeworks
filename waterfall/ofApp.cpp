#include "ofApp.h"
#define RED (255,0,0)
#define BK (0,0,0);
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(15); // Limit the speed of our program to 15 frames per second
    
    // We still want to draw on a black background, so we need to draw
    // the background before we do anything with the brush
    ofBackground(255,255,255);
    ofSetLineWidth(4);
    
    draw_flag = 0;
    load_flag = 0;
    dot_diameter = 20.0f;
    dot_now = 0; //selected dot
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(127,23,31);  // Set the drawing color to brown
    
    // Draw shapes for ceiling and floor
    ofDrawRectangle(0, 0, 1024, 40); // Top left corner at (50, 50), 100 wide x 100 high
    ofDrawRectangle(0, 728, 1024, 40); // Top left corner at (50, 50), 100 wide x 100 high
    ofSetLineWidth(5);
    
    
    ofSetLineWidth(5);
    if( draw_flag ) //key 'd' pressed
    {     
        
        /* COMSIL1-TODO 3 : Draw the line segment and dot in which water starts to flow in the screen.
         Note that after drawing line segment and dot, you have to make selected water start dot colored in red.
         */

        for (int i = 0; i < num_of_line; i++)
            ofDrawLine(L[i].x1, L[i].y1, L[i].x2, L[i].y2); //Line draw

        for (int j = 0; j < num_of_dot; j++)
        {
            if (j == dot_now) //selected dot
                ofSetColor RED;
            else
                ofSetColor BK;

            ofDrawCircle(D[j].x1, D[j].y1, dot_diameter / 2); //dot draw
        }
        
        
        // 2nd week portion.
        ofSetLineWidth(2);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'v') {
        // HACK: only needed on windows, when using ofSetAutoBackground(false)
        glReadBuffer(GL_FRONT);
        ofSaveScreen("savedScreenshot_"+ofGetTimestampString()+".png");
    }
    if (key == 'q'){
        // Reset flags
        draw_flag = 0;
        
        // Free the dynamically allocated memory exits.
        free(L);
        free(D);
        L = NULL;
        D = NULL;

        if(L == NULL)
            cout << "Memory for line segment has been freed." << endl;
        if(D == NULL)
            cout << "Memory for dot has been freed." << endl;
        
        _Exit(0);
    }
    if (key == 'd'){
        if( !load_flag) return; //load flag = 1 (load file completely)
        
        /* COMSIL1-TODO 2: This is draw control part.
        You should draw only after when the key 'd' has been pressed.
        */

        draw_flag = 1; //now go to draw()


    }
    if (key == 's'){
        // 2nd week portion.
    }
    if (key == 'e'){
        // 2nd week portion.
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if( key == 'l'){
        // Open the Open File Dialog
        ofFileDialogResult openFileResult= ofSystemLoadDialog("Select a only txt for Waterfall");
        
        // Check whether the user opened a file
        if( openFileResult.bSuccess){
            ofLogVerbose("User selected a file");
            
            // We have a file, so let's check it and process it
            processOpenFileSelection(openFileResult);
            load_flag = 1;
        }
    }
    
    /* COMSIL1-TODO 4: This is selection dot control part.
     You can select dot in which water starts to flow by left, right direction key (<- , ->).
     */
    
    if (key == OF_KEY_RIGHT){
        if ((++dot_now) == num_of_dot)
            dot_now = 0;

        cout << "Selcted Dot Coordinate is ("<< D[dot_now].x1 << ", "<< D[dot_now].y1 << ")" << endl;
    }
    if (key == OF_KEY_LEFT){
        if (!dot_now)
            dot_now = num_of_dot;
        dot_now--;
        
        cout << "Selcted Dot Coordinate is (" << D[dot_now].x1 << ", " << D[dot_now].y1 << ")" << endl;
    }
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

void ofApp::processOpenFileSelection(ofFileDialogResult openFileResult) { 
    //Path to the comma delimited file
    //string fileName = "input.txt";
    
    string fileName = openFileResult.getName();
    ofFile file(fileName);
    
    if( !file.exists()) cout << "Target file does not exists." << endl;
    else cout << "We found the target file." << endl;
    
    ofBuffer buffer(file);
    
    /* This variable is for indicating which type of input is being received.
     IF input_type == 0, then work of getting line input is in progress.
     IF input_type == 1, then work of getting dot input is in progress.
     */

    int input_type = 0; //line input
    int index = 0; //index of array    
    
    /* COMSIL1-TODO 1 : Below code is for getting the number of line and dot, getting coordinates.
     You must maintain those information. But, currently below code is not complete.
     Also, note that all of coordinate should not be out of screen size.
     However, all of coordinate do not always turn out to be the case.
     So, You have to develop some error handling code that can detect whether coordinate is out of screen size.
    */
    
    
    // Read file line by line
    for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) 
    {
        string line = *it;
        
        
        // Split line into strings
        vector<string> words = ofSplitString(line, " ");
        
        if( words.size() == 1){ //1 number = number of lines or dots
            if( input_type == 0){ // Input for the number of lines.
                num_of_line = atoi(words[0].c_str());
                cout << "The number of line is: " << num_of_line << endl;


                if (!L)
                    L = new Line[num_of_line]; //dynamically allocate memory
            }
            else{ // Input for the number of dots.
                num_of_dot = atoi(words[0].c_str());
                cout << "The number of dot is: " << num_of_dot << endl;


                if (!D)
                    D = new Dot[num_of_dot]; //dynamically allocate memory.
            }
        }

        else if (words.size() >= 2){
            if( input_type == 0){ // Input for actual information of lines
                L[index].x1 = atoi(words[0].c_str());
                L[index].y1 = atoi(words[1].c_str());
                L[index].x2 = atoi(words[2].c_str());
                L[index].y2 = atoi(words[3].c_str());

                //error handling code
                if (L[index].x1 < 0 || L[index].x1 > ofGetWidth()) {
                    cout << L[index].x1 << " is out of range\n";
                }

                if (L[index].x2 < 0 || L[index].x2 > ofGetWidth()) {
                    cout << L[index].x2 << " is out of range\n";
                }

                if (L[index].y1 < 0 || L[index].y1 > ofGetHeight()) {
                    cout << L[index].y1 << " is out of range\n";
                }

                if (L[index].y2 < 0 || L[index].y2 > ofGetHeight()) {
                    cout << L[index].y2 << " is out of range\n";
                }


                if ((++index) >= num_of_line) 
                {
                    input_type = 1; //now input of dots
                    index = 0; //dot index = 0
                }

            }
            else // Input for actual information of dots.
            { 
                D[index].x1 = atoi(words[0].c_str());
                D[index].y1 = atoi(words[1].c_str());

                //error handling code

                if (D[index].x1 < 0 || D[index].x1 > ofGetWidth()) {
                    cout << D[index].x1 << " is out of range\n";
                }

                if (D[index].y1 < 0 || D[index].y1 > ofGetHeight()) {
                    cout << D[index].y1 << " is out of range\n";
                }

               // ++index;

                if ((++index) == num_of_dot)
                {
                    input_type = 0; //reset
                }

            }
        } // End of else if.

 


    } // End of for-loop (Read file line by line).

    //initializeWaterLines();
}

void ofApp::initializeWaterLines() {
    ;
}


