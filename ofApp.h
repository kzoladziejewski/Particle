#pragma once

#include "ofMain.h"
#include "ofTrueTypeFont.h"

struct kula
{
	float x, y, z, vx, vy, vz, promien, r,g,b, lifetime;
	bool exist, uderzenie;

};

struct szescian
{
	float x, y, z, promien;
};


class ofApp : public ofBaseApp {




public:
	void setup();
	void update();
	void draw();
	void kulka(int przekazane);
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void niszcze();
	void gotMessage(ofMessage msg);
	ofEasyCam cam;
	float x1;
	ofSpherePrimitive sphere;
	int a;
	int promien = 11;
	int ilosc_czasteczek = 11;
	ofTrueTypeFont font;


};
