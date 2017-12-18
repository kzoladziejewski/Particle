#include "ofApp.h"
#include "of3dPrimitives.h"
//--------------------------------------------------------------
kula kulki[1500000];
szescian hex1[10000];

int kuleczki, powierzchnia;
bool start = false;
bool rozprysk = false;
bool powrot = false;
float cos_ty;
int ile_razy_mi_poszlo = 0;

void ofApp::setup() {
	ofSetFrameRate(60);
	//ofEnableDataPath();
	//ofSetVerticalSync(true);
	cam.setAutoDistance(true);
	//cam.setDistance(akcja);
	kuleczki = 0;
	powierzchnia = 0;
	ofBackground(0, 255, 0, 50);

	kulka(0);
}

//--------------------------------------------------------------
void ofApp::update() {

	int i,k, j,p, w;

	//SPRAWDZA MOZLIWOSC CZY JEST UDERZENIE
	if (start == true) {
		for (int uderz = 0; uderz < kuleczki; uderz++)
		{

			//NADAJE UDERZENIE
			if (kulki[uderz].x >= 350)
			{
				//start = false;
				kulki[uderz].vx *= -1;
				kulki[uderz].vy = ofRandom(-10.0, 10.0);
				kulki[uderz].vz = ofRandom(-10.0, 10.0);
				kulki[uderz].uderzenie = true;
			}
			//ZMIANA KOLOROW, ODPALA ZMNIEJSZANIE PROMIENIA I LIFETIME'A
			if (kulki[uderz].uderzenie == true)
			{
				kulki[uderz].promien -= ofRandom(0.0f, 1.0f);

				kulki[uderz].lifetime -= ofRandom(0.0f, 1.0f);
				kulki[uderz].r = rand() % 255;
				kulki[uderz].g = rand() % 255;
				kulki[uderz].b = rand() % 255;
				if (kulki[uderz].lifetime < 0)
				{ //NISZCZY KULKE
					kulki[uderz].exist = false;
				}
			}
		}
	}

	//ROZPRASZA KULE
	if (rozprysk == true)
	{
		
		cos_ty = 0.1;
		for (int iterator = 0; iterator < kuleczki; iterator++) {
			//LEWA DOLNA CWIARTKA TYLNIA
			if ((kulki[iterator].x < 0) && (kulki[iterator].y < 0) && (kulki[iterator].z < 0))
			{
				//cout << "find it";
				kulki[iterator].vx =  1.01+cos_ty;
				kulki[iterator].vy =  1.01+cos_ty;
				kulki[iterator].vz =  1.01+cos_ty;
				
			}
			//PRAWA GORNA CWIARTKA PRZEDNIA
			if ((kulki[iterator].x >= 0) && (kulki[iterator].y >= 0) && (kulki[iterator].z >= 0))
			{
			//	cout << "find it";
				kulki[iterator].vx = 1.01+cos_ty;
				kulki[iterator].vy = 1.01+cos_ty;
				kulki[iterator].vz = 1.01+cos_ty;
			
			} 
			//LEWA GÓRNA CWIARTKA PRZEDNIA
			if ((kulki[iterator].x < 0) && (kulki[iterator].y > 0) && (kulki[iterator].z > 0))
			{
			//	cout << "find it";
				kulki[iterator].vx = 1.01+cos_ty;
				kulki[iterator].vy = 1.01+cos_ty;
				kulki[iterator].vz = 1.01+cos_ty;
			}//PRAWA DOLNA CWIARKA PRZEDNIA
			if ((kulki[iterator].x > 0) && (kulki[iterator].y < 0) && (kulki[iterator].z > 0))
			{
			//	cout << "find it";
				kulki[iterator].vx = 1.01+cos_ty;
				kulki[iterator].vy = 1.01+cos_ty;
				kulki[iterator].vz = 1.01+cos_ty;
			} //PRAWA GORNA CWIARTKA TYL
			if ((kulki[iterator].x > 0) && (kulki[iterator].y > 0) && (kulki[iterator].z < 0))
			{
			//	cout << "find it";
				kulki[iterator].vx = 1.01+cos_ty;
				kulki[iterator].vy = 1.01+cos_ty;
				kulki[iterator].vz = 1.01+cos_ty;
			}//PRAWA DOLNA CWIARTKA TYL
			if ((kulki[iterator].x >= 0) && (kulki[iterator].y <= 0) && (kulki[iterator].z <= 0))
			{
			//	cout << "find it";
				kulki[iterator].vx = 1.01+cos_ty;
				kulki[iterator].vy = 1.01+cos_ty;
				kulki[iterator].vz = 1.01+cos_ty;
			}//LEWA GORNA WIARTKA TYL
			if ((kulki[iterator].x <= 0) && (kulki[iterator].y >= 0) && (kulki[iterator].z <= 0))
			{
			//	cout << "find it";
				kulki[iterator].vx = 1.01+cos_ty;
				kulki[iterator].vy = 1.01+cos_ty;
				kulki[iterator].vz = 1.01+cos_ty;
		}//LEWA DOLNA CWIARTKA TYL
		if ((kulki[iterator].x <= 0) && (kulki[iterator].y <= 0) && (kulki[iterator].z >= 0))
		{
		//	cout << "find it";
			kulki[iterator].vx = 1.01+cos_ty;
				kulki[iterator].vy = 1.01+cos_ty;
				kulki[iterator].vz = 1.01+cos_ty;
		}
	}
		
					ile_razy_mi_poszlo++;
			
	}
//	SPRASZA KULE
	if (powrot == true)
	{
		int kalka = 0;
		for (int iterator1 = 0; iterator1 <= kuleczki; iterator1++)
		{
			if ((kulki[iterator1].x <= 0) && (kulki[iterator1].y <= 0) && (kulki[iterator1].z <= 0))
			{
				//if (pow(kulki[iterator1].x, 2) + pow(kulki[iterator1].y, 2) + pow(kulki[iterator1].z, 2) > pow(promien, 2)) {
				//	cout << pow(kulki[iterator1].x, 2) + pow(kulki[iterator1].y, 2) + pow(kulki[iterator1].z, 2)<< " " << promien << endl;
					kulki[iterator1].vx = (1/(1 - cos_ty));
					kulki[iterator1].vy = (1 / (1 - cos_ty));
					kulki[iterator1].vz = (1 / (1 - cos_ty));
				//}
			}
			if ((kulki[iterator1].x >= 0) && (kulki[iterator1].y >= 0) && (kulki[iterator1].z >= 0))
			{
				kulki[iterator1].vx = 1 / (1 - cos_ty);
				kulki[iterator1].vy = 1 / (1 - cos_ty);
				kulki[iterator1].vz = 1 / (1 - cos_ty);

			}
			if ((kulki[iterator1].x <= 0) && (kulki[iterator1].y >= 0) && (kulki[iterator1].z >= 0))
			{

				kulki[iterator1].vx = 1 / (1 - cos_ty);
				kulki[iterator1].vy = 1 / (1 - cos_ty);
				kulki[iterator1].vz = 1 / (1 - cos_ty);
			}
			if ((kulki[iterator1].x >= 0) && (kulki[iterator1].y <= 0) && (kulki[iterator1].z >= 0))
			{
				kulki[iterator1].vx = 1 / (1 - cos_ty);
				kulki[iterator1].vy = 1 / (1 - cos_ty);
				kulki[iterator1].vz = 1 / (1 - cos_ty);
			}
			if ((kulki[iterator1].x >= 0) && (kulki[iterator1].y >= 0) && (kulki[iterator1].z <= 0))
			{

				kulki[iterator1].vx = 1 / (1 - cos_ty);
				kulki[iterator1].vy = 1 / (1 - cos_ty);
				kulki[iterator1].vz = 1 / (1 - cos_ty);
			}
			if ((kulki[iterator1].x >= 0) && (kulki[iterator1].y <= 0) && (kulki[iterator1].z <= 0))
			{

				kulki[iterator1].vx = 1 / (1 - cos_ty);
				kulki[iterator1].vy= 1 / (1 - cos_ty);
				kulki[iterator1].vz = 1 / (1 - cos_ty);
			}
			if ((kulki[iterator1].x <= 0) && (kulki[iterator1].y >= 0) && (kulki[iterator1].z <= 0))
			{
				kulki[iterator1].vx = 1 / (1 - cos_ty);
				kulki[iterator1].vy = 1 / (1 - cos_ty);
				kulki[iterator1].vz = 1 / (1 - cos_ty);
			}
			if ((kulki[iterator1].x <= 0) && (kulki[iterator1].y <= 0) && (kulki[iterator1].z >= 0))
			{

				kulki[iterator1].vx = 1 / (1 - cos_ty);
				kulki[iterator1].vy = 1 / (1 - cos_ty);
				kulki[iterator1].vz = 1 / (1 - cos_ty);
			}
	
		}
		//cout << ile_razy_mi_poszlo;
		ile_razy_mi_poszlo--;
		if (ile_razy_mi_poszlo == 0)
		{
			powrot = false;
		}
	}
	//NADANIE RUCH CZASTECZKE W ZALEZNOSCI CZY ROZPRYSK CZY POWROT CZY TOCZENIE SIE

	for (p = 0; p < kuleczki; p++) {
			if (start == true)
		{	//PORUSZA KULE O 1 W PRAWO

		kulki[p].x += kulki[p].vx;

		kulki[p].y += kulki[p].vy;
		kulki[p].z += kulki[p].vz;
		}
		if (rozprysk == true)
		{
			//cout << kulki[p].x * kulki[p].vx << " " << kulki[p].x << " " << kulki[p].vx << endl;
			kulki[p].x = kulki[p].x * kulki[p].vx;

			kulki[p].y = kulki[p].y * kulki[p].vy;
			kulki[p].z = kulki[p].z * kulki[p].vz;
		}
		if (powrot == true)
		{
			kulki[p].x = kulki[p].x / kulki[p].vx;

			kulki[p].y = kulki[p].y / kulki[p].vy;
			kulki[p].z = kulki[p].z / kulki[p].vz;
		}

	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	
	cam.begin();
	int i, j, k, l;
	ofSetColor(0, 255, 0);
	ofFill();
	int ilosc_sfer = 0;

	for (i = 0; i <= kuleczki; i++)
	{
		if (kulki[i].exist == true) {
			ofSetColor(kulki[i].r, kulki[i].g, kulki[i].b);
			ofFill();
			ofDrawSphere(kulki[i].x, kulki[i].y, kulki[i].z, kulki[i].promien);
			
		}
	}
	

	//ofDrawSphere(kulki[0].x, kulki[0].y, kulki[0].z, kulki[0].promien);
	//ofDrawBox(20, 20, 20, 20, 20, 20);
//ofSetColor(200, 0, 0);
	//ofFill();
//	ofDrawBox(350,0 ,0, 20, 1000,1000);
	if (start == true)
	{
		ofSetColor(200, 0, 0);
		ofFill();
		ofDrawPlane(425, 0, 100, 2000);
	}
	//ofDrawSphere(kulki[2].x, kulki[2].y, kulki[2].z, kulki[2].promien);
	ofSetColor(255, 255, 255);
	ofFill();
	//ofDrawSphere(0, 0, 0, 10);

	//ofDrawBitmapString("Instrukcja sterowania: \n Start kuli: z \n Zatrzymanie kuli: x \n Reset: r \n Przywrócenie do zycia kulek: c \n Zwiekszenie ilosci czasteczek: w \n  Zmniejszenie ilosci czasteczek: s \n Rozprysk: p \n Powrót rozprysku: o \n STOP WSZYSTKIEGO!: l \n Reset kamery: 2xLPM", -500, 350);
	cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key)
	{
	case 'z':
		start = true;

		/*	for (int j = 0; j < kuleczki; j++)
			{
				kulki[j].vx = 5;
			}*/
		break;
	case 'x':
		start = false;
		break;

	case  'r':
		setup();
		powrot = false;
		rozprysk = false;
		start = false;
		break;
	case 'c':
		for (int i = 0; i < kuleczki; i++)
		{
			kulki[i].lifetime = 10;
			kulki[i].exist = true;
		}
		break;
	case 'w':
		ilosc_czasteczek++;
		promien++;
		break;
	case 's':
		ilosc_czasteczek--;
		promien--;
		break;
	case 'p':

		powrot = false;
		//	niszcze();
		rozprysk = true;
		break;
	case 'o':
		rozprysk = false;
		//	niszcze();
		powrot = true;
		break;

	case 'l':
		rozprysk = false;
		powrot = false;
		start = false;
		//	niszcze();
		break;

	case 'a':
	
		break;
	}

}

