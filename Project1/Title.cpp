#include "Title.h"

Title::Title()
{
	title_len = strlen(title);
	click_len = strlen(click);


	robot = new Robot(0.f, -200.f, 0.f, 50.f);
}


Title::~Title()
{
}

void Title::Draw() {
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//원근 투영
	gluPerspective(60.f, WindowWidth / WindowHeight, 1.f, 10000.f);
	glTranslatef(0.0f, 0.0f, -WindowWidth / 2);
	glMatrixMode(GL_MODELVIEW); // 모델행렬 이거 안해서 그랬음..
	glLoadIdentity();


	glPushMatrix();
	glTranslatef(0.f, -100.f, 0.f);
	glRotatef(160.f, 0.f, 1.f, 0.f);
	robot->DrawRobot();
	glPopMatrix();

	//cout << "Draw" << endl;
	glColor4f(1.f, 0.f, 0.f, 1.f);
	glPushMatrix();
	{
		
		glRasterPos2f(-100.f, 350.f);
		
		for (int i = 0; i < title_len; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
		}
	}
	glPopMatrix();

	glPushMatrix();
	{
		glRasterPos2f(-80.f, -200.f);
		for (int i = 0; i < click_len; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, click[i]);
		}
	}
	glPopMatrix();
}