void ofApp::niszcze()
{
	for (int w = 0; w < kuleczki; w++)
	{
		kulki[w].vx = 0;
		kulki[w].vy = 0;
		kulki[w].vz = 0;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::kulka(int przekazane)
{
	x1 = -ilosc_czasteczek;
	float y1 = -ilosc_czasteczek;
	float z1 = -ilosc_czasteczek;


	int i, j, k, l;
	for (l = 0; l <= promien; l++)
	{
		x1 = -ilosc_czasteczek;
		for (i = 0; x1 <= ilosc_czasteczek; i++)//po x
		{

			y1 = -ilosc_czasteczek;
			for (j = 0; y1 <= ilosc_czasteczek; j++)
			{

				z1 = -ilosc_czasteczek;
				for (k = 0; z1 <= ilosc_czasteczek; k++)
				{
					if (pow(x1, 2) + pow(y1, 2) + pow(z1, 2) < pow(l, 2))

					{

						kulki[kuleczki].promien = 10;
						kulki[kuleczki].x = x1 * 10;
						kulki[kuleczki].y = y1 * 10;
						kulki[kuleczki].z = z1 * 10;
						//	cout << "Jedna kuleczka zajmuje pozycje: X-" << kulki[kuleczki].x << " Y- " << kulki[kuleczki].y << " Z - " << kulki[kuleczki].z << endl;
						kulki[kuleczki].r = 0;
						kulki[kuleczki].g = 0;
						kulki[kuleczki].b = 255;
						kulki[kuleczki].vx = 5;
						kulki[kuleczki].vy = 0;
						kulki[kuleczki].vz = 0;
						kulki[kuleczki].exist = true;
						kulki[kuleczki].lifetime = 10;
						kulki[kuleczki].uderzenie = false;
						kuleczki++;
						if (l == promien)
						{
							hex1[powierzchnia].x = x1 * 10;
							hex1[powierzchnia].y = y1 * 10;
							hex1[powierzchnia].z = z1 * 10;
							powierzchnia++;
						}


						/*	cout << "powstalo nam tylko tyle kulek w kuli" << kuleczki << endl;
						cout << i << j << k << endl;
						cout << x1 << y1 << z1 << endl;;*/
					}
					z1 += 1;
					//	cout << x1 << " " << y1 << " " << z1 << " " << endl;
				}
				y1 += 1;
			}
			x1 += 1;
		}

	}cout << kuleczki << " " << powierzchnia << endl;
}